#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>

using std::vector;

int binary_search(const vector<int> &a, int key, int low, int high) {
    // check to make sure we can haven't searched the whole array
    if (high < low)
        return -1;
    // update mid with new mid value
    int mid = low + floor((high - low) / 2);
    // if we find our key, return the index where we found it
    if (a[mid] == key)
        return mid;
    // if key is greater than current mid, then update new low to be current mid
    else if (key > a[mid])
        binary_search(a, key, mid + 1, high);
    // if key less than the value at current mid, then update new high to be the mid
    else
        binary_search(a, key, low, mid - 1);
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i], 0, a.size()) << ' ';
  }
}
