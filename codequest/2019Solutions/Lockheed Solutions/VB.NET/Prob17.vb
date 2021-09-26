Option Explicit On
Imports System.Text

Module ConwayGameOfLife
    Public Const WIDTH As Integer = 10
    Public Const HEIGHT As Integer = 10



    ' 10:48 PM
    ' 11:15 PM
    ' 27 Min
    Sub Main()
        Dim numOfCases As Integer = Integer.Parse(Console.ReadLine())

        For testCase As Integer = 0 To (numOfCases - 1)
            Dim gridOfLife As New List(Of String)

            Dim numOfGenerations As Integer = Integer.Parse(Console.ReadLine())
            For i As Integer = 0 To 9
                gridOfLife.Add(Console.ReadLine())
            Next

            For i As Integer = 0 To numOfGenerations - 1
                evolve(gridOfLife)
            Next
            printGrid(gridOfLife)
        Next
    End Sub

    Private Sub printGrid(gridOfLife As List(Of String))
        For Each line As String In gridOfLife
            Console.WriteLine(line)
        Next
    End Sub

    Private Sub evolve(ByRef gridOfLife As List(Of String))
        Dim nextGeneration As New List(Of String)
        For row As Integer = 0 To HEIGHT - 1
            Dim nextGenerationRow As New StringBuilder()
            Dim currentRow As String = gridOfLife(row)
            Dim previousRow As String = If(row > 0, gridOfLife(row - 1), String.Empty)
            Dim nextRow As String = If(row < HEIGHT - 1, gridOfLife(row + 1), String.Empty)

            For col As Integer = 0 To WIDTH - 1
                Dim numOfAdjacent As Integer = 0
                Dim isAlive As Boolean = isCellAlive(currentRow.Chars(col))

                Dim isAliveNextGeneration As Boolean = False

                ' Check Previous Row
                If (previousRow <> String.Empty) Then
                    If (isCellAlive(previousRow.Chars(col))) Then
                        numOfAdjacent += 1
                    End If

                    If col > 0 AndAlso isCellAlive(previousRow.Chars(col - 1)) Then
                        numOfAdjacent += 1
                    End If

                    If col < WIDTH - 1 AndAlso isCellAlive(previousRow.Chars(col + 1)) Then
                        numOfAdjacent += 1
                    End If
                End If

                'Check Left
                If col > 0 AndAlso isCellAlive(currentRow.Chars(col - 1)) Then
                    numOfAdjacent += 1
                End If

                'Check Right
                If col < WIDTH - 1 AndAlso isCellAlive(currentRow.Chars(col + 1)) Then
                    numOfAdjacent += 1
                End If

                'Check Next
                If (nextRow <> String.Empty) Then
                    If (isCellAlive(nextRow.Chars(col))) Then
                        numOfAdjacent += 1
                    End If

                    If col > 0 AndAlso isCellAlive(nextRow.Chars(col - 1)) Then
                        numOfAdjacent += 1
                    End If

                    If col < WIDTH - 1 AndAlso isCellAlive(nextRow.Chars(col + 1)) Then
                        numOfAdjacent += 1
                    End If
                End If

                If isAlive AndAlso numOfAdjacent <= 1 Then
                    'Die
                    isAliveNextGeneration = False
                ElseIf isAlive AndAlso (numOfAdjacent = 2 Or numOfAdjacent = 3) Then
                    'Live
                    isAliveNextGeneration = True
                ElseIf isAlive AndAlso numOfAdjacent >= 4 Then
                    'Die
                    isAliveNextGeneration = False
                ElseIf (isAlive = False AndAlso numOfAdjacent = 3) Then
                    'Come Alive
                    isAliveNextGeneration = True
                End If

                If isAliveNextGeneration Then
                    nextGenerationRow.Append("1")
                Else
                    nextGenerationRow.Append("0")
                End If
            Next
            nextGeneration.Add(nextGenerationRow.ToString)
        Next

        gridOfLife = nextGeneration
    End Sub

    Private Function isCellAlive(cell As Char) As Boolean
        Return cell = "1"
    End Function
End Module
