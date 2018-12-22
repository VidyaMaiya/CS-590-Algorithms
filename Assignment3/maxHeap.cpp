#include <iostream>
#include <climits>
#include "maxHeap.h"

using namespace std; 



maxHeap::maxHeap(int cap) 
{ 
   heapArray = new int[cap];
   heapSize=0;
   capacity=cap;
} 

maxHeap::~maxHeap()
{
  delete[] heapArray;
}

void maxHeap::insertKey(int k) 
{ 
	if(heapSize > capacity)
        {  
	    cout<<"InsertKey() failed : Exceeded the capacity of heap array."<<endl;
	    return ;
        }
       else
       {	
            heapSize++;
	    //Get the last position in the heap array
	    int i=heapSize-1;
            heapArray[i]=-1;
            increaseKey(i,k);
       }
	
} 

void maxHeap::increaseKey(int i, int new_val) 
{ 
   if(new_val < heapArray[i])	
   {
      cout<<"IncreaseKey() failed : The new value"<<new_val<<"  is smaller than the current value "<<heapArray[i]<<endl;
      return ;
   }
   heapArray[i]=new_val;
   while(i>0)
   {
       int temp=0;
       //get the position of it's parent
       int parent=maxHeap::parent(i);
       //check if parent of the new element is smaller than value of new element. If yes, then swap the values.
       if(heapArray[parent]<heapArray[i])
       {
            temp=heapArray[parent];
            heapArray[parent]=heapArray[i];
             heapArray[i]=temp;
       }
       i=maxHeap::parent(i);
    }
} 

int maxHeap::extractMax() 
{ 
     int max=0;
     if(maxHeap::size() <= 0)
     {
         cout<<"extractMax() failed : Heap array is empty"<<endl;
         return -1;
     }
     max=maxHeap::getMax();
     heapArray[0]=heapArray[heapSize-1];
     heapSize--;
     maxHeapify(0);
     return max;
     
} 
 
void maxHeap::deleteKey(int i) 
{ 
     if(maxHeap::size() == 0)
     {
        cout<<"deleteKey() failed : Heap array is empty"<<endl;
	return ;
     }
     cout<<"Item to delete: "<<heapArray[i]<<endl;
     heapArray[i]=heapArray[heapSize-1];
     heapSize--;
     maxHeapify(i);
} 

void maxHeap::maxHeapify(int i) 
{ 
   int largest=0;
   //Get the position of left child
   int left =maxHeap::left(i);
   //Get the position of right child
   int right = maxHeap::right(i);
   if(left<=heapSize && heapArray[left]>heapArray[i])
   {
 	largest=left;
   }
   else
   {
      largest=i;
   }
   if(right<=heapSize && heapArray[right]>heapArray[largest])
   {
       largest=right;
   }
   if(largest!=i)
   {
     int temp=0;
     //Swap the elements which voilates max Heap property
     temp=heapArray[largest];
     heapArray[largest]=heapArray[i];
     heapArray[i]=temp;
     maxHeapify(largest);
   }
}
