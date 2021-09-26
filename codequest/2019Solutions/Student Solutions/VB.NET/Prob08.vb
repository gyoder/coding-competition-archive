Module Problem8

    Sub Main(args As String())
        Dim i As Integer
        Int32.TryParse(Console.ReadLine(), i)
        Dim test As Integer = 0
        Dim arr As String()
        For test = 0 To (i - 1)
            arr = Console.ReadLine().Split(" ")
            Dim ix = arr(0)
            Dim iy = arr(1)
            Dim grid(19, 19)
            For x = 0 To 19
                For y = 0 To 19
                    grid(x, y) = 10
                Next
            Next

            For x = ix - 2 To ix + 2
                For y = iy - 2 To iy + 2
                    Try
                        grid(x, y) = 25
                    Catch ex As IndexOutOfRangeException
                        ' ignore()
                    End Try
                Next
            Next

            For x = ix - 1 To ix + 1
                For y = iy - 1 To iy + 1
                    Try
                        grid(x, y) = 50
                    Catch ex As Exception
                        ' ignore()
                    End Try
                Next
            Next

            grid(ix, iy) = 100

            For y = 0 To 19
                For x = 0 To 19
                    Console.Write(grid(y, x))
                    If x <> 19 Then
                        Console.Write(" ")
                    Else
                        Console.WriteLine()
                    End If
                Next
            Next
        Next
        Console.ReadLine()
    End Sub

    Sub Die(message As String)
        Console.WriteLine(message)
        Console.ReadLine()
        End
    End Sub

End Module
