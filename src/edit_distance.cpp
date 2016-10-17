#include "../inc/edit_distance.hpp"
#include <algorithm>

int min(int x, int y, int z)
{
    return std::min(std::min(x,y), z);
}


int dynamic::edit_distance(std::string str1, std::string str2, int m, int n)
{
    // Tabela que armazena os subproblemas
    int dp[m+1][n+1];

    //bottom-up
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            //Se a primeira string está vazia
            if (i==0)
                dp[i][j] = j;

            //Se a segunda string está vazia
            else if (j==0)
                dp[i][j] = i;

            //Se os caracteres são iguais
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];

            //Se os caracteres são iguais é considerado todas as possibilidades usando a função min
            else
                dp[i][j] = 1 + min(dp[i][j-1],
                                   dp[i-1][j],
                                   dp[i-1][j-1]);
        }
    }

    return dp[m][n];
}
