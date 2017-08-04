#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    // figure out size of vector
    int size = 2;
    if (n > 2)
        size = n + 1;

    // build array
    std::vector<int> fib(size);
    fib[0] = 0;
    fib[1] = 1;

    // Go through vector, adding last digit of very number to array
    for (int i = 2; i <= n; i++)
        fib[i] = (fib[i - 1] + fib[i -2]) % 10;

    return fib[n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << get_fibonacci_last_digit_fast(n) << '\n';
}
