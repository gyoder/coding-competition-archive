Module Module1

    Sub Main()
        On Error GoTo Errortrap



        Dim i As Integer
        Dim strline As String
        Dim intnumlines As Integer


        intnumlines = Console.ReadLine()

        For i = 1 To intnumlines

            strline = Console.ReadLine()
            Console.WriteLine(strline.ToLower)
        Next


        Console.ReadKey()
        Exit Sub

Errortrap:
        Console.WriteLine(Err.Description)
        Console.ReadKey()
    End Sub
End Module