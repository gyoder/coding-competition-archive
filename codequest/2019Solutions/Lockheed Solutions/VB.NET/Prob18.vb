Option Explicit On

Module MandelbrotSet

    Public Class Complex

        Public Real As Double
        Public Imaginary As Double

        Public ReadOnly Property Magnitude() As Double
            Get
                Return Math.Sqrt(Real * Real + Imaginary * Imaginary)
            End Get
        End Property

        Public Sub New(ByVal R As Double, I As Double)
            Real = R
            Imaginary = I
        End Sub

        Public Shared Operator *(ByVal c1 As Complex, c2 As Complex)
            Dim a As Double = c1.Real * c2.Real - c1.Imaginary * c2.Imaginary
            Dim b As Double = c1.Real * c2.Imaginary + c1.Imaginary * c2.Real
            Return New Complex(a, b)
        End Operator

        Public Shared Operator +(ByVal c1 As Complex, c2 As Complex)
            Dim a As Double = c1.Real + c2.Real
            Dim b As Double = c1.Imaginary + c2.Imaginary
            Return New Complex(a, b)
        End Operator
    End Class

    Sub Main()
        Dim cases As Int32 = Console.ReadLine()
        For counter As Int32 = 0 To cases - 1
            Dim dataIn As String = Console.ReadLine()
            Dim raw_words As String() = dataIn.Split(New Char() {" "c})
            Dim values = Array.ConvertAll(raw_words, Function(str) Double.Parse(str))
            Dim a = values(0)
            Dim b = values(1)

            Dim precisionA As Integer = raw_words(0).Length - raw_words(0).IndexOf("."c) - 1
            Dim precisionB As Integer = raw_words(1).Length - raw_words(1).IndexOf("."c) - 1

            Dim c As Complex = New Complex(a, b)
            Dim Z0 As Complex = New Complex(0, 0)
            Dim Z1 As Complex = New Complex(0, 0)

            'Console.WriteLine("a, b = " + a.ToString() + ", " + b.ToString())

            Dim n As Int32 = 0
            For n = 1 To 55
                Z1 = Z1 * Z1 + c
                If (Z1.Magnitude >= 100) Then
                    Exit For
                End If
            Next
            If (n <= 10) Then
                Console.WriteLine(String.Format("{0}+{1}i", FormatNumber(c.Real, precisionA), FormatNumber(c.Imaginary, precisionB)) + " RED")
            ElseIf (n <= 20) Then
                Console.WriteLine(String.Format("{0}+{1}i", FormatNumber(c.Real, precisionA), FormatNumber(c.Imaginary, precisionB)) + " ORANGE")
            ElseIf (n <= 30) Then
                Console.WriteLine(String.Format("{0}+{1}i", FormatNumber(c.Real, precisionA), FormatNumber(c.Imaginary, precisionB)) + " YELLOW")
            ElseIf (n <= 40) Then
                Console.WriteLine(String.Format("{0}+{1}i", FormatNumber(c.Real, precisionA), FormatNumber(c.Imaginary, precisionB)) + " GREEN")
            ElseIf (n <= 50) Then
                Console.WriteLine(String.Format("{0}+{1}i", FormatNumber(c.Real, precisionA), FormatNumber(c.Imaginary, precisionB)) + " BLUE")
            Else
                Console.WriteLine(String.Format("{0}+{1}i", FormatNumber(c.Real, precisionA), FormatNumber(c.Imaginary, precisionB)) + " BLACK")
            End If
        Next
    End Sub

End Module
