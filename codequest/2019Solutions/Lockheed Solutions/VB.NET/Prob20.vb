Option Explicit On

Imports System.Text.RegularExpressions

Module BirdWatching

    Public Const DEBUG As Boolean = False


    ' 10:55 PM
    ' 11:43 PM
    ' 48 Min
    Sub Main()
        Dim numOfCases As Integer = Integer.Parse(Console.ReadLine())

        For testCase As Integer = 0 To (numOfCases - 1)
            Dim inputLine As String = Console.ReadLine()

            Dim pattern As New Regex("(\d+) (\d+)")
            Dim match As Match = pattern.Match(inputLine)

            Dim numOfKnown As Integer
            Dim numOfUnknown As Integer

            If match.Success Then
                numOfKnown = Integer.Parse(match.Groups(1).Value)
                numOfUnknown = Integer.Parse(match.Groups(2).Value)
            End If

            Dim knownBirds As New List(Of Bird)

            For count As Integer = 1 To numOfKnown
                inputLine = Console.ReadLine()

                pattern = New Regex("(Accipitridae|Passeridae|Cathartidae) (\d+.\d+) (\d+.\d+) (\d+.\d+) (\d+.\d+)")
                match = pattern.Match(inputLine)

                If match.Success Then
                    'knownBirds
                    knownBirds.Add(New Bird(match.Groups(1).Value, Double.Parse(match.Groups(2).Value), Double.Parse(match.Groups(3).Value), Double.Parse(match.Groups(4).Value), Double.Parse(match.Groups(5).Value)))
                End If

            Next

            For count As Integer = 1 To numOfUnknown
                inputLine = Console.ReadLine()

                pattern = New Regex("(\d+.\d+) (\d+.\d+) (\d+.\d+) (\d+.\d+)")
                match = pattern.Match(inputLine)

                If match.Success Then
                    Dim unknownLength As Double = Double.Parse(match.Groups(1).Value)
                    Dim unknownWidth As Double = Double.Parse(match.Groups(2).Value)
                    Dim unknownWingspan As Double = Double.Parse(match.Groups(3).Value)
                    Dim unknownAngle As Double = Double.Parse(match.Groups(4).Value)

                    Dim distances As New List(Of Distance)
                    For Each _bird As Bird In knownBirds
                        distances.Add(New Distance(_bird.GetTaxonomy, _bird.GetDistance(unknownLength, unknownWidth, unknownWingspan, unknownAngle)))
                    Next


                    distances.Sort()

                    If (DEBUG) Then
                        For Each distance As Distance In distances
                            Console.WriteLine(distance.GetDistance())
                        Next
                    End If

                    Dim calculatedTaxonomy As String = String.Empty
                    For k As Integer = 5 To distances.Count
                        Dim accipitridae As Integer = 0
                        Dim passeridae As Integer = 0
                        Dim cathartidae As Integer = 0

                        For i As Integer = 0 To k - 1
                            If (distances(i).GetTaxonomy = "Accipitridae") Then
                                accipitridae += 1
                            ElseIf (distances(i).GetTaxonomy = "Passeridae") Then
                                passeridae += 1
                            ElseIf (distances(i).GetTaxonomy = "Cathartidae") Then
                                cathartidae += 1
                            End If
                        Next

                        If accipitridae > passeridae AndAlso accipitridae > cathartidae Then
                            calculatedTaxonomy = "Accipitridae"
                        ElseIf passeridae > accipitridae AndAlso passeridae > cathartidae Then
                            calculatedTaxonomy = "Passeridae"
                        ElseIf cathartidae > accipitridae AndAlso cathartidae > passeridae Then
                            calculatedTaxonomy = "Cathartidae"
                        End If
                        If calculatedTaxonomy <> String.Empty Then
                            Exit For
                        End If
                    Next

                    Console.WriteLine(calculatedTaxonomy)
                End If
            Next
        Next

    End Sub

    Public Class Distance
        Implements IComparable(Of Distance)

        Private _taxonomy As String
        Private _distance As Double

        Public Function GetTaxonomy() As String
            Return _taxonomy
        End Function

        Public Function GetDistance() As Double
            Return _distance
        End Function

        Public Sub New(taxonomy As String, distance As Double)
            _taxonomy = taxonomy
            _distance = distance
        End Sub

        Public Function CompareTo(other As Distance) As Integer Implements IComparable(Of Distance).CompareTo
            Return Me.GetDistance().CompareTo(other.GetDistance())
        End Function
    End Class

    Public Class Bird
        Private _taxonomy As String
        Private _length As Double
        Private _width As Double
        Private _wingspan As Double
        Private _angle As Double

        Public Sub New(taxonomy As String, length As Double, width As Double, wingspan As Double, angle As Double)
            _taxonomy = taxonomy
            _length = length
            _width = width
            _wingspan = wingspan
            _angle = angle
        End Sub

        Public Function GetTaxonomy() As String
            Return _taxonomy
        End Function

        Public Function GetDistance(length As Double, width As Double, wingspan As Double, angle As Double) As Double

            Return Math.Sqrt(Math.Pow((_length - length), 2) + Math.Pow((_width - width), 2) + Math.Pow((_wingspan - wingspan), 2) + Math.Pow((_angle - angle), 2))

        End Function

        Public Overrides Function ToString() As String
            Return String.Format("Taxonomy: {0}     Length: {1}     Width: {2}     Wingspan: {3}    Angle: {4}", _taxonomy, _length, _width, _wingspan, _angle)
        End Function


    End Class

End Module
