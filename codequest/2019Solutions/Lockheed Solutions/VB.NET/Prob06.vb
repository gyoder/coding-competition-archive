Option Explicit On
Module Prob06

    Sub Main()
        Static Dim Circ As Double = 40075.0
        Dim cases As Int32 = Console.ReadLine()
        For counter As Int32 = 0 To cases - 1
            Dim N1 As Int32 = Console.ReadLine()
            Dim C2 As Double = Math.Round(Circ + Math.PI * N1 * 2, 1)
            Console.WriteLine(FormatNumber(C2, 1, TriState.UseDefault, TriState.UseDefault, TriState.False))
        Next
    End Sub

End Module
