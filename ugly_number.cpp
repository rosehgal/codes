/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
shows the first 11 ugly numbers. By convention, 1 is included.
Write a program to find and print the 150’th ugly number.
*/

#include <bits/stdc++.h>

using namespace std;

int ugly_number(int n)
{
    vector<int> ugly;
    ugly.push_back(1);
    int id2,id3,id5;id3=id2=id5=0;
    while(ugly.size()<n)
    {
        int next_ugly=min({ugly[id2]*2,ugly[id3]*3,ugly[id5]*5});
        if(next_ugly==ugly[id2]*2)
            id2++;
        if(next_ugly==ugly[id3]*3)
            id3++;
        if(next_ugly==ugly[id5]*5)
            id5++;
        ugly.push_back(next_ugly);
    }
    
    return ugly.back();
}

int main()
{
    int num;
    cin>>num;
    cout<<ugly_number(num);
    return 0;
}
