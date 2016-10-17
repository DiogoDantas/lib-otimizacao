#include"../inc/matrix_chain_mult.hpp"
#include<limits.h>


int dynamic::matrix_chain_mult(int p[], int n)
{

    //primeira linha e coluna não serão utilizadas
    int m[n][n];

    //custo zero para multiplicar uma matriz
    for (int i=1; i<n; i++)
        m[i][i] = 0;

    //L é o tamanho da cadeia
    for (int L=2; L<n; L++)
    {
        for (int i=1; i<n-L+1; i++)
        {
            int j = i+L-1;
            m[i][j] = INT_MAX;
            for (int k=i; k<=j-1; k++)
            {

                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n-1];
}
