
#include "graph.h"
#include <list>
#include <iostream>
#include "limits.h"
using namespace std;

/*
 * constructor/destructor
 */
graph::graph(int n)
{ /*<<<*/
  no_vert = (n > 0) ? n : 1;

/*
 * allocate adjacency matrix
 */
  m_edge = new int*[no_vert];
  for (int i = 0; i < no_vert; i++)
    m_edge[i] = new int[no_vert];

  m_predecessor = new int*[no_vert];
  for (int i = 0; i < no_vert; i++)
    m_predecessor[i] = new int[no_vert];

  initialize();
} /*>>>*/

graph::~graph()
{ /*<<<*/ 
/*
 * delete nil element and all other allocated nodes
 */
  for (int i = 0; i < no_vert; i++)
  {
    delete[] m_edge[i];
    delete[] m_predecessor[i];
  } 
  delete[] m_edge;
  delete[] m_predecessor;
} /*>>>*/


void graph::initialize()
{ /*<<<*/
/*
 * initialize adjacency matrix
 * -> use infinity to allow 0 weight edges
 */
  for (int i = 0; i < no_vert; i++)
  {
    for (int j = 0; j < no_vert; j++)
    {
      m_edge[i][j] = INT_MAX;
      m_edge[i][i]=0;
      m_predecessor[i][j]=INT_MAX;
    }
      
  }
} /*>>>*/

void graph::permutation(int* perm, int n)
{ /*<<<*/
  random_generator rg;
  int p_tmp, p_pos;

  for (int i = 0; i < n; i++)
    perm[i] = i;
  
  for (int i = 0; i < n; i++)
    {
      rg >> p_pos;
      p_pos = (p_pos % (n - i)) + i;

      p_tmp = perm[i];
      perm[i] = perm[p_pos];
      perm[p_pos] = p_tmp;
    }
} /*>>>*/

void graph::output()
{ /*<<<*/
  cout << "[";
  for (int i = 0; i < no_vert; i++)
    {
      cout << "[\t";
      for (int j = 0; j < no_vert; j++)
	if (m_edge[i][j] == INT_MAX)
	  cout << "Inf\t";
	else
	  cout << m_edge[i][j] << "\t";
      cout << "]" << endl;
    }
  cout << "]" << endl;
} /*>>>*/

void graph::set_edge(int source, int destination, int weight)
{
    if(source > graph::no_vert || destination > graph::no_vert || source < 0 || destination < 0 )
    {
      cout<<"Invalid edge, please enter the valid edge"<<endl;
    }
    else
    {
      graph::m_edge[source-1][destination-1] = weight;
      graph::m_predecessor[source-1][destination-1]=source;
    }
}


void graph::output_predecessor()
{ /*<<<*/
  cout << "[";
  for (int i = 0; i < no_vert; i++)
    {
      cout << "[\t";
      for (int j = 0; j < no_vert; j++)
	if (m_predecessor[i][j] == INT_MAX)
	  cout << "NIL\t";
	else
	  cout << m_predecessor[i][j] << "\t";
      cout << "]" << endl;
    }
  cout << "]" << endl;
} /*>>>*/

void graph::floydWarshallAlgorithm()
{
  cout<<"---------------------------------------------------------"<<endl;
  cout<<"Running Floyd-Warshall Algorithm"<<endl;
  cout<<"---------------------------------------------------------"<<endl;
  floydWarshallShortestPath(m_edge, m_predecessor);
}
void graph::floydWarshallShortestPath(int** m_edge, int**m_predecessor)
{

  for(int k=0;k<no_vert;k++)
  {
    for(int i=0;i<no_vert;i++)
    {
      for(int j=0;j<no_vert;j++)
      {
        if( j!=i && (m_edge[i][k] != INT_MAX &&  m_edge[k][j] != INT_MAX))
        {
           if( (m_edge[i][k]+m_edge[k][j]) < m_edge[i][j])
           {
            m_edge[i][j] = (m_edge[i][k]+m_edge[k][j]);
            m_predecessor[i][j] =  m_predecessor[k][j];
           }
        }
     }
   }
 }
  
}

bool graph::bellmanFordAlgorithm(int source)
{
   cout<<"---------------------------------------------------------"<<endl;
   cout<<"Running BellmanFord Algorithm"<<endl;
   cout<<"---------------------------------------------------------"<<endl;

  int* distance_vector = new int[graph::no_vert];
   isNegativeCycleFound = bellmanFordShortestPath(m_edge,source-1,distance_vector);
   cout<<"Bellman Ford Distance Vector Output sequence : "<<endl;
   for(int i=0;i<graph::no_vert;i++)
   {
     cout<<i+1<<"------->"<<distance_vector[i]<<endl;
   }
   return isNegativeCycleFound;
   delete[] distance_vector;
}

bool graph::bellmanFordShortestPath(int** m_edge, int source, int *distance_vector)
{
   for(int i=0;i<no_vert;i++)
   {
     distance_vector[i]=INT_MAX;
   }
   distance_vector[source]= 0;

   for(int k=1;k<no_vert;k++)
   {
     for(int i=0;i<no_vert;i++)
     {
       for(int j=0;j<no_vert;j++)
       {
         if(m_edge[i][j] !=0 && m_edge[i][j] != INT_MAX)
         {
            if(distance_vector[i] + m_edge[i][j] < distance_vector[j])
            {
              distance_vector[j] = distance_vector[i] + m_edge[i][j] ;
            }
         }
       }
     }
   }
  
  for(int i=0;i<no_vert;i++)
  {
    for(int j=0;j<no_vert;j++)
    {
      if(m_edge[i][j] !=0 && m_edge[i][j] != INT_MAX)
      {
        if(distance_vector[i] + m_edge[i][j] < distance_vector[j])
        {
           isNegativeCycleFound=true;
	   return isNegativeCycleFound;
        }
      }
    }
  }
  return isNegativeCycleFound;
}

void graph::random_graph(int m, int w)
{
  random_generator rg;
  double weight;
  int indice_array[no_vert];

  if(m > no_vert*(no_vert-1))
  {
    m = no_vert*(no_vert-1);
  }
  while(m>0)
  {
    //Avoids cycle to be present in the graph
    int noOfEdges = (m>no_vert-1)?no_vert-1:m;
    //Swaps the indices
    permutation(indice_array,no_vert);
    for(int i=0;i<noOfEdges;i++)
    {
      //Check if the edges exist
      if( m_edge[indice_array[i]][indice_array[i+1]] == INT_MAX )
      {
        rg>>weight;
        weight = (weight - 0.5)*2*w;
        m_edge[indice_array[i]][indice_array[i+1]] = weight;
        m--;
      }
    }
  }
}
