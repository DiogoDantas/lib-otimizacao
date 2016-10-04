#include "../inc/maior_subs_comum.hpp"

//max from two integers
int max(int a, int b)
   {
       return (a > b)? a : b;
   }


int dinamica::lcs( char *X, char *Y, int m, int n )
   {
      int table[m+1][n+1];
      int i, j;

      //building the table
      for (i=0; i<=m; i++)
      {
        for (j=0; j<=n; j++)
        {
          //first row and column
          if (i == 0 || j == 0)
            table[i][j] = 0;

         //if equal
          else if (X[i-1] == Y[j-1])
            table[i][j] = table[i-1][j-1] + 1;

         //if different
          else
            table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
      }

      //the last cell of the table
      return table[m][n];
   }
