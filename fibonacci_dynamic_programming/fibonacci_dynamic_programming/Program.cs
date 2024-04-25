class Fib
{
    public static double Fibonacci(double n)
    {
        if (n == 1 || n == 2) return 1;
        double[] M = new double[(int)n];
        return Fibonacci_Recursive(n-1, M) + Fibonacci_Recursive(n-2, M);
    }
    public static double Fibonacci_Recursive(double n, double[] M)
    {
        if (M[(int)n] > 0) return M[(int)n];
        if (n == 1 || n == 2) return 1;
        return M[(int)n] = Fibonacci_Recursive(n - 1, M) + Fibonacci_Recursive(n - 2, M);
    }
    public static void Main()
    {
        Console.WriteLine("Calculate Fibonacci number: ");
        double fib = Convert.ToDouble(Console.ReadLine());
        double result = Fibonacci(fib);
        Console.WriteLine("The Fibonacci number F(" +  fib + ") = " + result);
    }
}
