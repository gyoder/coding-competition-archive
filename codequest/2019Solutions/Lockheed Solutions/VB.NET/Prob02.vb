Option Explicit On
Module Prob02

    Sub Main()
        Dim cases As Int32 = Console.ReadLine()
        For counter As Int32 = 0 To cases - 1
            Dim dataIn As String = Console.ReadLine().Trim()
            Dim raw_nums As String() = dataIn.Split(New Char() {" "c})
            Dim values = Array.ConvertAll(raw_nums, Function(str) Int32.Parse(str))
            Dim N1 As Int32 = values(0)
            Dim N2 As Int32 = values(1)

            If N1 = N2 Then
                Console.WriteLine(N1 + N1 + N2 + N2)
            Else
                Console.WriteLine(N1 + N2)
            End If
        Next
    End Sub

End Module
