Imports System.IO
Module Module1
    Sub Main()
        ' Stops errors from crashing the program
        On Error GoTo ErrorTrap

        ' Tell the user the program has started ok

        Dim i As Integer
        Dim intNum1 As Integer
        Dim intNum2 As Integer
        Dim strInput As String
        Dim intFinalNUm As Integer
        Dim numLines As Integer
        Dim tokens As Integer
        numLines = Console.ReadLine()

            For i = 1 To numLines
            strInput = Console.ReadLine()
            strInput.Split(" ")
            intNum1 = System.Convert.ToInt32(strInput.Split(" ")(0))
            intNum2 = System.Convert.ToInt32(strInput.Split(" ")(1))


            ' Write code here
            If intNum1 = intNum2 Then
                    intFinalNUm = intNum1 + intNum2
                    intFinalNUm = intFinalNUm * 2
                Else
                    intFinalNUm = intNum1 + intNum2
                End If

                Console.WriteLine(intFinalNUm)
            Next

            Console.ReadKey()
        Exit Sub

ErrorTrap:


        Console.ReadKey()
        Call Sub() Main()

    End Sub
End Module