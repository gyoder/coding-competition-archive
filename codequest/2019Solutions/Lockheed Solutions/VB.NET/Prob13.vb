Option Explicit On
Imports System.Text
Imports System.Text.RegularExpressions

Module Minesweeper

    ' 4:55 PM
    ' 5:12 PM
    ' 17 Minutes
    Sub Main()
        Dim numOfCases As Integer = Integer.Parse(Console.ReadLine())

        For testCase As Integer = 0 To (numOfCases - 1)
            Dim inputLine As String = Console.ReadLine()

            Dim pattern As New Regex("(\d+) (\d+) (\d+)")
            Dim match As Match = pattern.Match(inputLine)

            If match.Success Then
                Dim r As Integer = Integer.Parse(match.Groups(1).Value)
                Dim c As Integer = Integer.Parse(match.Groups(2).Value)
                Dim b As Integer = Integer.Parse(match.Groups(3).Value)

                Dim GRID(r, c) As String

                For i As Integer = 0 To b - 1
                    inputLine = Console.ReadLine()
                    pattern = New Regex("(\d+) (\d+)")
                    match = pattern.Match(inputLine)

                    If match.Success Then
                        Dim row As Integer = Integer.Parse(match.Groups(1).Value)
                        Dim col As Integer = Integer.Parse(match.Groups(2).Value)

                        ' Place teh bomb's on the grid
                        GRID(row, col) = "*"
                    End If
                Next

                For i As Integer = 0 To r - 1
                    Dim output As New StringBuilder()
                    For j As Integer = 0 To c - 1
                        Dim val As String = GRID(i, j)
                        If val = String.Empty Then
                            Dim bombs As Integer = 0

                            ' Check for bombs

                            ' Check Above row
                            If (i - 1 >= 0) Then
                                If (j - 1 >= 0 AndAlso GRID(i - 1, j - 1) = "*") Then
                                    bombs += 1
                                End If

                                If (GRID(i - 1, j) = "*") Then
                                    bombs += 1
                                End If

                                If (j + 1 < c AndAlso GRID(i - 1, j + 1) = "*") Then
                                    bombs += 1
                                End If
                            End If

                            'Check current Row, ahead/behind
                            If (j - 1 >= 0 AndAlso GRID(i, j - 1) = "*") Then
                                bombs += 1
                            End If

                            If (j + 1 < c AndAlso GRID(i, j + 1) = "*") Then
                                bombs += 1
                            End If

                            ' Check Below row
                            If (i + 1 < r) Then
                                If (j - 1 >= 0 AndAlso GRID(i + 1, j - 1) = "*") Then
                                    bombs += 1
                                End If

                                If (GRID(i + 1, j) = "*") Then
                                    bombs += 1
                                End If

                                If (j + 1 < c AndAlso GRID(i + 1, j + 1) = "*") Then
                                    bombs += 1
                                End If
                            End If
                            val = bombs.ToString
                        End If
                        output.Append(val)
                    Next
                    Console.WriteLine(output)
                Next
            End If
        Next

    End Sub

End Module
