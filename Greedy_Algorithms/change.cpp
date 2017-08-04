#include <iostream>
#include <vector>

using std::vector;
using std::cout;


int get_change(int m) {
  //write your code here
  // keeping track of how many coins we need
  int n = 0, i = 0;
  // vector of all possible values we can use, sorted from highest to lowest
  vector<int> coins{10, 5, 1};

  // Greedy Algorithm.
  // Safe move: Check to make sure highest value can substract from 'm'
  // Keep subtracting until we need to lower to next value or we reached 0
  while (m > 0) {
      if (m >= coins[i]) {
          n++;
          m -= coins[i];
      } else if (i > 2) {
          return -1;
      } else {
          i++;
      }
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
