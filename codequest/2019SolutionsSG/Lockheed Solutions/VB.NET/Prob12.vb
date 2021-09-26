Option Explicit On

Module Prob12

    Class Door
        Public Propablity As Double
        Public Open As Boolean
        Public UserPick As Boolean
    End Class
    Public Sub Main()
        Dim testCases As Integer
        Integer.TryParse(Console.ReadLine(), testCases)
        For testCase As Integer = 0 To (testCases - 1)
            solve()
        Next
    End Sub
    Sub solve()
        Dim LineArray = Console.ReadLine().Split(" ")
        Dim NumberOfDoors = Convert.ToInt32(LineArray(0))
        Dim NumberOfRounds = Convert.ToInt32(LineArray(1))
        Dim NumberOfDoorsToBeOppened = Convert.ToInt32(LineArray(2))
        Dim DoorArray(NumberOfDoors - 1) As Door

        For i As Integer = 0 To NumberOfDoors - 1
            DoorArray(i) = New Door
            DoorArray(i).Open = False
            DoorArray(i).UserPick = False
            DoorArray(i).Propablity = (100.0 / NumberOfDoors)
        Next
        DoorArray(0).UserPick = True

        For roundNumber As Integer = 1 To NumberOfRounds
            'host opening doors
            For j As Integer = 1 To NumberOfDoorsToBeOppened
                For k As Integer = NumberOfDoors - 1 To 0 Step -1
                    If DoorArray(k).Open = False Then
                        DoorArray(k).Open = True
                        Exit For
                    End If
                Next
            Next
            'end host opening doors

            'recal probs
            Dim openCount = 0
            Dim PropablityOffSet = 0.0
            For i As Integer = 0 To NumberOfDoors - 1
                If DoorArray(i).UserPick = False And DoorArray(i).Open = False Then
                    openCount += 1
                ElseIf DoorArray(i).UserPick = True Then
                    PropablityOffSet += DoorArray(i).Propablity
                ElseIf DoorArray(i).Open = True Then
                    DoorArray(i).Propablity = 0
                End If
            Next
            Dim Propablity = ((100.0 - PropablityOffSet) / openCount)
            For i As Integer = 0 To NumberOfDoors - 1
                If DoorArray(i).UserPick = False And DoorArray(i).Open = False Then
                    DoorArray(i).Propablity = Propablity
                End If
            Next

            For i As Integer = 0 To NumberOfDoors - 1
                If DoorArray(i).UserPick = False And DoorArray(i).Open = False Then
                    DoorArray(i).UserPick = True
                    Exit For
                End If
            Next
            'end recal probs
        Next

        Dim highestPropablity = DoorArray(0).Propablity
        For i As Integer = 1 To NumberOfDoors - 1

            If highestPropablity < DoorArray(i).Propablity Then
                highestPropablity = DoorArray(i).Propablity
            End If
        Next
        Console.WriteLine(Math.Round(highestPropablity, 2, MidpointRounding.AwayFromZero).ToString("N2") + "%")
    End Sub

End Module
