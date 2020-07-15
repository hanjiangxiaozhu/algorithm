#include "binarytree.h"

BinaryTree::BinaryTree()
{

}
BinaryTree::BinaryTree(int *array,int n)
{
    root = new TreeNode(array[0]);
    TreeNode* p=root;

    TreeNode* tmp;
    for(int i=1;i<n;i++){
        tmp=new TreeNode(array[i]);
        if(tmp->val<p->val) {
            p->left=tmp;
            p=p->left;
        } else {
            p->right=tmp;
            p=p->right;
        }
    }
}

//int b[]={5,4,8,1,3,6,10,0,2,1,5};
//TreeNode* root;
//create_tree(root,b,sizeof(b)/sizeof(int),0);
void BinaryTree::create_tree(TreeNode* &tree, int a[], int len, int index){
    if (index >= len||a[index]==-1)
        return;
    tree = new TreeNode(a[index]);
    create_tree(tree->left, a, len, 2 * index + 1);
    create_tree(tree->right, a, len, 2 * index + 2);
}

//isValid(root,INT_FAST32_MIN,INT_FAST32_MAX);
bool BinaryTree::isValid(TreeNode* root,long left,long right){
    if(!root) return true;
    else if(root->val<=left||root->val>=right) return false;

    return isValid(root->left,left,root->val)&&isValid(root->right,root->val,right);
}

void BinaryTree::preorder(TreeNode* p,vector<int>& res){
    if(p){
        preorder(p->left,res);
        res.push_back(p->val);
        preorder(p->right,res);
    }
}

//function 1
//int maxDepth(TreeNode* root) {
//    int depth=0;
//    if(!root) return depth;
//    return DFSDepth(root);
//}
int BinaryTree::DFSDepth1(TreeNode* root){
    if(!root) return 0;
    int leftMaxDepth=DFSDepth1(root->left);
    int rightMaxDepth=DFSDepth1(root->right);
    return max(leftMaxDepth,rightMaxDepth)+1;
}
//function 2
int BinaryTree::DFSDepth(TreeNode* left,TreeNode* right){
    int depth =0;
    if (!left && !right) return depth+1;
    else if (!left && right) depth=DFSDepth(right->left,right->right);
    else if (left&&!right) depth=DFSDepth(left->left,left->right);
    else  {
       int dleft=DFSDepth(left->left,left->right);
       int dright=DFSDepth(right->left,right->right);
       depth=dleft>dright?dleft:dright;
    }
    return depth+1;
}
//function 3
int BinaryTree::maxDepth(TreeNode* root) {
    int depth=0;
    if(!root) return depth;

    vector<TreeNode*> NodeLi,NodeNextL;
    NodeLi.push_back(root);
    while (!NodeLi.empty()) {
        depth++;
        NodeNextL.clear();
        for(int i=0;i<NodeLi.size();i++){
            TreeNode* node=NodeLi[i];
            if(node->left) NodeNextL.push_back(node->left);
            if(node->right) NodeNextL.push_back(node->right);
        }
        NodeLi=NodeNextL;
    }

    return depth;
}


void BinaryTree::preOrder(TreeNode* root,vector<int> &ans){
    if(!root) return;
    ans.push_back(root->val);
    preOrder(root->left,ans);
    preOrder(root->right,ans);
    return;
}
void BinaryTree::inOrder(TreeNode* root,vector<int> &ans){
    if(!root) return;
    inOrder(root->left,ans);
    ans.push_back(root->val);
    inOrder(root->right,ans);
    return;
}
void BinaryTree::aftOrder(TreeNode* root,vector<int> &ans){
    if(!root) return;
    aftOrder(root->left,ans);
    aftOrder(root->right,ans);
    ans.push_back(root->val);
    return;
}

//将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树
TreeNode* BinaryTree::sortedArrToBST(vector<int>::iterator itbeg,vector<int>::iterator itend,vector<int>& nums){
    TreeNode* root=NULL;
    if(itbeg==itend) return root;

    vector<int>::iterator it=itbeg+(itend-itbeg)/2;
    root=new TreeNode(*it);
    root->left=sortedArrToBST(itbeg,it,nums);
    it++;
    root->right=sortedArrToBST(it,itend,nums);
    return root;
}
