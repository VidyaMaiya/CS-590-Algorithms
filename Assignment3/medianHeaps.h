#ifndef __medianHeaps_h__
#define __medianHeaps_h__

#include "minHeap.h"
#include "maxHeap.h"

// A class for Min Heap 
class medianHeaps
{ 
    // member variables
     maxHeap m_mxHeap;
     minHeap m_mnHeap;
     int median;

    
public: 
    // Constructor 
    medianHeaps(int capacity); 

    // Destructor
    ~medianHeaps();
  
    // Adds a new number and stores it in the two heaps to maintain the median value
    void addNewNumber(int x);
    
    // Returns median value from randomly generated values
    int getMedian();
};

#endif // __medianHeaps_h__
