Option Explicit On

Module HomewardBound
    Sub Main(args As String())
        Dim i As Integer
        Int32.TryParse(Console.ReadLine(), i)
        Dim test As Integer = 0
        For test = 0 To (i - 1)
            runTest(Console.ReadLine())
        Next
    End Sub

    Private Sub runTest(testLine As String)
        Dim flight() As String
        Dim originatingCity As String = String.Empty

        'Get the number of boarding passes that need to be sorted
        Dim numberofPasses As Int16 = 0
        Int16.TryParse(testLine, numberofPasses)

        'If there are no boarding pass then return 
        If numberofPasses < 1 Then
            Return
        End If

        'Save all boarding passed into a dictionary
        'A dictionary will allow easy search 
        Dim outboundFlights As Dictionary(Of String, String) = New Dictionary(Of String, String)

        For index = 1 To numberofPasses
            flight = Console.ReadLine().Split(" ")
            outboundFlights.Add(flight(1), flight(0))
        Next

        'find originating cityso that we can sort from there
        For index = 1 To numberofPasses
            originatingCity = outboundFlights.Keys(index - 1)

            'Once we find a city that has no prior flight then we found the originating city so step out of the loop
            If outboundFlights.ContainsValue(originatingCity) = False Then
                Exit For
            End If

        Next

        'Write out the originating cities 
        Console.WriteLine(originatingCity)

        'Using the originating city get the next city and write it out
        For index = 1 To numberofPasses
            Console.WriteLine(outboundFlights(originatingCity))
            originatingCity = outboundFlights(originatingCity)
        Next
    End Sub
End Module
