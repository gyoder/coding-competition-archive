Option Explicit On
Module Prob05

    Sub Main()
        Dim cases As Int32 = Console.ReadLine()
        For counter As Int32 = 0 To cases - 1
            Dim dataIn As String = Console.ReadLine().Trim()
            Dim raw_nums As String() = dataIn.Split(New Char() {" "c})
            Dim values = Array.ConvertAll(raw_nums, Function(str) Int32.Parse(str))
            Dim N1 As Int32 = values(0)
            Dim N2 As Int32 = values(1)
            Dim goal As Int32 = values(2)
            Dim large As Int32 = Math.Floor(goal / 5)

            If large > N2 Then
                goal -= Math.Floor(N2 * 5)
            Else
                goal -= Math.Floor(large * 5)
            End If
            If goal <= N1 Then
                Console.WriteLine("true")
            Else
                Console.WriteLine("false")
            End If
        Next
    End Sub

End Module
