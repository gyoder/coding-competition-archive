Option Explicit On
Imports System.Text

Module HaveYouSeenMyKey

    ' 2:20 PM
    ' 2:34 PM
    Sub Main()
        Dim numOfCases As Integer = Integer.Parse(Console.ReadLine())

        For testCase As Integer = 0 To (numOfCases - 1)
            Dim numOfStrings As Integer = Integer.Parse(Console.ReadLine())
            Dim cipherText As String = Console.ReadLine()

            For keyNum As Integer = 0 To (numOfStrings - 1)
                Dim key As String = Console.ReadLine()
                Dim text As New StringBuilder()

                For digit As Integer = 0 To (cipherText.Length - 1) Step 2
                    Dim c As Integer = Convert.ToInt32(cipherText.Substring(digit, 2), 16)
                    Dim k As Integer = Convert.ToInt32(key.Substring(digit, 2), 16)

                    Dim t As Integer = c Xor k

                    text.Append(Chr(t))
                Next

                Console.WriteLine(String.Format("[{0, -64}]", text))
            Next
        Next
    End Sub

End Module
