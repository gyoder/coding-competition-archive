Module Problem10

    Sub Main(args As String())
        Dim i As Integer
        Int32.TryParse(Console.ReadLine(), i)
        Dim test As Integer = 0
        Dim arr As String()
        For test = 0 To (i - 1)
            Dim shift As Integer = Console.ReadLine()
            Dim cipher As String = Console.ReadLine()
            Dim cipherChar As New List(Of Integer)
            Dim plaintext As String = ""
            cipher = cipher.ToLower()

            For i = 0 To cipher.Length - 1
                cipherChar.Add(AscW(cipher(i)))

                If ChrW(cipherChar(i)) = " " Then
                    plaintext &= " "

                Else
                    cipherChar(i) -= shift

                    If cipherChar(i) < AscW("a") Then
                        cipherChar(i) += 26
                    ElseIf cipherChar(i) > AscW("z") Then
                        cipherChar(i) -= 26
                    End If

                    plaintext &= ChrW(cipherChar(i))
                End If
            Next

            Console.WriteLine(plaintext)
        Next
        Console.ReadLine()
    End Sub

    Sub Die(message As String)
        Console.WriteLine(message)
        Console.ReadLine()
        End
    End Sub

End Module
