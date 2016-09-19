#include <iostream>
#include <list>
#include <string.h>
#include <string>
#include <unordered_map>
#include <stack>
#include <vector>
#include <fstream>
using namespace std;


vector<string> split(const char *str, char c = ' ')
{
    vector<string> result;

    do
    {
        const char *begin = str;

        while(*str != c && *str)
            str++;

        result.push_back(string(begin, str));
    } while (0 != *str++);

    return result;
}



vector<string> parse(string str)
{
    int found = str.find("=");
    vector<string> ret;

    string before = str.substr(0,found);
    string after = str.substr(found+1);
    cout<<before<<"\n";
    cout<<after<<"\n";

    size_t first = after.find("(");
    size_t last = after.find(")");
    ret.push_back(before);

    if(first!=string::npos && last!=string::npos)
    {
        string expr = after.substr(first+1);
        expr = expr.substr(0,expr.length()-1);

        //cout<<expr<<endl;

         vector<string> result= split(expr.c_str(),',');
         for(auto s : result)
            ret.push_back(s);
    }

    else
    {
        // cout<<"else";
        char* s = (char*)after.c_str();
        char* p = strtok(s, "+-*/");
        while (p != NULL)
        {
            string s(p);
            p = strtok(NULL, "+-*/");
            cout<<s;
            ret.push_back(s);
        }
    }
    return ret;
}



class Graph
{
    public:
    int nodes;
    int strtonodecounter;
    unordered_map<string,int> strtonode;

    list<int> *adj;

    void topologicalSorthelper(int v, bool visited[], stack<int> &Stack)
    {
        visited[v] = true;
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                topologicalSorthelper(*i, visited, Stack);
        Stack.push(v);
    }


    Graph(int nodes)
    {
        this->nodes = nodes;
        strtonodecounter=0;
        adj = new list<int>[nodes];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void topologicalSort()
    {
        stack<int> Stack;
        bool *visited = new bool[nodes];
        for (int i = 0; i < nodes; i++)
            visited[i] = false;

        for (int i = 0; i < nodes; i++)
          if (visited[i] == false)
            topologicalSorthelper(i, visited, Stack);

        while (Stack.empty() == false)
        {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }

    void update(vector<string> str)
    {
        for(auto s:str)
            if(strtonode.count(s)<=0)
                strtonode[s]=strtonodecounter++;
    }

    int getnode(string str)
    {
        return strtonode[str];
    }

    void addToGraph(string str)
    {
        vector<string> n = parse(str);
        update(n);
        for(int i=1;i<n.size();++i)
            this->addEdge(getnode(n[0]),getnode(n[i]));
    }
};



int main()
{
    ifstream file;
    file.open("sampleinput.in",ios::in);
    ofstream ofile;
    ofile.open("C1.in",ios::out);

    int testcases,curr=1;
    file>>testcases;
    while(curr<=testcases)
    {
        int n;
        file>>n;
        string str;
        Graph g(n);

        while(n--)
        {
            file>>str;
            g.addToGraph(str);
        }

        g.topologicalSort();
        curr++;
    }
    file.close();
    return 0;
}
