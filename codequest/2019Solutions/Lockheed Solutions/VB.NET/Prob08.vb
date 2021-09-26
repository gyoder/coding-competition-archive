Option Explicit On
Module Prob08

    Sub Main()
        Dim cases As Int32 = Console.ReadLine()
        For counter As Int32 = 0 To cases - 1
            Dim dataIn As String = Console.ReadLine().Trim()
            Dim raw_nums As String() = dataIn.Split(New Char() {" "c})
            Dim values = Array.ConvertAll(raw_nums, Function(str) Int32.Parse(str))

            Dim eyeRow As Int32 = values(0)
            Dim eyeCol As Int32 = values(1)

            For row As Int32 = 0 To 19
                Dim rowValue As String = ""
                For col As Int32 = 0 To 19
                    Dim rowDiff = Math.Abs(row - eyeRow)
                    Dim colDiff = Math.Abs(col - eyeCol)
                    If rowDiff + colDiff = 0 Then
                        rowValue += "100 "
                    ElseIf rowDiff + colDiff > 4 Then
                        rowValue += "10 "
                    ElseIf rowDiff = 2 Or colDiff = 2 Then
                        rowValue += "25 "
                    ElseIf (rowDiff = 1 And colDiff <= 1) Or (colDiff = 1 And rowDiff <= 1) Then
                        rowValue += "50 "
                    Else
                        rowValue += "10 "
                    End If
                Next
                Console.WriteLine(rowValue.Trim())
            Next
        Next
    End Sub

End Module
