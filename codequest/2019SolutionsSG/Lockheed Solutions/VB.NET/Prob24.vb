Option Explicit On

Module Sudoku
    Sub Main(args As String())
        Dim i As Integer
        Int32.TryParse(Console.ReadLine(), i)
        Dim test As Integer = 0
        For test = 0 To (i - 1)
            Dim board(8, 8) As Integer
            Dim cellOptions As List(Of List(Of List(Of Integer))) = New List(Of List(Of List(Of Integer)))

            Dim row As Integer = 0
            Dim col As Integer = 0
            Dim num As Integer = 1
            For row = 0 To 8
                cellOptions.Add(New List(Of List(Of Integer)))
                For col = 0 To 8
                    cellOptions(row).Add(New List(Of Integer))
                    For num = 1 To 9
                        cellOptions(row)(col).Add(num)
                    Next
                Next
            Next

            Dim numbersComplete As Integer = 0

            For row = 0 To 8
                Dim inputLine As String = Console.ReadLine()
                For col = 0 To 8
                    If inputLine.Chars(col) = "_" Then
                        board(row, col) = 0
                    Else
                        board(row, col) = Asc(inputLine.Chars(col)) - 48
                        numbersComplete = numbersComplete + 1
                        scratchOffNumber(row, col, board(row, col), cellOptions)
                    End If
                Next
            Next

            solve(board, numbersComplete, cellOptions)

            For row = 0 To 8
                For col = 0 To 8
                    Console.Write(board(row, col))
                Next
                Console.WriteLine()
            Next
        Next
    End Sub

    Private Sub scratchOffNumber(ByVal row As Integer, ByVal col As Integer, ByVal value As Integer, ByRef cellOptions As List(Of List(Of List(Of Integer))))
        cellOptions(row)(col) = Nothing

        Dim i As Integer
        For i = 0 To 8
            If cellOptions(row)(i) IsNot Nothing Then
                cellOptions(row)(i).Remove(value)
            End If
            If cellOptions(i)(col) IsNot Nothing Then
                cellOptions(i)(col).Remove(value)
            End If
            Dim subRow As Integer = ((row \ 3) * 3) + (i \ 3)
            Dim subCol As Integer = ((col \ 3) * 3) + (i Mod 3)
            If cellOptions(subRow)(subCol) IsNot Nothing Then
                cellOptions(subRow)(subCol).Remove(value)
            End If
        Next
    End Sub

    Private Function solve(ByRef board(,) As Integer, ByVal numbersFilled As Integer, ByRef cellOptions As List(Of List(Of List(Of Integer)))) As Boolean
        Dim numbersDone As Integer = numbersFilled

        While numbersDone < 81
            Dim entryMade As Boolean = False
            Dim minimumOptions As Integer = 9
            Dim minOptRow As Integer = 9
            Dim minOptCol As Integer = 9

            Dim row As Integer
            Dim col As Integer

            For row = 0 To 8
                For col = 0 To 8
                    Dim options As List(Of Integer) = cellOptions(row)(col)
                    If options IsNot Nothing Then
                        If options.Count = 1 Then
                            Dim value As Integer = options(0)
                            board(row, col) = value
                            scratchOffNumber(row, col, value, cellOptions)
                            entryMade = True
                            numbersDone = numbersDone + 1
                            Exit For
                        ElseIf options.Count = 0 Then
                            Return False
                        ElseIf options.Count < minimumOptions Then
                            minimumOptions = options.Count
                            minOptRow = row
                            minOptCol = col
                        End If
                    End If
                Next
                If entryMade Then
                    Exit For
                End If
            Next

            If entryMade Then
                Continue While
            End If

            Dim possibleOptions As List(Of Integer) = cellOptions(minOptRow)(minOptCol)
            Dim idx As Integer
            For idx = 0 To possibleOptions.Count - 1
                Dim optionValue As Integer = possibleOptions(idx)
                Dim boardCopy(8, 8) As Integer
                Dim cellOptionsCopy As List(Of List(Of List(Of Integer))) = New List(Of List(Of List(Of Integer)))(9)

                For row = 0 To 8
                    cellOptionsCopy.Add(New List(Of List(Of Integer)))
                    For col = 0 To 8
                        boardCopy(row, col) = board(row, col)
                        If cellOptions(row)(col) IsNot Nothing Then
                            cellOptionsCopy(row).Add(New List(Of Integer))
                            cellOptionsCopy(row)(col).AddRange(cellOptions(row)(col))
                        Else
                            cellOptionsCopy(row).Add(Nothing)
                        End If
                    Next
                Next

                boardCopy(minOptRow, minOptCol) = optionValue
                scratchOffNumber(minOptRow, minOptCol, optionValue, cellOptionsCopy)

                If solve(boardCopy, numbersDone + 1, cellOptionsCopy) Then
                    For row = 0 To 8
                        For col = 0 To 8
                            board(row, col) = boardCopy(row, col)
                        Next
                    Next
                    Return True
                End If
            Next

            Return False
        End While

        Return True
    End Function
End Module
