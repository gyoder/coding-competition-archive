Imports System.IO
Module Module1
    Sub Main()
        ' Stops errors from crashing the program
        On Error GoTo ErrorTrap

        Dim i As Integer
        Dim intSpeed As Integer
        Dim strBirthday As String
        Dim strInput As String
        Dim numLines As Integer

        numLines = Console.ReadLine()
        For i = 1 To numLines
            strInput = Console.ReadLine()
            ' Write code here
            strInput.Split(" ")
            intSpeed = System.Convert.ToInt32(strInput.Split(" ")(0))
            strBirthday = System.Convert.ToString(strInput.Split(" ")(1))
            If strBirthday = "false" Then

                If intSpeed <= 60 Then
                    Console.WriteLine("no ticket")

                ElseIf intSpeed <= 80 Then
                    Console.WriteLine("small ticket")
                Else
                    Console.WriteLine("big ticket")
                End If
            ElseIf strBirthday = "true" Then
                If intSpeed <= 65 Then
                    Console.WriteLine("no ticket")

                ElseIf intSpeed <= 85 Then
                    Console.WriteLine("small ticket")
                Else
                    Console.WriteLine("big ticket")
                End If
            Else
                Call Sub() Main()
            End If
        Next

        Console.ReadKey()
        Exit Sub

ErrorTrap:


        Console.ReadKey()
        Call Sub() Main()

    End Sub
End Module