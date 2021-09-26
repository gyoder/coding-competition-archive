Module Problem11

    Sub Main(args As String())
        Dim i As Integer
        Int32.TryParse(Console.ReadLine(), i)
        Dim test As Integer = 0
        Dim arr As String()
        For test = 0 To (i - 1)
            arr = Console.ReadLine().Split(" ")
            Dim n As Integer = arr(0)
            For x = 0 To (2 ^ n) - 1
                Console.WriteLine(GetBinary(x, n))
            Next
        Next
        Console.ReadLine()
    End Sub

    Sub Die(message As String)
        Console.WriteLine(message)
        Console.ReadLine()
        End
    End Sub

    Function GetBinary(ByVal Deci As Integer, ByVal aaaaaa As Integer)
        Dim binary As String = ""
        For i = aaaaaa - 1 To 0 Step -1
            If Deci >= 2 ^ i Then
                binary &= "1"
                Deci -= 2 ^ i
            Else binary &= "0"
            End If
        Next
        Return binary
    End Function




End Module
