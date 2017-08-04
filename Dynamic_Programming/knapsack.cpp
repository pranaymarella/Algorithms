#include <iostream>
#include <vector>

using std::vector;

// creates a 2d vector
vector<vector<int>> initalize_knapsack(vector<int> &bars, int capacity) {
    vector<vector<int>> value(bars.size()+1);

    for (int i = 0; i < bars.size() + 1; i++) {
        vector<int> row(capacity + 1);
        value[i] = row;
    }

    return value;
}

// Dynamic Programming method to get optimal weight of knapsack with no repetitions (limited quantity)
int knapsack(vector<int> &bars, int capacity) {
    // Get 2D vector to hold values
    vector<vector<int>> value = initalize_knapsack(bars, capacity);
    // total items we can use from 0 items up to n items
    int n = bars.size() + 1;
    int val = 0;

    // for each item that we are able to use 1 up to n
    for (int i = 1; i < n; i++) {
        // for each weight that we can hold
        for (int w = 1; w < capacity + 1; w++) {
            // default
            value[i][w] = value[i-1][w];
            // split to subproblem and check
            if (bars[i-1] <= w)
                value[i][w] = std::max(value[i-1][w], value[i-1][w-bars[i-1]] + bars[i-1]);
        }
    }

    // return optimal weight with our given capacity
    return value[n-1][capacity];
}

int main() {
    int n, capacity;
    std::cin >> capacity >> n;
    vector<int> bars(n);
    for (int i = 0; i < n; i++) {
        std::cin >> bars[i];
    }

    std::cout << knapsack(bars, capacity) << std::endl;
}
