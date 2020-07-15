/*
 * @Author: your name
 * @Date: 2020-06-16 20:00:52
 * @LastEditTime: 2020-07-08 20:00:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /algorithm/binarytree.h
 */ 
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <vector>
#include <stddef.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(int* array,int n);
    void create_tree(TreeNode* &tree, int a[], int len, int index);

    void preorder(TreeNode* p,vector<int>& res);
    bool isValid(TreeNode* root,long left,long right);

    int DFSDepth1(TreeNode* root);
    int DFSDepth(TreeNode* left,TreeNode* right);
    int maxDepth(TreeNode* root);

    void preOrder(TreeNode* root,vector<int> &ans);
    void inOrder(TreeNode* root,vector<int> &ans);
    void aftOrder(TreeNode* root,vector<int> &ans);

    TreeNode* sortedArrToBST(vector<int>::iterator itbeg,vector<int>::iterator itend,vector<int>& nums);

private:
    TreeNode *root;
};

#endif // BINARYTREE_H
