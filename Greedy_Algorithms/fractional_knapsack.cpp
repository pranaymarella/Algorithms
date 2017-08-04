#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    // Get size of the vector
    int n = weights.size();
    int swap = 1, temp = 0;
    double temp_one = 0.0, temp_two = 0.0;

    // sort the weights and values from highest to lowest (in terms of value per weight)
    while (swap > 0) {
        swap = 0;
        for (int i = 0; i < n; i++) {
            // hold current index's fraction of value per weight
            temp_one = (double)values[i] / weights[i];
            // hold next index's fraction of value per weight
            temp_two = (double)values[i+1] / weights[i+1];
            // if the next index has a higher value per weight, switch index's
            if (temp_one < temp_two) {
                // swap the values
                temp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temp;
                // swap the weights
                temp = weights[i];
                weights[i] = weights[i+1];
                weights[i + 1] = temp;
                swap++;
            }
        }
    }

    temp = 0;
    // used for looping through vector
    int i = 0;
    // make sure current index of vector exists (we didnt reach past end of vector)
    // Also make sure capacity is not full yet
    while (capacity > 0 && weights[i]) {
        temp = capacity - weights[i];
        // if we have not filled up to capacity
        if (temp > 0) {
            // add the value of the current index (already sorted highest to lowest)
            value += values[i];
            // Decrease capacity because we added the item to bag
            capacity -= weights[i];
            // move onto next index
            i++;
        }
        // if the current items weight is more than our bag can handle
        else {
            // fill up rest of the bag with the current item
            value += values[i] * ((double)capacity / weights[i]);
            // now capacity is zero because we fille up our bag fully
            capacity = 0;
        }
    }
    return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
