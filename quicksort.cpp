#include <iostream>
#include <cstdlib>
#include <vector>

using std::vector;
using std::swap;

int partition(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l+1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);

    return j;
}

void QuickSort(vector<int> &a, int l, int r) {
    if (l >= r)
        return;

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int m = partition(a, l, r);

    QuickSort(a, l, m - 1);
    QuickSort(a, m + 1, r);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    QuickSort(a, 0, a.size() - 1);

    std::cout << "Answer: " << std::endl;
    for (int j = 0; j < a.size(); j++)
        std::cout << a[j] << ' ';
    std::cout << '\n';
}
