Option Explicit On
Module CaesarCipher
    Dim ZEE_INT As Integer = Convert.ToInt32("z"c)
    Dim AHH_INT As Integer = Convert.ToInt32("a"c)
    Sub Main()
        'stand test case stuff
        Dim input, numTestCasesStr As String
        Dim numTestCases, numShift As Integer

        numTestCasesStr = Console.ReadLine()
        numTestCases = UInteger.Parse(numTestCasesStr)

        While numTestCases > 0
            input = Console.ReadLine()
            numShift = Integer.Parse(input)
            input = Console.ReadLine()
            HandleTestCase(numShift, input)

            numTestCases = numTestCases - 1
        End While

        Console.Read()
    End Sub

    Private Sub HandleTestCase(numShift As Integer, input As String)
        Dim newChar As Char
        For Each c As Char In input.ToCharArray()
            newChar = ShiftChar(c, numShift)
            Console.Write(newChar)
        Next
        Console.WriteLine("")
    End Sub

    Private Function ShiftChar(c As Char, numShift As Integer) As Char
        Dim charAsInt As Integer
        Dim newChar As Char
        charAsInt = Convert.ToInt32(c)

        If c = " "c Then
            Return " "c
        End If

        charAsInt -= numShift

        If charAsInt < AHH_INT Then
            charAsInt = (ZEE_INT - (AHH_INT - charAsInt)) + 1
        ElseIf charAsInt > ZEE_INT Then
            charAsInt = (charAsInt - ZEE_INT) + AHH_INT - 1
        End If

        newChar = Chr(charAsInt)

        Return newChar
    End Function

End Module
