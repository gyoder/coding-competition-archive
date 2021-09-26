Option Explicit On

Imports System.Text.RegularExpressions

Module HideYourSpies
    Public Const DEBUG As Boolean = False

    ' 2:15 PM
    ' 2:42 PM
    ' 27 Minutes
    Sub Main()
        Dim numOfCases As Integer = Integer.Parse(Console.ReadLine())

        For testCase As Integer = 0 To (numOfCases - 1)
            Dim inputLine As String = Console.ReadLine()

            Dim pattern As New Regex("(-?\d+) (-?\d+) (-?\d+) (-?\d+) (\d+)")
            Dim match As Match = pattern.Match(inputLine)

            If match.Success Then
                Dim spyX As Double = Double.Parse(match.Groups(1).Value)
                Dim spyY As Double = Double.Parse(match.Groups(2).Value)
                Dim cameraX As Double = Double.Parse(match.Groups(3).Value)
                Dim cameraY As Double = Double.Parse(match.Groups(4).Value)
                Dim numOfWalls As Integer = Double.Parse(match.Groups(5).Value)

                Dim cameraToSpyLine As New Line(spyX, spyY, cameraX, cameraY)

                Dim walls As New List(Of Line)(numOfWalls)
                For i As Integer = 0 To numOfWalls - 1
                    inputLine = Console.ReadLine()
                    pattern = New Regex("(-?\d+) (-?\d+) (-?\d+) (-?\d+)")
                    match = pattern.Match(inputLine)
                    If match.Success Then
                        walls.Add(New Line(Double.Parse(match.Groups(1).Value), Double.Parse(match.Groups(2).Value), Double.Parse(match.Groups(3).Value), Double.Parse(match.Groups(4).Value)))
                    End If
                Next

                If DEBUG Then
                    Console.WriteLine(cameraToSpyLine)
                    For Each wall As Line In walls
                        Console.WriteLine(wall)
                    Next
                End If

                ' Calculate slope of Camera to Spy

                Dim m As Double = ((cameraY - spyY) / (cameraX - spyX))
                Dim c As Double = (spyY) - ((m) * (spyX))

                Dim hidden As Boolean = False

                For Each wall As Line In walls
                    If wall.HasIntersection(cameraToSpyLine) Then
                        hidden = True
                        Exit For
                    End If
                Next

                If Not hidden Then
                    Console.WriteLine("YES")
                Else
                    Console.WriteLine("NO")
                End If
            End If
        Next
    End Sub


    Public Class Line
        Public _startX As Double
        Public _startY As Double
        Public _endX As Double
        Public _endY As Double

        Public Sub New(startX As Double, startY As Double, endX As Double, endY As Double)
            _startX = startX
            _startY = startY
            _endX = endX
            _endY = endY
        End Sub

        Public Function GetSlope() As Double
            Return ((_endY - _startY) / (_endX - _startX))
        End Function

        Public Function isVertical() As Boolean
            Return (_endX - _startX) = 0
        End Function

        Public Function GetC() As Double
            If isVertical() Then
                Return 0
            End If
            Return (_startY) - (GetSlope() * (_startX))
        End Function

        Public Overrides Function ToString() As String
            Return String.Format("Line [StartX: {0} StartY: {1} EndX: {2} EndY: {3}     (y = {4}x + {5})]", _startX, _startY, _endX, _endY, GetSlope(), GetC())
        End Function

        Public Function HasIntersection(otherLine As Line) As Boolean
            Dim intersects As Boolean = False

            Dim c1 As Double = otherLine.GetC()
            Dim m1 As Double = otherLine.GetSlope()
            Dim c2 As Double = GetC()
            Dim m2 As Double = GetSlope()

            Dim x As Double = -((c1 - c2) / (m1 - m2))
            Dim y As Double = (m1 * x) + c1
            If (c1 = GetC()) Then
                ' Same slope, parallel lines
                intersects = False
            ElseIf (otherLine.isVertical()) Then
                ' If the other line Is vertical...
                x = otherLine._startX
                ' Solve myself for Y And see if I am on the line
                y = (m2 * x) + c2

                If ((y >= Math.Min(_startY, _endY) AndAlso y >= Math.Min(otherLine._startY, otherLine._endY)) AndAlso (y <= Math.Max(_startY, _endY) AndAlso y <= Math.Max(otherLine._startY, otherLine._endY))) Then
                    intersects = True
                End If
            ElseIf (isVertical()) Then
                ' If current wall Is vertical...
                x = _startX
                ' Solve Other line for for Y And see if I am on the line
                y = (m1 * x) + c1

                If ((y >= Math.Min(_startY, _endY) AndAlso y >= Math.Min(otherLine._startY, otherLine._endY)) AndAlso (y <= Math.Max(_startY, _endY) AndAlso y <= Math.Max(otherLine._startY, otherLine._endY))) Then
                    intersects = True
                End If
            Else
                If ((x >= Math.Min(_startX, _endX) AndAlso x >= Math.Min(otherLine._startX, otherLine._endX)) AndAlso (x <= Math.Max(_startX, _endX) AndAlso x <= Math.Max(otherLine._startX, otherLine._endX))) Then
                    intersects = True
                End If
            End If

            If (DEBUG) Then
                If (intersects) Then
                    Console.WriteLine(Me.ToString())
                    Console.WriteLine(String.Format("Intersection at ({0}, {1})", x, y))
                Else
                    Console.WriteLine("No Intersection")
                End If
            End If

            Return intersects
        End Function
    End Class
End Module
