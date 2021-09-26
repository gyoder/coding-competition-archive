Option Explicit On
Module GoofyGorillas

    Sub Main(args As String())
        Dim i As Integer
        Int32.TryParse(Console.ReadLine(), i)
        Dim test As Integer = 0
        For test = 0 To (i - 1)
            Dim input As String = Console.ReadLine()
            Dim gorilla1 As String = input.Substring(0, input.IndexOf(" "))
            Dim gorilla2 As String = input.Substring(input.IndexOf(" ") + 1)

            If (Boolean.Parse(gorilla1) = True AndAlso Boolean.Parse(gorilla2) = True) Then
                Console.WriteLine("true")
            ElseIf (Boolean.Parse(gorilla1) = False AndAlso Boolean.Parse(gorilla2) = False) Then
                Console.WriteLine("true")
            Else
                Console.WriteLine("false")
            End If
        Next

    End Sub

End Module
