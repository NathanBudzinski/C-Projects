
class Fib
{

    public static int Fibonacci(int n)
    {
        int[] M = new int[n];
        return Fibonacci_Recursive(n-1, M) + Fibonacci_Recursive(n-2, M);
    }

    public static int Fibonacci_Recursive(int n, int[] M)
    {
        if (M[n] > 0) return M[n];
        if (n == 1 || n == 2) return 1;
        return M[n] = Fibonacci_Recursive(n - 1, M) + Fibonacci_Recursive(n - 2, M);
    }



    public static void Main()
    {
        Console.WriteLine("Calculate Fibonacci number: ");
        int fib = Convert.ToInt32(Console.ReadLine());
        int result = Fibonacci(fib);
        Console.WriteLine("The Fibonacci number F(" +  fib + ") = " + result);
    }
}