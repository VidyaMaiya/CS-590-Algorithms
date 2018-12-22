#ifndef __RB_TREE_H__
#define __RB_TREE_H__

enum rb_tree_color 
{
  RB_RED,
  RB_BLACK
};

struct rb_tree_node 
{
  int		key;
  int		color;
  rb_tree_node*	left;
  rb_tree_node*	right;
  rb_tree_node*	p;
};

class rb_tree
{ 
  protected:
 
    rb_tree_node*	T_nil;
    rb_tree_node*	T_root;

  public:
    rb_tree();
    ~rb_tree();
    int duplicateCounter;  //to track duplicate nodes in the tree
    int countNodes;   //No of unique nodes after removing duplicates
    int countCase1;   
    int countCase2;
    int countCase3;
    int countLeftRotate;
    int countRightRotate;
    int countBlackNodes;
    void insert(int*, int);
    void insert(int);

    // void inorder_output()
     // { inorder_output(T_root, 1); }
    void inorder_nodeArray(int*); 
    void inorder_output(rb_tree_node*,int*,int*);  //Stores the element of the tree into an array.
    void output()
      { output(T_root, 1); }

    bool testNumberOfBlackNodes(); //// test the property 5 of red black tree
    int getTreeHeight(rb_tree_node*,int);  //Get height of the tree

  protected:
    void insert(rb_tree_node*);
    void insert_fixup(rb_tree_node*&);

    
    void remove_all(rb_tree_node*);

    void left_rotate(rb_tree_node*);
    void right_rotate(rb_tree_node*);

    void inorder_output_1(rb_tree_node*, int);
    void output(rb_tree_node*, int);
};


#endif
