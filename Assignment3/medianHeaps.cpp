#include <iostream>
#include <climits>
#include "medianHeaps.h"
#include "minHeap.h"
#include "maxHeap.h"

using namespace std; 

medianHeaps::medianHeaps(int cap) :
   m_mxHeap(cap), m_mnHeap(cap)
{ 
      median=0;
} 

medianHeaps::~medianHeaps()
{
}

void medianHeaps::addNewNumber(int x) 
{
    /*
     * Left subtree = maxHeap => Stores lower half of the numbers.
     * Right subtree = minHeap => Stores upper half of the numbers.
     * Check if MaxHeap and minHeap trees are imbalanced, if yes balance them up first and then insert accordingly. 
     * Median value will be root element of the maxHeap or minHeap based on whichever has more elements in it.
     * If maxHeap has more heapSize then median would be root of maxHeap ; Similarly if minHeap has more elements then median would be root of minHeap
     * if both MaxHeap and minHeap tree are balanced, then median would be the average of root element of both maxHeap and minHeap
     */ 
    if(m_mxHeap.size() > m_mnHeap.size())
    {
       if( x < medianHeaps::median)
       {
          //Take the root element from bigger heap and add it smaller heap.
          m_mnHeap.insertKey(m_mxHeap.extractMax());
          m_mxHeap.insertKey(x);
      }
      else
      {
         m_mnHeap.insertKey(x);
      }
     medianHeaps::median = getMedian();
   }
   else if(m_mnHeap.size() > m_mxHeap.size())
   {
      if( x < medianHeaps::median)
      {
         m_mxHeap.insertKey(x);
      }
      else
      {
         //Take the root element from bigger heap and add it smaller heap.
         m_mxHeap.insertKey(m_mnHeap.extractMin());
         m_mnHeap.insertKey(x); 
      }
      medianHeaps::median = getMedian();
   }
   else if(m_mxHeap.size() ==  m_mnHeap.size())
   {
       if( x < medianHeaps::median )
       {
          m_mxHeap.insertKey(x);
          median = getMedian();
      }
      else 
      {
         m_mnHeap.insertKey(x);
         medianHeaps::median = getMedian();
      }
   }
   
}

 
int medianHeaps::getMedian() 
{
    if(m_mxHeap.size() >  m_mnHeap.size()) 
    {
      return m_mxHeap.getMax();
    }
    else if (m_mnHeap.size() > m_mxHeap.size())
    {
      return m_mnHeap.getMin();
    }
    else
    {
       return (m_mxHeap.getMax() + m_mnHeap.getMin())/2;
    }

} 
