#include "graph.h"
#include<iostream>
using namespace std;

Graph::Graph(int nodes)
{
    Graph::nodes = nodes;
      matrix = new int*[nodes];
    for(int i=0;i<nodes;i++)
    {
        matrix[i]= new int[nodes];
    }
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            matrix[i][j]=0;
        }
    }

}

Graph::Graph(int** adj_matrix , int nodes)
{
    Graph::nodes=nodes;
    Graph::matrix = adj_matrix;
}

Graph::~Graph()
{
 /*
  * This is required ONLY when the constructor Graph(int nodes) is called
 
   for(int i=0;i<nodes;i++)
    {
        delete[] matrix[i];
    }
    delete matrix;
*/
}

void Graph::dfs(int start)
{
    set<int> DFSNodeSet;
    for(int i=start;i<Graph::nodes;i++)
    {
      if(DFSNodeSet.find(i) == DFSNodeSet.end())
      {
        dfs(i,&DFSNodeSet);
      }
    }
}
bool Graph::set_edge(int start,int end,int weight)
{
    if(start>Graph::nodes || end > Graph::nodes || start < 0 || end < 0)
    {
        return false;
    }
    else
    {
        matrix[start][end]=1;
        return true;
    }
}

void Graph::dfs(int start, set<int> *DFSVisitedNodes)
{
    DFSVisitedNodes->insert(start);
    cout<<start<<" "<<endl;
    DFSSequences.push_back(start);
    for(int i=0;i<Graph::nodes;i++)
    {
        if(matrix[start][i] == 1 && DFSVisitedNodes->find(i) == DFSVisitedNodes->end())
        {
            dfs(i,DFSVisitedNodes);
        }
    }
}

void Graph::bfs(int start)
{
    set<int> BFSNodeSet;
    bfs(start,&BFSNodeSet);
}

void Graph::bfs(int start, set<int> *BFSVisitedNodes)
{
    Graph::BFSQueue.push(start);
    BFSVisitedNodes->insert(start);
    while(!BFSQueue.empty())
    {     
        int sourceVertex = BFSQueue.front();
        cout<<sourceVertex<<" "<<endl;
        BFSSequences.push_back(sourceVertex);
        BFSQueue.pop();
        for(int i=0;i<Graph::nodes;i++)
        {
            if(matrix[sourceVertex][i] == 1 && BFSVisitedNodes->find(i) == BFSVisitedNodes->end())
            {
                BFSVisitedNodes->insert(i);
                Graph::BFSQueue.push(i);
            }
        }

    }
}
