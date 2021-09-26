Option Explicit On
Module CountToTen
    Public Sub Main()
        Dim testCases As Integer
        Integer.TryParse(Console.ReadLine(), testCases)
        For testCase As Integer = 0 To (testCases - 1)
            solve()
        Next
    End Sub

    Sub solve()
        Dim BitCount = Convert.ToInt32(Console.ReadLine())
        Dim maxnumber As Integer = Math.Pow(2, BitCount) - 1
        For i As Integer = 0 To maxnumber
            Console.WriteLine(Convert.ToString(i, 2).PadLeft(BitCount, "0"c))
        Next
    End Sub
End Module
