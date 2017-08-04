#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

void bubble_sort_desc(vector<int> &a) {
    int n = a.size();
    int temp = 0, swap = 1;
    while (swap > 0) {
        swap = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] < a[i + 1]) {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap++;
            }
        }
    }
}

long long dot_product(vector<int> a, vector<int> b) {
    long long result = 0;

    // Sort both vectors by descending order
    bubble_sort_desc(a);
    bubble_sort_desc(b);

    for (size_t i = 0; i < a.size(); i++)
        result += (long long)a[i] * b[i];

    return result;
}

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  // std::cout << max_dot_product(a, b) << std::endl;
  std::cout << dot_product(a, b) << std::endl;
}
