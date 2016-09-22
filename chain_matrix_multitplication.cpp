#include<bits/stdc++.h>
using namespace std;


int chain_matrix_multipilcation(vector<int> mat)
{
    vector<vector<int> > cmm(mat.size());

    for(int i=0;i<cmm.size();++i)
        cmm[i].resize(mat.size());

    for(int s=1;s<cmm.size();++s)
    {
        cout<<"check0\n";
        for(int i=1,j=s+1;i<cmm.size() && j<cmm.size();++i,++j)
        {
            int product=-1;
            for(int k=i+1;k<=j;++k)
            {
                int temp = cmm[i][k]+cmm[k+1][j]+mat[i-1]*mat[k]*mat[j];
                if(product==-1)
                    product=cmm[i][k]+cmm[k+1][j]+mat[i-1]*mat[k]*mat[j];
                else if(temp<product)
                    product=temp;
            }
            cmm[i][j]=product;

            for(auto &v:cmm)
            {
                for(auto &x:v)
                    cout<<x<<"\t";
                cout<<"\n";
            }
        }
    }
    cout<<"check1\n";
    for(auto &v:cmm)
    {
        for(auto &x:v)
            cout<<x<<"\t";
        cout<<"\n";
    }
    cout<<"check2";
    return cmm[0][cmm.size()-1];
}


int main()
{
    int mat[]={3,2,5,1};
    cout<<chain_matrix_multipilcation(vector<int>(mat,mat+4));
    return 0;
}
