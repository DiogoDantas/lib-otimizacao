#ifndef FRACTIONAL_KNAPSACK
#define  FRACTIONAL_KNAPSACK
#include <vector>

namespace greedy {
    struct Item {
        int value_, weight_;


        Item(int value, int weight) {
                value_ = value;
                weight_ = weight;
        }
    };

    double fractional_knapsack(int W, std::vector<Item> arr, int n);
}
#endif
