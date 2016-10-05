#include <bits/stdc++.h>

using namespace std;

int rand5()
{
    srand(time(0));
    return rand()%5+1;
}

int rand25()
{
    unordered_map<int,int> randmap;
    int count=1;
    for(int i=1;i<=5;++i)
        for(int j=1;j<=5;++j)
            randmap[i*j]=count++;
    return randmap[rand5()*rand5()];
}

int rand21()
{
    int temp = rand25();
    if(temp<=21)
        return temp;
    else
        return rand21();
}

int rand7()
{
    return rand21()%7+1;
}

int main()
{
    cout<<rand7();
}
