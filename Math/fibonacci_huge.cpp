#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int pisano(long long n, long long m) {
    int i = 2;
    std::vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);

    while (true) {
        fib.push_back((fib[i - 1] + fib[i - 2]) % m);
        if (fib[i] == 1 && fib[i - 1] == 0) {
            break;
        }
        i++;
    }

    int length = i - 1;
    return (fib[n % length]);
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << pisano(n, m) << '\n';
    return 0;
}
