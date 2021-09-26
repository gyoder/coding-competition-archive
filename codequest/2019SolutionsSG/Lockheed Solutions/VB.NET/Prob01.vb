Option Explicit On

Module NoMoreShouting

    Sub Main()
        Dim i As Integer
        Int32.TryParse(Console.ReadLine(), i)
        Dim test As Integer = 0
        For test = 0 To (i - 1)
            Dim input As String = Console.ReadLine()

            Console.WriteLine(input.ToLower())
        Next

    End Sub

End Module
