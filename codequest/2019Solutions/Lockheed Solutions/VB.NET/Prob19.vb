Imports System.Text
Imports System.Text.RegularExpressions

Module NetworkRanger

    ' 3:08 PM
    ' 3:49 PM
    Sub Main()
        Dim numOfCases As Integer = Integer.Parse(Console.ReadLine())

        For testCase As Integer = 0 To (numOfCases - 1)
            Dim numOfIpAddresses As Integer = Integer.Parse(Console.ReadLine())

            Dim ipAddresses As New ArrayList()

            For i As Integer = 0 To (numOfIpAddresses - 1)
                Dim ipAddress As String = Console.ReadLine()
                Dim pattern As New Regex("(\d+).(\d+).(\d+).(\d+)")
                Dim match As Match = pattern.Match(ipAddress)

                Dim octal1 As Integer
                Dim octal2 As Integer
                Dim octal3 As Integer
                Dim octal4 As Integer

                If match.Success Then
                    octal1 = Integer.Parse(match.Groups(1).Value)
                    octal2 = Integer.Parse(match.Groups(2).Value)
                    octal3 = Integer.Parse(match.Groups(3).Value)
                    octal4 = Integer.Parse(match.Groups(4).Value)
                End If
                ipAddresses.Add(New Integer(3) {octal1, octal2, octal3, octal4})
            Next

            Dim all1 As New List(Of Integer)
            Dim all2 As New List(Of Integer)
            Dim all3 As New List(Of Integer)
            Dim all4 As New List(Of Integer)

            For Each ipAddress As Integer() In ipAddresses
                If (Not all1.Contains(ipAddress(0))) Then
                    all1.Add(ipAddress(0))
                End If
                If (Not all2.Contains(ipAddress(1))) Then
                    all2.Add(ipAddress(1))
                End If
                If (Not all3.Contains(ipAddress(2))) Then
                    all3.Add(ipAddress(2))
                End If
                If (Not all4.Contains(ipAddress(3))) Then
                    all4.Add(ipAddress(3))
                End If
            Next

            Dim ipRange As New StringBuilder()

            Dim cidr As Integer = 0
            ' Go Set by Set to see how similar they are.
            If (all1.Count = 1) Then
                cidr += 8
                ipRange.Append(all1(0))

                ' Move on to set 2
                If (all2.Count = 1) Then
                    cidr += 8
                    ipRange.Append(".").Append(all2(0))

                    ' Move on to set 3
                    If (all3.Count = 1) Then
                        cidr += 8
                        ipRange.Append(".").Append(all3(0))

                        ' Move on to set 4
                        If (all4.Count = 1) Then
                            cidr += 8
                            ipRange.Append(".").Append(all4(0))

                        ElseIf (all4.Count > 1) Then
                            ' Gotta calculate how similar they are
                            For j As Integer = 1 To 8
                                Dim shift As New List(Of Integer)
                                For Each octal As Integer In all4
                                    Dim x As Integer = (octal >> j << j)
                                    If (Not shift.Contains(x)) Then
                                        shift.Add(x) ' clear out j bits
                                    End If
                                Next
                                If shift.Count = 1 Then
                                    cidr += (8 - j)
                                    ipRange.Append(".").Append(shift(0))
                                    Exit For
                                End If
                            Next
                        End If
                    ElseIf (all3.Count > 1) Then
                        ' Gotta calculate how similar they are
                        For j As Integer = 1 To 8
                            Dim shift As New List(Of Integer)
                            For Each octal As Integer In all3
                                Dim x As Integer = (octal >> j << j)
                                If (Not shift.Contains(x)) Then
                                    shift.Add(x) ' clear out j bits
                                End If
                            Next
                            If shift.Count = 1 Then
                                cidr += (8 - j)
                                ipRange.Append(".").Append(shift(0)).Append(".0")
                                Exit For
                            End If
                        Next
                    End If
                ElseIf (all2.Count > 1) Then
                    ' Gotta calculate how similar they are
                    For j As Integer = 1 To 8
                        Dim shift As New List(Of Integer)
                        For Each octal As Integer In all2
                            Dim x As Integer = (octal >> j << j)
                            If (Not shift.Contains(x)) Then
                                shift.Add(x) ' clear out j bits
                            End If
                        Next
                        If shift.Count = 1 Then
                            cidr += (8 - j)
                            ipRange.Append(".").Append(shift(0)).Append(".0.0")
                            Exit For
                        End If
                    Next
                End If
            ElseIf (all1.Count > 1) Then
                ' Gotta calculate how similar they are
                For j As Integer = 1 To 8
                    Dim shift As New List(Of Integer)
                    For Each octal As Integer In all1
                        Dim x As Integer = (octal >> j << j)
                        If (Not shift.Contains(x)) Then
                            shift.Add(x) ' clear out j bits
                        End If
                    Next
                    If shift.Count = 1 Then
                        cidr += (8 - j)
                        ipRange.Append(shift(0)).Append(".0.0.0")
                        Exit For
                    End If
                Next
            End If

            Console.WriteLine(String.Format("{0}/{1}", ipRange, cidr))
        Next
    End Sub

End Module
