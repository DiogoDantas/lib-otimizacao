#include "../inc/mochila_fracionaria.hpp"
#include <algorithm>



// Funcao de comparacao customizada
bool cmp(gulosos::Item a, gulosos::Item b) {
    double r1 = (double)a.value_ / a.weight_;
    double r2 = (double)b.value_ / b.weight_;
    return r1 > r2;
}

double gulosos::mochila_fracionaria(int W, std::vector<Item> arr, int n) {

    std::sort(arr.begin(), arr.end(), cmp);

    int curWeight = 0;  // peso atual
    double finalvalue = 0.0; // variavel que armazena o resultado

    // todos os itens
    for (int i = 0; i < n; i++) {
        // adicionando os que cabem
        if (curWeight + arr.at(i).weight_ <= W) {
            curWeight += arr.at(i).weight_;
            finalvalue += arr.at(i).value_;
        } else {
            // adicionando a fração que cabe
            int remain = W - curWeight;
            finalvalue += arr.at(i).value_ * ((double) remain / arr.at(i).weight_);
            break;
        }
    }

    return finalvalue;
}
