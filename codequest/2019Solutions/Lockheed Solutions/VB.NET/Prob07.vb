Option Explicit On
Module Prob07
    Sub Main()
        Dim cases As Int32 = Console.ReadLine()
        For counter As Int32 = 0 To cases - 1
            Dim lines As Int32 = Console.ReadLine().Trim()
            Dim colorMin As Double = 999999.0
            Dim colorMax As Double = 0.0
            Dim colors(lines - 1) As Double
            For line As Int32 = 0 To lines - 1
                Dim color As Double = Console.ReadLine().Trim()
                colors(line) = color
                colorMin = Math.Min(color, colorMin)
                colorMax = Math.Max(color, colorMax)
            Next

            For Each color As Double In colors
                Console.WriteLine(Math.Round((color - colorMin) / (colorMax - colorMin) * 255.0))
            Next
        Next

    End Sub

End Module
