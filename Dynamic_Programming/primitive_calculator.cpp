#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;


int minimize(int n, vector<int> &dynamic, vector<int> &optimal) {
    if (n <= 1) {
        return 0;
    } else if (dynamic[n] != 0) {
        // if value is memozied then return that
        return (dynamic[n]);
    } else {
        // init variables to hold minimized values
        long long r = n, rone = n, rtwo = n, rthree = n;


        if (n % 2 == 0) {
            // if the n / 2 condition gives smaller calculations
            rtwo = 1 + minimize(n / 2, dynamic, optimal);
            r = std::min(r, rtwo);
            // switch the optimal
            if (r == rtwo)
                optimal[n] = n / 2;
        }
        if (n % 3 == 0) {
            // if the n / 3 condition gives smaller calculations
            rthree = 1 + minimize(n / 3, dynamic, optimal);
            r = std::min(r, rthree);
            // switch the optimal
            if (r == rthree)
                optimal[n] = n / 3;
        }
        if (n % 2 != 0 || n % 3 != 0) {
            // start with n - 1 condition
            rone = 1 + minimize(n - 1, dynamic, optimal);
            r = std::min(r, rone);
            // switch the optimal
            if (r == rone)
                optimal[n] = n - 1;
        }

        // store calculation for future
        dynamic[n] = r;
        // return min calculation
        return r;
    }
}


int main() {
    int n;
    std::cin >> n;
    vector<int> dynamic(n + 1);
    vector<int> optimal(n + 1);
    int output = minimize(n, dynamic, optimal);
    std::cout << output << std::endl;
    int temp = n;
    vector<int> temp_vect(output);
    while (temp >= 1) {
        temp_vect.push_back(temp);
        temp = optimal[temp];
    }
    for (int i = temp_vect.size() - 1; temp_vect[i] > 0; i--) {
        std::cout << temp_vect[i] << ' ';
    }
    std::cout << '\n';
}
