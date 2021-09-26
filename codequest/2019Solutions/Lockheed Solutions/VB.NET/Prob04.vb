Option Explicit On
Module CaughtSpeeding

    Public Sub Main()
        Dim testCases As Integer
        Integer.TryParse(Console.ReadLine(), testCases)
        For testCase As Integer = 0 To (testCases - 1)
            solve()
        Next
    End Sub

    Sub solve()
        Dim LineArray = Console.ReadLine().Split(" ")
        Dim Speed = Convert.ToInt32(LineArray(0))
        Dim isBirthday = Convert.ToBoolean(LineArray(1))
        If Speed <= (60 + If(isBirthday, 5, 0)) Then
            Console.WriteLine("no ticket")
        ElseIf Speed <= (80 + If(isBirthday, 5, 0)) Then
            Console.WriteLine("small ticket")
        Else
            Console.WriteLine("big ticket")
        End If
    End Sub

End Module
