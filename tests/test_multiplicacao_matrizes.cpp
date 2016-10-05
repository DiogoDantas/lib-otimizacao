#include <iostream>
#include "../inc/multiplicacao_matrizes.hpp"

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

        std::cout << "Minimum number of multiplications is "<< dinamica::multiplicacao_matrizes(arr, nmatrix+1)<<std::endl;

    }


    return 0;
}
