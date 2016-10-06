#include<bits/stdc++.h>
using namespace std;


list<int> add(list<int> a,list<int> b)
{
    list<int>::iterator i,j;
    list<int> result;
    int carry=0;

    for(i=a.begin(),j=b.begin();i!=a.end() && j!=b.end();++i,++j)
    {
        int current = *i + *j + carry;
        result.push_back(current%10);
        carry = current / 10;
        //cout<<current<<endl;
    }
    if(i!=a.end() && j==b.end())
        while(i!=a.end())
        {
            int current = *i + carry;
            result.push_back(current%10);
            carry = current / 10;
            i++;
        }
    else
        if(j!=b.end() && i==a.end())
            while (j!=b.end())
            {
                int current = *j + carry;
                result.push_back(current%10);
                carry = current / 10;
                ++j;
            }

    if(carry)
        result.push_back(carry);
    return result;
}

list<int> multiply(string a,string b)
{
    int carry=0,count=0;
    list<int> prevresult{0},currentresult;
    for(int i=a.size()-1;i>=0;--i)
    {
        currentresult.clear();
        carry=0;
        for(int k=0;k<count;++k)
            currentresult.push_back(0);
        for(int j=b.size()-1;j>=0;--j)
        {
            int current = (a[i]-'0')*(b[j]-'0')+carry;
            currentresult.push_back(current%10);
            carry = current/10;
        }
        if(carry)
            currentresult.push_back(carry);
        prevresult=add(currentresult,prevresult);
        count++;
    }
    prevresult.reverse();
    return prevresult;
}



int main()
{
    // list<int> a{1,2,3,4,5,6,7,8},b{9,8,5,3,5,1};
    string a,b;
    cin>>a>>b;
    list<int> result;
    if(a.size()>b.size())
        swap(a,b);

    for(auto result : multiply(a,b))
        cout<<result;

    return 0;
}
