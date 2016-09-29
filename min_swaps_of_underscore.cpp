/*
There is a string whose characters can only be either ‘a’, ‘b’ or ‘_’ (there can be only one ‘_’ in the string). At each step, we can modify the string as follows: 1. ‘_’ can be swapped with its adjacent character, example “a_ba” can be changed to either “_aba” or “ab_a”. 2. Two characters adjacent to ‘_’ (both on the same side of ‘_’) can be reversed along with the ‘_’ if both characters are different, example, “aa_ba” can be changed to “aaab_” but not to “_aaba” because both characters are ‘a’. You are given two strings, the initial state and the final state (lengths will be same), you have to output the minimum number of steps required to change the string in initial state to the string in the final state. example: input: a_b ab_ output: 1 input: abaa_a b_aaaa output: 4 reason for example 2:- abaa_a -> aba_aa -> ab_aaa -> _baaaa -> b_aaaa
*/

#include <bits/stdc++.h>

using namespace std;

int min_swaps(string src,string dst)
{
    if(dst.size()!=src.size())
        return -1;
    queue<pair<string,int> > bfs;
    set<string> visited;
    int min_edits=0;

    visited.insert(src);
    bfs.push(pair<string,int>(src,0));

    while (!bfs.empty())
    {
        pair<string,int> curr = bfs.front();
        bfs.pop();

        if(curr.first==dst)
            return curr.second;


        string str = curr.first;
        for(int i=0;i<str.size();++i)
        {
            if(str[i]=='_')
            {

                if(i+1<str.size())
                {
                    swap(str[i],str[i+1]);
                    if(visited.find(str)==visited.end())
                        bfs.push(pair<string,int>(str,curr.second+1));
                    swap(str[i],str[i+1]);
                }
                if(i+2<str.size() && str[i+1]!=str[i+2])
                {
                    swap(str[i],str[i+2]);
                    if(visited.find(str)==visited.end())
                        bfs.push(pair<string,int>(str,curr.second+1));
                    swap(str[i],str[i+2]);
                }

                if(i-1>=0)
                {
                    swap(str[i],str[i-1]);
                    if(visited.find(str)==visited.end())
                        bfs.push(pair<string,int>(str,curr.second+1));
                    swap(str[i],str[i-1]);
                }
                if(i-2>=0 && str[i-1]!=str[i-2])
                {
                    swap(str[i],str[i-2]);
                    if(visited.find(str)==visited.end())
                        bfs.push(pair<string,int>(str,curr.second+1));
                    swap(str[i],str[i-2]);
                }
            }
        }
    }
    return min_edits;
}


int main()
{
    string a,b;
    cin>>a>>b;
    cout<<min_swaps(a,b);
    return 0;
}
