#ifndef MOCHILA_FRA_H_
#define  MOCHILA_FRA_H_
#include <vector>

namespace gulosos {
    struct Item {
        int value_, weight_;


        Item(int value, int weight) {
                value_ = value;
                weight_ = weight;
        }
    };

    double mochila_fracionaria(int W, std::vector<Item> arr, int n);
}
#endif
