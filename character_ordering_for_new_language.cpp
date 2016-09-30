/*
In a certain language which has same alphabets as in english language (ie. a-z), but the order of the alphabets is different (for eg 's' is the first character, 'g' is second, and likewise). Given a dictionary of this new language (which has words arranged according to new alphabetical order), FInd out the order of alphabets in this language.
*/

#include <bits/stdc++.h>

using namespace std;

pair<list<int>*,int> create_graph(vector<string> strings,vector<int> &indegree)
{
    for(auto str:strings)
        for(auto s:str)
            indegree[s-'a']=0;

    list<int>* graph = new list<int>[26];

    for(int i=0;i<strings.size();++i)
        for(int j=i+1;j<strings.size();++j)
            {
                for(int k=0,l=0;k<strings[i].size() && l<strings[j].size();++k,++l)
                {

                    if(strings[i][k]!=strings[j][l])
                    {
                        graph[strings[i][k]-'a'].push_back(strings[j][l]-'a');
                        indegree[strings[j][l]-'a']++;
                        break;
                    }
                }
            }
    return pair<list<int>*,int>(graph,26);
}

int indegree_next_zero(vector<int> &indegree)
{
    for(int i=0;i<indegree.size();++i)
        if(indegree[i]==0)
        {
            indegree[i]--;
            return i;
        }
    return indegree.size();
}

vector<int> topological_sort(pair<list<int>*,int> graph,vector<int> &indegree)
{
    list<int>* g = graph.first;
    int size=graph.second;
    int nextzero;
    std::vector<int> toposort;
    while((nextzero=indegree_next_zero(indegree)) != size)
    {
        toposort.push_back(nextzero);
        for(auto node : g[nextzero])
            indegree[node]--;
    }
    return toposort;
}

int main()
{
    vector<string> strings;
    string str;int n;
    cin>>n;
    while(n--)
    {
        cin>>str;
        strings.push_back(str);
    }

    vector<int> indegree(26,-1);
    pair<list<int>*,int> graph = create_graph(strings,indegree);
    //
    // for(int i=0;i<graph.second;++i)
    // {
    //     for(auto a:graph.first[i])
    //         cout<<(char)(i+'a')<<"-->"<<(char)(a+'a')<<endl;
    // }
    //
    // for(int i=0;i<indegree.size();++i)
    //     cout<<(char)(i+'a')<<" "<<indegree[i]<<endl;

    vector<int> toposort = topological_sort(graph,indegree);
    cout<<"\nRequired Ordering ";
    for(auto t:toposort)
        cout<<(char)(t+'a')<<" ";
    cout<<endl;
    return 0;
}
