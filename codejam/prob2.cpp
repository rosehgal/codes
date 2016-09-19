#include <iostream>
#include <algorithm>
#include <stdio.h>

int **sum;

void matrixdp(int **matrix,int r ,int c)
{
    sum = new int*[r];
    for(int i=0;i<r;++i)
        *(sum+i)=new int[c];

    for(int i=0;i<r;++i)
        sum[i][0]=matrix[i][0];

    for(int i=0;i<c;++i)
        sum[0][i]=matrix[0][i];

    for(int i=1; i < r; i++)
    {
        for(int j=1; j < c; j++)
        {
            if(matrix[i][j] == 1)
                sum[i][j] = std::min(std::min(sum[i][j-1], sum[i-1][j]),sum[i-1][j-1]) + 1;
            else
                sum[i][j] = 0;
        }
    }
}


int main()
{
    stdin = fopen("B-large.in","r");
    stdout = fopen("B2.in","w");

    int t,abhi=1;
    scanf("%d",&t);

    while(abhi<=t)
    {

        int row,col,k,x,y;
        int total=0;
        scanf("%d%d%d",&row,&col,&k);

        int **matrix;
        matrix = new int*[row];
        for(int i=0;i<row;++i)
            *(matrix+i)=new int[col];

        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j)
                matrix[i][j]=1;

        while(k--)
        {
            scanf("%d%d",&x,&y);
            matrix[x][y]=0;
        }

        matrixdp(matrix,row,col);
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
                total+=sum[i][j];
        }
        printf("Case #%d: %d",abhi,total);
        abhi++;
    }
    return 0;
}
