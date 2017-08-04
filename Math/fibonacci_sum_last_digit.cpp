#include <iostream>
#include <vector>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long get_fibonacci_last_digit_fast(long long n) {
    // build array
    std::vector<long long> fib(60);
    fib[0] = 0;
    fib[1] = 1;

    // Go through vector, adding last digit of very number to array
    for (long long i = 2; i < 60; i++)
        fib[i] = (fib[i - 1] + fib[i -2]) % 10;

    if (fib[n % 60] == 0)
        return 10;
    else
        return fib[n % 60];
}

int fibonacci_sum_fast(long long n) {
    return ((get_fibonacci_last_digit_fast(n + 2) - 1) % 10);
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n) << '\n';
}
