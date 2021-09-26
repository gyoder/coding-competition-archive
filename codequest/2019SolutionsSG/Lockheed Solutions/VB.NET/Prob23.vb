Imports System.Collections.Generic
Imports System.Tuple

Module Evacuate

    Public Const STARTING_SYMBOL = "o"c
    Public Const EXIT_SYMBOL = "X"c
    Public Const EMPTY_SYMBOL = " "c
    Public Const TRIED_SYMBOL = ","c
    Public Const WALL = "#"c
    Public Const PATH_SYMBOL = "."c
    Public Const DEBUG As Boolean = False


    Sub Main()
        'stand test case stuff
        Dim numTestCasesStr As String
        Dim numTestCases As Integer
        Dim testMap As Map
        numTestCasesStr = Console.ReadLine()
        numTestCases = UInteger.Parse(numTestCasesStr)

        While numTestCases > 0
            testMap = Map.ReadMap()
            testMap.Print()
            testMap.Solve(testMap.StartingLocation)
            testMap.PrintBestSoltion()

            numTestCases = numTestCases - 1
        End While
    End Sub


    Public Class Map
        Public Width As Integer
        Public Height As Integer
        Public StartingLocation As Tuple(Of Integer, Integer)
        Dim OriginalMap As Char(,)
        Dim Map As Char(,)
        Dim Steps As List(Of Tuple(Of Integer, Integer)) = New List(Of Tuple(Of Integer, Integer))
        Dim currentBestSolution As Solution = Nothing
        Dim Solutions As List(Of Solution) = New List(Of Solution)

        Public Shared Function ReadMap() As Map
            Dim parts As String()
            Dim inWidth, inHeight As Integer
            parts = Console.ReadLine().Split(" ")
            Dim inMapText(,) As Char
            Dim tempRowArray() As Char
            Dim row As String
            Dim inStartingLoc As Tuple(Of Integer, Integer) = Nothing
            inWidth = Integer.Parse(parts(0))
            inHeight = Integer.Parse(parts(1))
            inMapText = New Char(inHeight, inWidth) {}

            For i As Integer = 0 To inHeight - 1
                row = Console.ReadLine()
                If row.Contains("o") Then
                    inStartingLoc = Tuple.Create(i, row.IndexOf("o"))
                End If

                tempRowArray = row.ToCharArray()
                For j As Integer = 0 To tempRowArray.Length - 1
                    inMapText(i, j) = tempRowArray(j)
                Next
            Next

            If IsNothing(inStartingLoc) Then
                Throw New Exception("No starting location")
            End If

            Return New Map(inWidth, inHeight, inMapText, inStartingLoc)

        End Function


        Public Sub New(inWidth As Integer, inHeight As Integer, inMap As Char(,), inStartingLocation As Tuple(Of Integer, Integer))
            Me.Width = inWidth
            Me.Height = inHeight
            Me.Map = inMap
            Me.OriginalMap = New Char(inHeight, inWidth) {}
            Array.Copy(Me.Map, Me.OriginalMap, Me.Map.Length)
            Me.StartingLocation = inStartingLocation
        End Sub

        Public Sub Print()
            If DEBUG Then
                Console.WriteLine($"Starting Location {StartingLocation.Item1}, {StartingLocation.Item2}")
                For i As Integer = 0 To Map.GetLength(0) - 1
                    For j As Integer = 0 To Map.GetLength(1) - 1
                        Console.Write(Map(i, j))
                    Next
                    Console.WriteLine("")
                Next
            End If
        End Sub

        Public Function Solve(Optional location As Tuple(Of Integer, Integer) = Nothing) As Boolean
            Dim nextLocation, templocation As Tuple(Of Integer, Integer)
            Dim solved As Boolean = False

            Me.Print()
			
			nextLocation = Nothing

            'if theres another location 
            '   Try To solve from there
            '   Add point to steps to completion
            For i As Integer = Direction.Up To Direction.Right
                If TryGetNextLocation(location, i, nextLocation) Then

                    If Not Me.GetValueAtLocation(nextLocation) = EXIT_SYMBOL Then
                        Me.Map(nextLocation.Item1, nextLocation.Item2) = TRIED_SYMBOL
                    End If

                    'if this step is an exit save the solution
                    If Me.GetValueAtLocation(nextLocation) = EXIT_SYMBOL Then
                        solved = True
                        AddSolution(New Solution(Steps))
                    Else
                        Steps.Add(nextLocation)
                        'If it's not solved remove this step
                        Solve(nextLocation)
                        templocation = Steps(Steps.Count - 1)
                        Me.Map(templocation.Item1, templocation.Item2) = EMPTY_SYMBOL
                        Steps.RemoveAt(Steps.Count - 1)
                    End If

                End If
            Next

            If DEBUG Then
                'Console.WriteLine($"Done with location: {location.Item1}, {location.Item2}")
            End If

            Return solved
            'otherwise return and mark this spot as tried
        End Function

        Private Sub AddSolution(solution As Solution)
            Dim newSolution As Solution = New Solution(Steps)
            Solutions.Add(newSolution)

            If IsNothing(currentBestSolution) Then
                currentBestSolution = newSolution
            ElseIf newSolution.IsBetterThan(currentBestSolution) Then
                currentBestSolution = newSolution
            End If
        End Sub

        Public Sub PrintBestSoltion()
            Dim currentbest As Solution

            currentbest = Solutions(0)
            If DEBUG Then
                PrintSolution(currentbest)
            End If

            For i As Integer = 1 To Solutions.Count - 1
                If Solutions(i).IsBetterThan(currentbest) Then
                    currentbest = Solutions(i)
                End If

                If DEBUG Then
                    PrintSolution(Solutions(i))
                End If
            Next

            PrintSolution(currentbest)
        End Sub

        Private Sub PrintSolution(currentbest As Solution)
            Dim tempMap As Char(,)
            tempMap = New Char(Height, Width) {}
            Array.Copy(Me.OriginalMap, tempMap, Me.Map.Length)

            For Each i As Tuple(Of Integer, Integer) In currentbest.Steps
                tempMap(i.Item1, i.Item2) = PATH_SYMBOL
            Next

            '2 since last is an X
            For i As Integer = 0 To currentbest.Length - 1
                If Not tempMap(currentbest.Steps(i).Item1, currentbest.Steps(i).Item2) = EXIT_SYMBOL Then
                    tempMap(currentbest.Steps(i).Item1, currentbest.Steps(i).Item2) = PATH_SYMBOL
                End If
            Next

            For i As Integer = 0 To tempMap.GetLength(0) - 2
                For j As Integer = 0 To tempMap.GetLength(1) - 1
                    If Not tempMap(i, j) = vbNullChar Then
                        Console.Write(tempMap(i, j))
                    End If
                Next
                Console.WriteLine("")
            Next
        End Sub

        Public Function GetValueAtLocation(location As Tuple(Of Integer, Integer)) As Char
            Return Me.Map(location.Item1, location.Item2)
        End Function

        Public Function TryGetNextLocation(inLocation As Tuple(Of Integer, Integer), direction As Direction, ByRef outLocation As Tuple(Of Integer, Integer)) As Boolean
            Dim x, y As Integer
            Dim success As Boolean = False
			outLocation = Tuple.Create(inLocation.Item1, inLocation.Item2)

            y = inLocation.Item1
            x = inLocation.Item2

            If IsNothing(currentBestSolution) OrElse (Steps.Count < currentBestSolution.Length) Then
                If direction = Direction.Up Then
                    outLocation = Tuple.Create(y - 1, x)
                    success = IsLocationAvailable(y - 1, x)
                ElseIf direction = Direction.Left Then
                    outLocation = Tuple.Create(y, x - 1)
                    success = IsLocationAvailable(y, x - 1)
                ElseIf direction = Direction.Down Then
                    outLocation = Tuple.Create(y + 1, x)
                    success = IsLocationAvailable(y + 1, x)
                ElseIf direction = Direction.Right Then
                    outLocation = Tuple.Create(y, x + 1)
                    success = IsLocationAvailable(y, x + 1)
                End If
            End If
            'If IsLocationAvailable(x, y - 1) Then
            '    outLocation = (x, y - 1)
            '    success = True
            'ElseIf IsLocationAvailable(x - 1, y) Then
            '    outLocation = (x - 1, y)
            '    success = True
            'ElseIf IsLocationAvailable(x + 1, y) Then
            '    outLocation = (x + 1, y)
            '    success = True
            'ElseIf IsLocationAvailable(x, y + 1) Then
            '    outLocation = (x, y + 1)
            '    success = True
            'End If

            Return success
        End Function

        Private Function IsLocationAvailable(y As Integer, x As Integer) As Boolean
            Dim spot As Char

            'Check out of bounds
            If x < 0 Or y < 0 Or x > Width - 1 Or y > Height - 1 Then
                Return False
            End If

            spot = Me.Map(y, x)
            If spot = EMPTY_SYMBOL Or spot = EXIT_SYMBOL Then
                Return True
            Else
                Return False
            End If

        End Function
    End Class

    Public Class Solution
        Public Steps As List(Of Tuple(Of Integer, Integer)) = New List(Of Tuple(Of Integer, Integer))
        Public Length As Integer

        Public Sub New(inSteps As List(Of Tuple(Of Integer, Integer)))
            For Each s As Tuple(Of Integer, Integer) In inSteps
                Steps.Add(s)
            Next
            Length = Steps.Count
        End Sub

        Public Function IsBetterThan(solution As Solution) As Boolean
            If Me.Length < solution.Length Then
                Return True
            ElseIf Me.Length = solution.Length Then
                Dim meIndex, themIndex As Integer
                meIndex = Steps(Steps.Count - 1).Item1 + Steps(Steps.Count - 1).Item2
                themIndex = solution.Steps(solution.Steps.Count - 1).Item1 + solution.Steps(solution.Steps.Count - 1).Item2

                If meIndex < themIndex Then
                    Return True
                Else
                    Return False
                End If
            Else
                Return False
            End If
        End Function

    End Class

    Enum Direction
        Up = 0
        Left = 1
        Down = 2
        Right = 3
    End Enum
End Module
