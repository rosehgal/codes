#include <bits/stdc++.h>

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

string num_to_string(int num)
{
    string result;
    while(num)
    {
        result=(char)(num%10+'0')+result;
        num=num/10;
    }
    return result;
}

string list_to_string(list<int> l)
{
    string res;
    for(auto s:l)
        res+=s+'0';
    return res;
}

list<int> factorial(int number)
{
    if(number<=1)
        return list<int>{1};
    else
    {
        string f=num_to_string(number);
        string s=list_to_string(factorial(number-1));
        if(f.size()>s.size())
            swap(f,s);
        return multiply(f,s);
    }
}

int main()
{
    int number;
    cin>>number;

    for(auto a:factorial(number))
        cout<<a;

    return 0;
}
