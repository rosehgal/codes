#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> matrix_multiply(vector<vector<int>> mat1,vector<vector<int>> mat2)
{
    vector<vector<int>> mat(mat1.size(),vector<int>(mat2.size()));
    if(mat1[0].size() != mat2.size())
        return mat;

    for(int i=0;i<mat1.size();++i)
        for(int j=0;j<mat2.size();++j)
        {
            int sum=0;
            for(int k=0;k<mat2.size();++k)
                sum+=mat1[i][k]*mat2[k][j];
            mat[i][j]=sum;
        }

    return mat;
}




vector<vector<int>> mat_mul(vector<vector<int>> mat,int n)
{
    //cout<<n<<endl;
    if(n==0)
        return vector<vector<int>>{{1,1},{1,1}};
    if(n==1)
        return mat;
    if(n==2)
        return matrix_multiply(mat,mat);

    vector<vector<int>> smaller_mat = mat_mul(mat,n/2);
    if(n%2==1)
        return matrix_multiply(matrix_multiply(smaller_mat,smaller_mat),mat);

    return matrix_multiply(smaller_mat,smaller_mat);
}

vector<vector<int>> nthFibo(int n)
{
    vector<vector<int>> fib{{1,1},{1,0}},base{{1},{0}};
    vector<vector<int>> prod1 = mat_mul(fib,n);
    vector<vector<int>> prod2 = matrix_multiply(prod1,base);
    return prod2;
}

int main()
{
    int n;
    cin>>n;
    //call fib for n-1
    vector<vector<int>> result  = nthFibo(n-1);
    cout<<result[0][0];
    return 0;
}
