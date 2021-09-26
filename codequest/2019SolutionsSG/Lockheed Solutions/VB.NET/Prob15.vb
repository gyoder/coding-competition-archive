Option Explicit On

Imports System.Text.RegularExpressions

Module LMCoin

    ' 6:30 PM
    ' 6:50 PM
    ' 20 Min
    Sub Main()
        Dim numOfCases As Integer = Integer.Parse(Console.ReadLine())
        Dim charValues As New Dictionary(Of Char, Long)
        charValues.Add("a"c, 1)
        charValues.Add("b"c, 2)
        charValues.Add("c"c, 3)
        charValues.Add("d"c, 4)
        charValues.Add("e"c, 5)
        charValues.Add("f"c, 6)
        charValues.Add("g"c, 7)
        charValues.Add("h"c, 8)
        charValues.Add("i"c, 9)
        charValues.Add("j"c, 10)
        charValues.Add("k"c, 11)
        charValues.Add("l"c, 12)
        charValues.Add("m"c, 13)
        charValues.Add("n"c, 14)
        charValues.Add("o"c, 15)
        charValues.Add("p"c, 16)
        charValues.Add("q"c, 17)
        charValues.Add("r"c, 18)
        charValues.Add("s"c, 19)
        charValues.Add("t"c, 20)
        charValues.Add("u"c, 21)
        charValues.Add("v"c, 22)
        charValues.Add("w"c, 23)
        charValues.Add("x"c, 24)
        charValues.Add("y"c, 25)
        charValues.Add("z"c, 26)

        For testCase As Integer = 0 To (numOfCases - 1)
            Dim inputLine As String = Console.ReadLine()

            Dim pattern As New Regex("(.*) (.*) (.*) (.*) (.*) (.*) (.*) (.*) (.*) (.*)")
            Dim match As Match = pattern.Match(inputLine)

            Dim dataValues As New List(Of String)
            Dim timestamps As New List(Of Long)

            If match.Success Then
                For i As Integer = 1 To 10
                    dataValues.Add(match.Groups(i).Value)
                Next

                inputLine = Console.ReadLine()
                match = pattern.Match(inputLine)

                If match.Success Then
                    For i As Integer = 1 To 10
                        timestamps.Add(Long.Parse(match.Groups(i).Value))
                    Next
                End If
            End If

            Dim hash As Double = 0
            For i As Integer = 1 To 10
                Dim data As Char() = dataValues(i - 1).ToCharArray()
                Dim tn As Long = timestamps(i - 1)

                Dim v As Long = 0
                For Each c As Char In data
                    v += charValues(c)
                    'Console.WriteLine(String.Format("{0}   {1}", c, charValues(c)))
                Next

                hash = ((tn + v + i + hash) * 50) / 147
            Next

            Console.WriteLine(Math.Round(hash))
        Next
    End Sub

End Module
