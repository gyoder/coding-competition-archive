Option Explicit On
Imports System.Text.RegularExpressions

Module Prob09

    ' 2:50 PM
    ' 2:59 PM
    Sub Main()
        Dim numOfCases As Integer = Integer.Parse(Console.ReadLine())

        For testCase As Integer = 0 To (numOfCases - 1)
            Dim inputString As String = Console.ReadLine()

            Dim hourRegEx As New Regex("(\d+)h")
            Dim minRegEx As New Regex("(\d+)m")
            Dim secRegEx As New Regex("(\d+)s")

            Dim hours As Integer = 0
            Dim minutes As Integer = 0
            Dim seconds As Integer = 0

            Dim match As Match = hourRegEx.Match(inputString)
            If match.Success Then
                hours = Integer.Parse(match.Groups(1).Value)
            End If

            match = minRegEx.Match(inputString)
            If match.Success Then
                minutes = Integer.Parse(match.Groups(1).Value)
            End If

            match = secRegEx.Match(inputString)
            If match.Success Then
                seconds = Integer.Parse(match.Groups(1).Value)
            End If

            Console.WriteLine(String.Format("{0}:{1}:{2}", hours.ToString("00"), minutes.ToString("00"), seconds.ToString("00")))
        Next
    End Sub

End Module
