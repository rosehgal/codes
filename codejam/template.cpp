#include <iostream>
#include <list>
#include <stack>
#include <fstream>
using namespace std;

class Graph
{
    int nodes;
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

public:
    Graph(int nodes)
    {
        this->nodes = nodes;
        adj = new list<int>[nodes];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void topologicalSort()
    {
        stack<int> Stack;
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        for (int i = 0; i < V; i++)
          if (visited[i] == false)
            topologicalSorthelper(i, visited, Stack);

        while (Stack.empty() == false)
        {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }
};



int main()
{
    ifstream file;
    file.open("sampleinput.in",ios::in);

    int testcases;
    file>>testcases;
    while(testcases)
    {
        testcases--;
        int r,c,k,x,y;
        int **mat=new int*[r];
        for(int i=0;i<r;++i)
            mat[i]=new int[c];

        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                mat[i][j]=0;

        file>>r>>c>>k;
        while(k--)
        {
            file>>x>>y;
            mat[x][y]=1;
        }

        int **dp = get_dp_mat(mat,r,c);
    }
    file.close();
    return 0;
}
