#include <iostream>

#include "graph.h"
#include "random_generator.h"

using namespace std;

int main(int argc, char* argv[])
{ 
   int n,m,w;
   /*
    * Creating the random graph for question1
   */
   cout<<"Enter no of vertices(n): "<<endl;
   cin>>n;
   if(n<=0)
   {
     cout<<"Please enter valid number of vertices"<<endl;
     return 0;
   }
   cout<<"Enter no of edges ( m - within the range n*(n-1)): "<<endl;
   cin>>m;
   if(m<=0)
   {
     cout<<"Please enter valid number of edges"<<endl;
     return 0;
   }
   cout<<"Enter the weight (w): "<<endl;
   cin>>w;
   
   graph graph3 = graph(n);
   graph3.random_graph(m,w);
   cout<<"---------------------------------------------------------"<<endl;
   cout<<"Printing the Random Graph"<<endl;
   cout<<"---------------------------------------------------------"<<endl;
   graph3.output();


    int floyd_nodes;
    cout<<"Enter number of nodes for Floyd's graph: "<<endl; 
    //For the given graph, number of vertices is  5
    cin>>floyd_nodes; 
    
    graph graph1 = graph(floyd_nodes);

    /*
     * Set the edges in the graph
    */
    graph1.set_edge(1,2,3);
    graph1.set_edge(1,3,8);
    graph1.set_edge(1,5,-4);
    graph1.set_edge(2,4,1);
    graph1.set_edge(2,5,7);
    graph1.set_edge(3,2,4);
    graph1.set_edge(4,1,2);
    graph1.set_edge(4,3,-5);
    graph1.set_edge(5,4,6);

 
    graph1.floydWarshallAlgorithm();
    cout<<"Output matrix of Floyd Warshall"<<endl;
    graph1.output();
    cout<<"Output matrix of predecessor matrix"<<endl;
    graph1.output_predecessor();
  
    int bellmanford_nodes;
    cout<<"Enter number of nodes for Bellman-Ford: "<<endl;
    //For the given graph number of vertices is 5
    cin>>bellmanford_nodes;

   graph graph2 = graph(bellmanford_nodes); 
 /*
  * Below commented graph contains negative cycle  
  * graph2.set_edge(1,2,5);
    graph2.set_edge(1,3,4);
    graph2.set_edge(2,4,3);
    graph2.set_edge(3,2,-6);
    graph2.set_edge(4,3,2);
  */
    graph2.set_edge(1,2,6);
    graph2.set_edge(1,4,7);
    graph2.set_edge(2,3,5);
    graph2.set_edge(2,4,8);
    graph2.set_edge(2,5,-4);
    graph2.set_edge(3,2,-2);
    graph2.set_edge(4,3,-3);
    graph2.set_edge(4,5,9);
    graph2.set_edge(5,1,2);
    graph2.set_edge(5,3,7); 
   
   bool isNegativeCycleFound = graph2.bellmanFordAlgorithm(1);
   cout<<"Is Negative Cycle Found in the graph? : ";
   if(isNegativeCycleFound)
	cout<<"Yes"<<endl;
   else
	cout<<"No"<<endl;
    
  return 0;
}
  
