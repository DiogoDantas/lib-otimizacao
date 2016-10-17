#include <iostream>
#include "../inc/matrix_chain_mult.hpp"

int main()
{
    int nproblem, nmatrix;
    std::cin >> nproblem;

    for (int i = 0; i < nproblem; i++) {
        std::cin >> nmatrix;

        int arr[nmatrix+1];

        for (int i = 0; i < nmatrix; i++) {
            int p,q;
            std::cin >> p;
            std::cin >> q;
            arr[i] = p;

            if(i==nmatrix-1)
                arr[i+1] = q;
        }

        std::cout << dynamic::matrix_chain_mult(arr, nmatrix+1)<<std::endl;

    }


    return 0;
}
