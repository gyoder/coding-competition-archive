Option Explicit On

Module HelloWorld

    Sub Main(args As String())
        Dim i As Integer
        Int32.TryParse(Console.ReadLine(), i)
        Dim test As Integer = 0
        For test = 0 To (i - 1)
            Console.WriteLine(Console.ReadLine())
        Next
    End Sub

End Module
