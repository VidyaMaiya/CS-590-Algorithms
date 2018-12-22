#include <iostream>
#include "LinkedList.h"
#include <map>
using namespace std;

// First implementation; uses additional data structure
void removeDupl_1(Node* head)
{
	//Declare node cur and prev. Make them point to head.
    Node* cur=head;
    Node* prev=cur;
	//Declare a map of integer key and values
    map<int,int> hmap;
    while(cur!=nullptr)
    {
		//Read each node and insert only the unique node into the map.
      if(hmap.find(cur->data)!= hmap.end())
      {
		prev->next=cur->next;  //cur node is already inserted and hence remove it by adjusting it's previous node's pointer to point to its next node.
      }
      else
      {
		  //The current node not found in the map. Therefore insert it to the map.
		hmap.insert(make_pair(cur->data,1));
      }
        prev=cur;
        cur=cur->next;
   }
}


// This implementation uses no additional data structure 
void removeDupl_2(Node* head)
{
	//Declaring 3 nodes and set cur and prev1 nodes pointing to head
   Node* cur=head;
   Node* prev1=head;
   Node* prev2;
   while(prev1!=nullptr)
  {
     prev2=prev1;
     cur=prev1->next;
     while(cur!=nullptr)
    {
		//Whenever there exists a duplicate node, remove that duplicate node by adjusting it's previous node's pointer, pointing to it's next node.
      if(prev1->data == cur->data)
      {
        prev2->next=cur->next;
      }
      prev2=cur; 
      cur=cur->next;
   }
    prev1=prev1->next;
 }
}   


int main()
{
    LinkedList* myList = new LinkedList();
    myList->insert(5);
    myList->insert(5);
    myList->insert(7);
    myList->insert(12);
    myList->insert(7);
    myList->insert(16);
    myList->insert(16);
    myList->insert(25);
    myList->insert(11);
    myList->insert(5);
    myList->insert(6);
    myList->insert(6);
    cout << "The original list is: ";
    myList->display();

    //Use removeDupl_2 to run that implementation
    //removeDupl_1(myList->head);
	removeDupl_2(myList->head);

    cout << "The list with duplicated removed is: ";
    myList->display();
    delete myList;

    return 0;
}
