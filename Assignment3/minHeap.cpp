#include <iostream>
#include <climits>
#include "minHeap.h"

using namespace std; 

minHeap::minHeap(int cap) 
{ 
  heapArray= new int[cap];
  heapSize=0;
  capacity=cap;
} 

minHeap::~minHeap()
{
   delete[] heapArray;
}
void minHeap::insertKey(int k) 
{ 
        if(heapSize >= capacity)
        {
                cout<<"InsertKey() failed : Exceeded the capacity of heap array."<< endl;
                return;
        }
        else
        {
                heapSize++;
                //insert the element in the last position
                int i = heapSize-1; 
                heapArray[i] = k;
                while(i != 0)
                {
                        int temp = 0;
                        int parent = minHeap::parent(i); //check the position of parent
                        if(heapArray[parent] > heapArray[i])
                        //swapping the value of parent and inserted element
                        {
                                temp = heapArray[parent];
                                heapArray[parent] = heapArray[i];
                                heapArray[i] = temp;
                        }
                        i = minHeap::parent(i);
                }
        }
}


void minHeap::decreaseKey(int i, int new_val) 
{ 
		int temp = 0;
		int parent = minHeap::parent(i);
		heapArray[i] = new_val;
		while(i > 0 && heapArray[i] < heapArray[parent] )
		{
			temp = heapArray[i];
                        heapArray[i] = heapArray[parent];
                        heapArray[parent] = temp;
                        i = minHeap::parent(i);
		}
} 

int minHeap::extractMin() 
{
      int min=0; 
	if(minHeap::size()<= 0)
	{
 	   cout<<"Error: No elements in the heap"<< endl;       
           return -1; 
	}
	        min = minHeap::getMin();
		heapArray[0] = heapArray[heapSize - 1];
		heapSize = heapSize-1;
		minHeap::minHeapify(0);
	return min;
} 

void minHeap::deleteKey(int i) 
{ 
 	if(minHeap::size() == 0)
	 {
		 cout << "deleteKey() failed : Heap Array is empty " <<endl;
		return;
	 
	 }
	 heapArray[i] = heapArray[heapSize -1];
	 heapSize--;
	 minHeapify(i);


} 


void minHeap::minHeapify(int i) 
{ 
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l <= heapSize && heapArray[l] < heapArray[i] )
	{
		 smallest = l;
	}
	else{
		 smallest = i;
	}
	if(r <= heapSize && heapArray[r] < heapArray[smallest])
	{
		smallest = r;
	}
	if(smallest != i)
	{
		int temp =0; 
		temp = heapArray[smallest];
        heapArray[smallest] = heapArray[i];
        heapArray[i] = temp;
        minHeapify(smallest);
	}
	//i = minHeap::minHeapify(smallest);
} 

