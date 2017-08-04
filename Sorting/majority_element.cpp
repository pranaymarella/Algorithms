#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

int majority_element(vector<long long> &a) {
    std::unordered_map<long long, int> hashtable;
    for (int i = 0; i < a.size(); i++) {
        if (hashtable.find(a[i]) != hashtable.end()) {
            hashtable[a[i]]++;
            if (hashtable[a[i]] > (a.size() / 2))
                return 1;
        } else
            hashtable.insert(std::make_pair(a[i], 1));
    }
    return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << majority_element(a) << std::endl;
}
