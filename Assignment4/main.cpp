#include <cstdio>
#include <cstdlib>

#include "sort.h"
#include "bs_tree.h"
#include "rb_tree.h"
#include "timer.h"
#include "random_generator.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    random_generator rg ;
    timer t;
    int m,d;

    if (argc > 1)
    { 
      m = atoi(argv[1]);
      m = (m < 1) ? 1 : m;
    }
    else
    {
      cout << "hw1: [m] [direction]" << endl;
      cout << "[m] number of the random numbers generated" << endl;
      cout << "[direction]      0: random" << endl;
      cout << "                 1: sorted" << endl;
      cout << "                 -1: reverse sorted" << endl;
      cout << endl;
      return 0;
    }
    if(argc > 2)
    {
       d = atoi(argv[2]);
    }
    else
    {
      d = 0;
    }
    
    int* input_array = new int[m];
    bs_tree bst= bs_tree();
    rb_tree rbt = rb_tree();

    /*
 * create input random array  
 * depending on program argument
 * -> input_array is allocated!
 */
    t.start();
    if(d == 0) 
    {
       input_array = create_random(m);
    }
    else if(d < 0)
    {
       input_array = create_reverse_sorted(m);
    }
    else
    {
       input_array = create_sorted(m);
    }
    t.stop();
    cout << "Timer (generate): " << t << endl;

 /*
 * output the first 30 elements for debugging purposes
 */
    for(int i=0;(i<m) && (i<30);i++)
    {
        cout<<" [ ";
        cout<<input_array[i]<<" ";
        cout<<" ] "<<endl;
    }
    cout<< endl;

    /*
    * Running binary search tree insert
    */
    cout<<"------------------------------------------------"<<endl;
    cout<<"Running binary search tree insertion algorithm: "<<endl;
    cout<<"------------------------------------------------"<<endl;
    bst.insert(input_array,m);
    int bsize = bst.countNodes;
    int *bst_array= new int[bsize];
    int treeHeight = bst.getHeightOfBST();
    cout<<"The height of the binary search tree: "<<treeHeight<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"Running binary search tree sorting algorithm: "<<endl;
    cout<<"----------------------------------------------"<<endl;
    t.start();
    bst.inorder_nodeArray(bst_array);
    t.stop();
   
    cout << "Timer (sort): " << t << endl;

 /*
  * check whether or not the algorithm sorted the array
 */
   if(check_sorted(bst_array,0,bsize-1))
     cout<<"The output is sorted!" << endl;
   else
     cout << "ERROR: The output is not sorted!" << endl;
   
   /*
    * Output the first 30 elements for debugging purpose
   */
    for(int i=0;(i<bsize) && (i<30);i++)
    {
       cout<<" [ ";
       cout<<bst_array[i]<<" ";
       cout<< " ] "<<endl;
    }
    cout<<endl;
 
    cout<<"--------------------------------------------"<<endl;
    cout<<"Running red black tree insertion algorithm: "<<endl;
    cout<<"--------------------------------------------"<<endl;
    rbt.insert(input_array,m);
 
    bool isBlackHeightCorrect =  rbt.testNumberOfBlackNodes();
    if(isBlackHeightCorrect)  
        cout<<"Red black tree satisfies property 5 "<<endl;
    else
        cout<<"Red black tree doesn't satisfy property 5 "<<endl;

   int rsize = rbt.countNodes;
   int *rbt_array = new int[rsize];
   cout<<"------------------------------------------"<<endl;
   cout<<"Running red black tree sorting algorithm: "<<endl;
   cout<<"------------------------------------------"<<endl;
   t.start();
   rbt.inorder_nodeArray(rbt_array);
   t.stop();
   cout << "Timer (sort): " << t << endl;

 /*
  * check whether or not the algorithm sorted the array
  */
    if(check_sorted(rbt_array,0,rsize-1))
      cout<<"The output is sorted!" << endl;
    else
      cout << "ERROR: The output is not sorted!" << endl;

   /*
    * Output the first 30 elements for debugging purpose
   */
    for(int i=0;(i<rsize) && (i<30);i++)
    {
       cout<<" [ ";
       cout<<rbt_array[i]<<" ";
       cout<< " ] "<<endl;
    }
    cout<<endl;

    delete[] input_array;
    delete[] bst_array;
    delete[] rbt_array;

}
  
