
#include "bs_tree.h"
#include <iostream>
using namespace std;

/*
 * constructor/destructor
 */
bs_tree::bs_tree()
{
  T_root = nullptr;
  bs_tree::duplicateCounter=0;
  bs_tree::countNodes=0;

}
bs_tree::~bs_tree()
{
  remove_all(T_root);
}
void bs_tree::insert(int* key_array,int n)
{
    for(int i=0;i<n;i++)
    {
        insert(key_array[i]);
    }
    cout<<"No of nodes: "<<bs_tree::countNodes<<endl;
    cout<<"No of duplicate nodes: "<<bs_tree::duplicateCounter<<endl;
}

void bs_tree::insert(int key)
{
    bs_tree_node* x;
    x = new bs_tree_node;
    x->key = key;
    x->left=nullptr;
    x->right = nullptr;
    insert(x);
}

void bs_tree::insert(bs_tree_node* z)
{
    bs_tree_node* x;
    bs_tree_node* y;
    
    y=nullptr;
    x= T_root;
    while(x!= nullptr)
    {
        y=x;
        if(z->key < x->key)
        {
            x = x->left;
        }
        else if(z->key > x->key)
        {
            x = x->right;
        }
        else
        {
            //Found the duplicae, hence increment the counter
            bs_tree::duplicateCounter++;
            return;
        }
    }
    z->p = y;
    if(y == nullptr)
    {
        T_root =z;
        bs_tree::countNodes++; //Increment the unique node counter
    }
    else 
    {
        if (z->key < y->key)
        {
           y->left = z;
           bs_tree::countNodes++; //Increment the unique node counter
        }
        else if(z->key > y-> key)
        {
            y->right = z;
            bs_tree::countNodes++;  //Increment the unique node counter
        }

    }
}

void bs_tree::inorder_nodeArray(int* bst_array)
{
    int i=0;
    bs_tree_node* T_node = T_root;
    inorder_tree_walk(T_node,bst_array,&i);
}

/* 
 * This function traverses the tree in inorder direction and stores the nodes into 
 * the array bst_array in an ascending order
*/
void bs_tree::inorder_tree_walk(bs_tree_node* T_node,int* bst_array,int *index)
{
   if(T_node!= nullptr)
   {
      inorder_tree_walk(T_node->left,bst_array,index);
      bst_array[(*index)] = T_node->key;
      *index = *index + 1;
      inorder_tree_walk(T_node->right,bst_array,index);
   }
}

/* This function returns the height of the binary search tree
*/
int bs_tree::getHeightOfBST()
{
  int getBSTreeHeight=0;
  bs_tree_node* T_node = T_root;
  getBSTreeHeight = getTreeHeight(T_node);
  return getBSTreeHeight;
}

/* 
 * This function calculates the height of the tree
*/  
int bs_tree::getTreeHeight(bs_tree_node* T_node)
{
    if(T_node == nullptr)
      return 0;

    int left = getTreeHeight(T_node->left);
    int right = getTreeHeight(T_node->right);

    if(left > right)
    {
      return left + 1;
    }
    else
    {
      return right + 1;
    }
}


void bs_tree::remove_all(bs_tree_node* x)
{
  if(x!=nullptr)
  {
    remove_all(x->left);
    remove_all(x->right);
    delete x;
 }
} 
