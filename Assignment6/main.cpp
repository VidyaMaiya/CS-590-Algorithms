#include "graph.h"
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

bool testDFS(vector<int> DFSSequence)
{
    //The possible DFS Sequences for source vertex 0
    vector<int> outputSequence1;
    outputSequence1.push_back(0);
    outputSequence1.push_back(1);
    outputSequence1.push_back(4);
    outputSequence1.push_back(2);
    outputSequence1.push_back(7);
    outputSequence1.push_back(6);
    outputSequence1.push_back(5);
    outputSequence1.push_back(3);
    outputSequence1.push_back(8);

    if(outputSequence1.size() == DFSSequence.size())
    {
        return equal(outputSequence1.begin(), outputSequence1.end(), DFSSequence.begin());
    }
    else
    {
        return false;
    }

}
bool testBFS(vector<int> BFSSequence)
{
    //The possible BFS Sequences for source vertex 0
    vector<int> outputSequence2;
    outputSequence2.push_back(0);
    outputSequence2.push_back(1);
    outputSequence2.push_back(3);
    outputSequence2.push_back(4);
    outputSequence2.push_back(6);
    outputSequence2.push_back(2);
    outputSequence2.push_back(7);
    outputSequence2.push_back(5);
    outputSequence2.push_back(8);

    if(outputSequence2.size() == BFSSequence.size())
    {
        return equal(outputSequence2.begin(), outputSequence2.end(), BFSSequence.begin());
    }
    else
    {
        return false;
    }
}
int main()
{
    int nodes;
    cout<<"Enter number of nodes: "<<endl;
    cin>>nodes;

    /*
     * Declare the adjacency matrix array
     * BELOW CODE MUST BE COMMENTED OUT WHEN THE CONSTRUCTOR Graph graph = Graph(nodes) is called
     * 
    */
    int **adj_matrix = new int*[nodes];
    for(int i=0;i<nodes;i++)
    {
        adj_matrix[i]= new int[nodes];
    }
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            adj_matrix[i][j]=0;
        }
    }

   /*
    * Input Adjacency matrix for the nodes 0,1,2,3,4,5,6,7,8
      0 1 0 1 0 0 0 0 0
      0 0 0 0 1 0 0 0 0
      0 1 0 0 0 0 0 0 0
      0 0 0 0 1 0 1 0 0 
      0 0 1 0 0 0 0 1 0
      0 0 0 1 0 0 0 0 0
      0 0 0 0 0 1 0 1 1
      0 0 0 0 0 0 1 0 0
      0 0 0 0 0 0 0 1 0
    
    BELOW USER INPUT CODE MUST BE COMMENTED OUT WHEN THE CONSTRUCTOR Graph graph = Graph(nodes) is called
  */
    cout<<"Enter adjacency matrix"<<endl;
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            cin>>adj_matrix[i][j];
        }
    }
    
   Graph graph = Graph(adj_matrix, nodes);

/* Setting the edges for the nodes 0,1,2,3,4,5,6,7,8
   Graph graph = Graph(nodes);
   bool isSet=true;
   int start,end;
/* Input edges are as follows:
   set_edge(0,1,0);
   set_edge(0,3,0);  
   set_edge(1,4,0);
   set_edge(2,1,0);
   set_edge(3,4,0);
   set_edge(3,6,0);
   set_edge(4,2,0);
   set_edge(4,7,0);
   set_edge(5,3,0);
   set_edge(6,5,0);
   set_edge(6,7,0);
   set_edge(6,8,0);
   set_edge(7,6,0);
   set_edge(10,7,0);
   set_edge(-1,7,0);

   while(isSet)
   {
       cout<<"Enter the start vertex of the edge"<<endl;
       cin>>start;
       cout<<"Enter the end vertex of the edge"<<endl;
       cin>>end;
       if(graph.set_edge(start,end,0))
       {
           cout<<"Edge is successfully set"<<endl;
       }
       else
       {
           //Enter the incorrect value for edge to terminate the while loop
           cout<<"Could not set the edge"<<endl;
           isSet=false;
       }
   }
*/ 
   int choice;
   cout<<"Enter your choice of algorithm : "<<endl;
   cout<<"1.BFS "<<endl;
   cout<<"2.DFS "<<endl;
   cin>>choice;
   switch(choice)
   {
     case 1: cout<<"BFS Sequences are "<<endl;
             /*
              * Call BFS for the source vertex 0
              *
             */
             graph.bfs(0);
             /*
              * Check if the BFS Sequence is correct
              *
             */
             if(testBFS(graph.BFSSequences))
             {
               cout<<"The generated BFS Sequence for the given graph is correct!"<<endl;
             }
             else
             {
               cout<<"The generated BFS Sequence for the given graph is wrong!"<<endl;
             }

             break;
     case 2: cout<<"DFS sequences are "<<endl;
             /*
              * Call DFS for the source vertex 0
              *
             */
             graph.dfs(0); 
             /*
              * Check if the DFS Sequence is correct
              * 
             */
             if(testDFS(graph.DFSSequences))
             {
               cout<<"The generated DFS Sequence for the given graph is correct!"<<endl;
             }
             else
             {
               cout<<"The generated DFS Sequence for the given graph is wrong!"<<endl;
             }
             break;
    default : cout<<"Incorrect choice";
              break;
   }
    /*
     * Deallocating adjacency matrix
     * BELOW CODE MUST BE COMMENTED OUT WHEN THE CONSTRUCTOR Graph graph = Graph(nodes) is called
    */
   for(int i=0;i<nodes;i++)
    {
        delete[] adj_matrix[i];
    }
    delete adj_matrix;

}
