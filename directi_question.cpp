/*
You are given two strings, say A and B, of the same length, say N. You can swap A[i] and B[i] for all i between 1 and N, inclusive. You cannot swap two characters within A, or within B. Also, you can only swap a character in A with the character at the same index in B, and with no other character. You can perform this operation zero or more times.
You wish to modify the strings through the operations in such a way that the number of unique characters in the strings is small. In fact if n(A) is the number of unique characters in A and n(B) is the number of unique characters in B; you wish to perform the operations such that max(n(A),n(B)) is as small as possible.
Print the value of max(n(A),n(B)) after all the operations.
*/
#include <bits/stdc++.h>

using namespace std;

int swap_count(string a,string b)
{
    unordered_map<char,int> first,second;
    for(char &s:a)
        if(first.count(s)<=0)
            first[s]=1;
        else
            first[s]++;

    for(auto s:b)
        if(second.count(s)<=0)
            second[s]=1;
        else
            second[s]++;

    for(int i=0;i<a.size();++i)
    {
        if(first.count(b[i])>0 && second.count(a[i])>0 && a[i]!=b[i]  && first.count(a[i])>=second.count(a[i]) && second.count(b[i])>=first.count(b[i]))
        {
            cout<<"A[i]=="<<a[i];
            swap(a[i],b[i]);
            first[b[i]]++;
            second[b[i]]--;
            second[a[i]]++;
            first[a[i]]--;
        }
    }

    int count1=0,count2=0;
    for(auto a:first)
        if(a.second)
            count1++;
    for(auto a:second)
        if(a.second)
            count2++;
    return max(count1,count2);
}


int main()
{
    string a,b;
    cin>>a>>b;
    cout<<swap_count(a,b);
    return 0;
}
