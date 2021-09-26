Module Module1

    Sub Main()
        Dim i As Integer
        Int32.TryParse(Console.ReadLine(), i)
        Dim test As Integer = 0
        Dim arr As String()
        For test = 0 To (i - 1)
            arr = Console.ReadLine().Split(" ")
            If arr.Length <> 2 Then
                Die("There are too many or too little terms in your input.")
            Else
                Dim term1 As Boolean = (arr(0).ToLower = "true")
                Dim term2 As Boolean = (arr(1).ToLower = "true")

                If term1 = term2 Then
                    Console.WriteLine("true")
                Else
                    Console.WriteLine("false")
                End If
            End If
        Next
        Console.ReadLine()
    End Sub

    Sub Die(message As String)
        Console.WriteLine(message)
        Console.ReadLine()
        End
    End Sub

End Module
