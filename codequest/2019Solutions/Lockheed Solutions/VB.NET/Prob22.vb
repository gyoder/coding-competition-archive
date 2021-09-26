Option Explicit On

Imports System.Text.RegularExpressions

Module FreeUpDiskSpace

    ' 10:55 AM
    ' 11:30 AM
    ' 35 Minutes
    Sub Main()
        Dim numOfCases As Integer = Integer.Parse(Console.ReadLine())

        For testCase As Integer = 0 To (numOfCases - 1)
            Dim inputLine As String = Console.ReadLine()

            Dim pattern As New Regex("(\d+) (\d+.\d+)")
            Dim match As Match = pattern.Match(inputLine)

            Dim numOfFiles As Integer
            Dim sizeOfDrive As Double

            If match.Success Then
                numOfFiles = Integer.Parse(match.Groups(1).Value)
                sizeOfDrive = Double.Parse(match.Groups(2).Value) * 1000
            End If

            Dim files As New List(Of File)

            For fileLines As Integer = 0 To (numOfFiles - 1)
                Dim fileLine As String = Console.ReadLine()
                pattern = New Regex("((\d{2}/\d{2}/\d{4}) \d{2}:\d{2} (AM|PM)) (\d+) (.*)")

                match = pattern.Match(fileLine)
                If match.Success Then
                    Dim file As New File(Date.ParseExact(match.Groups(2).Value, "dd/MM/yyyy", System.Globalization.DateTimeFormatInfo.InvariantInfo), match.Groups(5).Value, Long.Parse(match.Groups(4).Value), match.Groups(3).Value = "PM")

                    files.Add(file)
                End If
            Next

            files.Sort(Function(x As File, y As File)
                           Return y.GetScore - x.GetScore
                       End Function)

            Dim fileSizeSum As Double = 0

            For Each file In files
                fileSizeSum += (CDbl(file.getFileSize()) / CDbl(1000))

                Console.WriteLine(String.Format("{0} {1}", file.getFileName(), file.GetScore().ToString("0.000")))

                If (fileSizeSum >= (sizeOfDrive * 0.25)) Then
                    Exit For
                End If

            Next

        Next

    End Sub

    Public Class File
        Private _fileDt As Date
        Private _fileName As String
        Private _fileSize As Long
        Private _afternoon As Boolean
        Public Sub New(ByRef fileDt As Date, ByRef fileName As String, ByRef fileSize As Long, ByRef afternoon As Boolean)
            _fileDt = fileDt
            _fileName = fileName
            _fileSize = fileSize
            _afternoon = afternoon
        End Sub

        Public Function getFileName() As String
            Return _fileName
        End Function
        Public Function getFileSize() As Long
            Return _fileSize
        End Function

        Public Function GetAge() As Double
            Dim today As Date = Date.ParseExact("27/04/2019", "dd/MM/yyyy", System.Globalization.DateTimeFormatInfo.InvariantInfo)

            Dim age As Double = CDbl(DateDiff(DateInterval.Day, _fileDt, today))

            If (_afternoon = True) Then
                age -= 0.5
            End If

            Return age
        End Function

        Public Function GetRawScore() As Double
            Return GetAge() * (CDbl(_fileSize) / CDbl(1000))
        End Function

        Public Function GetScore() As Double
            Return Math.Round(GetAge() * (CDbl(_fileSize) / CDbl(1000)), 3, MidpointRounding.AwayFromZero)
        End Function

        Public Overrides Function ToString() As String
            Return String.Format("File Date: {0}    File Name: {1}      File Size: {2}      Age: {3}   Raw Score: {4}       Rounded Score: {5}", _fileDt, _fileName, _fileSize, GetAge(), GetRawScore(), GetScore())
        End Function
    End Class

End Module
