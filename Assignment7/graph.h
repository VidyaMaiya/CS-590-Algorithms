#ifndef __AM_GRAPH_H__
#define __AM_GRAPH_H__

#include <limits.h>
#include "random_generator.h"
    
class graph
{
  protected:
    int**	m_edge;
    int** m_predecessor;
    int		no_vert;
    int predecessor_indicator;


  public:
    graph(int);
    ~graph();

    int get_no_of_vertices()
      { return no_vert; }

    void output();
    void output_predecessor();
    void set_edge(int source, int destination, int weight);
    void floydWarshallAlgorithm();
    bool bellmanFordAlgorithm(int source);
    bool isNegativeCycleFound=false;
    void random_graph(int m, int w);
    

  protected:
    void initialize();
    void permutation(int*, int);
    void floydWarshallShortestPath(int **m_edge, int** m_predecessor);
    bool bellmanFordShortestPath(int **m_edge,int source, int *distance_vector);
    int findMinimum(int,int);
};



#endif
