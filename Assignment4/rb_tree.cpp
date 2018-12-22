
#include "rb_tree.h"
#include <list>
#include <iostream>

using namespace std;

/*
 * constructor/destructor
 */
rb_tree::rb_tree()
{ /*<<<*/
/*
 * create T_nil element
 */
  rb_tree::duplicateCounter=0;
  rb_tree::countNodes=0;
  
  rb_tree::countLeftRotate=0;
  rb_tree::countRightRotate=0;

  rb_tree::countCase1=0;
  rb_tree::countCase2=0;
  rb_tree::countCase3=0;
  rb_tree::countBlackNodes=0;

  T_nil = new rb_tree_node();
  T_nil->color = RB_BLACK;
  T_nil->p = T_nil;
  T_nil->left = T_nil;
  T_nil->right = T_nil;

/*
 * root of rb tree
 */
  T_root = T_nil;
} /*>>>*/

rb_tree::~rb_tree()
{ /*<<<*/ 
/*
 * delete nil element and all other allocated nodes
 */
  remove_all(T_root);

  delete T_nil;
} /*>>>*/

void rb_tree::insert(int* key_array, int n)
{ /*<<<*/
  for (int i = 0; i < n; i++)
  {
    insert(key_array[i]);
  }
  cout<<"No of nodes: "<<rb_tree::countNodes<<endl;
  cout<<"No of duplicate nodes: "<<rb_tree::duplicateCounter<<endl;
  cout << "Counter for Case 1 : "<<rb_tree::countCase1<<endl;
  cout << "Counter for Case 2 : "<<rb_tree::countCase2<<endl;
  cout << "Counter for Case 3 : "<<rb_tree::countCase3<<endl;
  cout << "No of left rotation: "<<rb_tree::countLeftRotate<<endl;
  cout << "No of right rotation: "<<rb_tree::countRightRotate<<endl;

} /*>>>*/

void rb_tree::insert(int key)
{ /*<<<*/
/*
 * wrapper around insert
 * -> creates black node with key
 * -> inserts node
 */
  rb_tree_node* z;

  z = new rb_tree_node;
  z->color = RB_BLACK;
  z->key = key;

  insert(z);
} /*>>>*/

void rb_tree::insert(rb_tree_node* z)
{ /*<<<*/
/*
 * binary tree type insert 
 * -> search position, insert new node
 * -> fix properties after insert
 */
  rb_tree_node* x;
  rb_tree_node* y;

  y = T_nil;
  x = T_root;
  while (x != T_nil)
  {
      y = x;

      if (z->key < x->key)
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
         rb_tree::duplicateCounter++;
         return;
      }
  }

  z->p = y;
  if (y == T_nil)
  {
    T_root = z;
    rb_tree::countNodes++;   //Increment the unique node counter
  }
  else
  {
     if (z->key < y->key)
     {
        y->left = z;
        rb_tree::countNodes++;  //Increment the unique node counter
     }
     else
     {
        y->right = z;
        rb_tree::countNodes++;  //Increment the unique node counter
     }
  }

  z->left = T_nil;
  z->right = T_nil;
  z->color = RB_RED;

/*
 * after binary tree type insert we need to fix RB tree properties
 * -> update the info file
 */
  insert_fixup(z);
} /*>>>*/

void rb_tree::insert_fixup(rb_tree_node*& z)
{ /*<<<*/
/*
 * fix RB tree properties, after inserting a node
 * -> see book/slides for details on the cases
 */
  rb_tree_node* y;

  while (z->p->color == RB_RED)
  {
      if (z->p == z->p->p->left)
      {
	  y = z->p->p->right;

	  if (y->color == RB_RED)
	  {
	      z->p->color = RB_BLACK;		// Case 1
	      y->color = RB_BLACK;
	      z->p->p->color = RB_RED;
	      z = z->p->p;
              countCase1++;
	  }
	  else
	  {
	      if (z == z->p->right)
	      {
		  z = z->p;			// Case 2
                  countCase2++;
                  left_rotate(z);
                  countLeftRotate++;
	      }

	      z->p->color = RB_BLACK;		// Case 3
	      z->p->p->color = RB_RED;
              countCase3++;
              right_rotate(z->p->p);
              countRightRotate++;
	  }
      }
      else
      {
	  y = z->p->p->left;

	  if (y->color == RB_RED)
	  {
	      z->p->color = RB_BLACK;		// Case 1
	      y->color = RB_BLACK;
	      z->p->p->color = RB_RED;
	      z = z->p->p;
              countCase1++;
	  }
	  else
	  {
	      if (z == z->p->left)
	      {
		z = z->p;			// Case 2
                countCase2++;
                right_rotate(z);
                countRightRotate++;
	      }

	      z->p->color = RB_BLACK;		// Case 3
	      z->p->p->color = RB_RED;
              countCase3++;
              left_rotate(z->p->p);
              countLeftRotate++;
	  }
       }
    }

  T_root->color = RB_BLACK;
} /*>>>*/


void rb_tree::left_rotate(rb_tree_node* x)
{ /*<<<*/
/*
 * rotate left -> see book/slides
 */
  rb_tree_node* y;

  y = x->right;			// set y
  x->right = y->left;		// turn y's left subtree into x's right subtree
  if (y->left != T_nil)
  y->left->p = x;

  y->p = x->p;			// link x's parent to y
  if (x->p == T_nil)
      T_root = y;
  else
  {
      if (x == x->p->left)
        x->p->left = y;
      else
        x->p->right = y;
  }

  y->left = x;			// put x on y's left
  x->p = y;
} /*>>>*/

void rb_tree::right_rotate(rb_tree_node* x)
{ /*<<<*/
/*
 * rotate right -> see book/slides
 */
  rb_tree_node* y;

  y = x->left;			// set y
  x->left = y->right;		// turn y's right subtree into x's left subtree
  if (y->right != T_nil)
    y->right->p = x;

  y->p = x->p;			// link x's parent to y
  if (x->p == T_nil)
    T_root = y;
  else
    {
      if (x == x->p->right)
	x->p->right = y;
      else
	x->p->left = y;
    }

  y->right = x;			// put x on y's right
  x->p = y;
} /*>>>*/

void rb_tree::inorder_nodeArray(int* rbt_array)
{
    int i=0;
    rb_tree_node* T_node = T_root;
    inorder_output(T_node,rbt_array,&i); 
}
/* 
 * This function traverses the tree in inorder direction and stores the nodes into 
 * the array rbt_array in an ascending order
*/
void rb_tree::inorder_output(rb_tree_node* T_node, int* rbt_array, int *index)
{
  if(T_node!= T_nil)
   {
      inorder_output(T_node->left,rbt_array,index);
      rbt_array[(*index)] = T_node->key;
      *index = *index + 1;
      inorder_output(T_node->right,rbt_array,index);
   }
}


void rb_tree::inorder_output_1(rb_tree_node* x, int level)
{ /*<<<*/
/*
 * in order walk through binary tree
 * -> see book or slides
 */
  if (x != T_nil)
    {
      inorder_output_1(x->left, level+1);
      cout << "(" << x->key << "," << level << "," 
	   << ((x->color == RB_RED) ? "R" : "B") << ")" << endl;
      inorder_output_1(x->right, level+1); 
    }
} /*>>>*/

void rb_tree::output(rb_tree_node* x, int r_level)
{ /*<<<*/
/*
 * some structured output
 */
  list< pair<rb_tree_node*,int> > l_nodes;
  pair<rb_tree_node*,int> c_node;
  int c_level;

  c_level = r_level;
  l_nodes.insert(l_nodes.end(), pair<rb_tree_node*,int>(x, r_level));

  while (!l_nodes.empty())
    {
      c_node = *(l_nodes.begin());

      if (c_level < c_node.second)
	{
	  cout << endl;
	  c_level = c_node.second;
	}

      cout << "(" << c_node.first->key << "," 
	   << ((c_node.first->color == RB_RED) ? "R" : "B");

      if (c_node.first->p == T_nil)
	cout << ",ROOT) ";
      else
        cout << ",P:" << c_node.first->p->key << ") ";

      if (c_node.first->left != T_nil)
	l_nodes.insert(l_nodes.end(), pair<rb_tree_node*,int>(c_node.first->left, 
							      c_node.second+1));
      if (c_node.first->right != T_nil)
	l_nodes.insert(l_nodes.end(), pair<rb_tree_node*,int>(c_node.first->right, 
							      c_node.second+1));
      l_nodes.erase(l_nodes.begin());
    }

  cout << endl;
} /*>>>*/

/* Test the red back tree's property 5
* if black height >= (height of the tree)/2
* Then the property 5 is satisfied.
*/
bool rb_tree::testNumberOfBlackNodes()
{
  int heightOfTree = 0;
  rb_tree_node* T_node = T_root;
  heightOfTree = getTreeHeight(T_node,countBlackNodes);
  cout<<"Height of the tree: "<<heightOfTree<<endl;
  cout<<"No of BlackNodes: "<<rb_tree::countBlackNodes<<endl;
  if(rb_tree::countBlackNodes >= (heightOfTree/2))
  {
    return true;
  }
  else
  {
    return false;
  }

}

/* This function calculates the height of the tree
 * and calculates the no of black nodes in the tree
*/
int rb_tree::getTreeHeight(rb_tree_node* T_node, int countBlackNodes)
{
    if(T_node == T_nil)
      return 0;
   
    int left = getTreeHeight(T_node->left,countBlackNodes);
    if(T_node->color == RB_BLACK)
    {
      rb_tree::countBlackNodes++;
    }
    int right = getTreeHeight(T_node->right,countBlackNodes);

    if(left > right)
    {
      return left + 1;
    }
    else
    {
      return right + 1;
    }
}

void rb_tree::remove_all(rb_tree_node* x)
{ /*<<<*/
/*
 * recursively remove all tree elements
 */
  if (x != T_nil)
    {
      remove_all(x->left);
      remove_all(x->right);

      delete x;
    }
} /*>>>*/

