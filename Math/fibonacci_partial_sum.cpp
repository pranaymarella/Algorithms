#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long m, long long n) {
    // build array
    std::vector<long long> fib(60);
    fib[0] = 0;
    fib[1] = 1;

    // Go through vector, adding last digit of very number to array
    for (long long i = 2; i < 60; i++)
        fib[i] = (fib[i - 1] + fib[i -2]);

    return (((fib[(n + 2) % 60] - 1) - (fib[(m + 1) % 60] - 1)) % 10);
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
