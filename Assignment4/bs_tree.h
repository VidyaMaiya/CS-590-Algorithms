#ifndef __BS_TREE_H__
#define __BS_TREE_H__

#endif

struct bs_tree_node
{
    int key;
    bs_tree_node* left;
    bs_tree_node* right;
    bs_tree_node* p;
};
class bs_tree
{
public:
    int duplicateCounter;
    int countNodes;
    bs_tree_node* T_root;
    bs_tree_node* T_nil;
public :
    bs_tree();
    ~bs_tree();
    void insert(int*,int);
    void insert(int);
    void insert(bs_tree_node*);
    void inorder_nodeArray(int*);
    void inorder_tree_walk(bs_tree_node*,int*,int*);
    int getHeightOfBST();
    int getTreeHeight(bs_tree_node*);
    void remove_all(bs_tree_node*);
};
