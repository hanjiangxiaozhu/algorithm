#ifndef SOLUTION_H
#define SOLUTION_H

#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<iterator>
#include <sys/time.h>
#include<string.h>
#include <queue>

#include "binarytree.h"
using namespace std;


#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class solution
{
public:
    solution();
    float getCalTimeOfFunc();
    void nextPermutation(vector<int>& nums);
    int lengthOfLongestSubstring(string s);//3
    string longestPalindrome(string s);

    string intToRoman(int num);//12
    vector<vector<int>> threeSum(vector<int>& nums);//15
    vector<vector<int>> fourSum(vector<int>& nums, int target);//18
    ListNode* removeNthFromEnd(ListNode* head, int n);//19
    
    vector<int> searchRange(vector<int>& nums, int target);
    bool isValidSudoku(vector<vector<char> >& board);
    
    int divide(int dividend, int divisor);//29
    int search(vector<int>& nums, int target);//33
    vector<vector<int> > combinationSum(vector<int>& candidates, int target);//39
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target);//40

    int firstMissingPositive(vector<int>& nums);//41
    int trap(vector<int>& height);//42
    string multiply(string num1, string num2);//43
    bool isMatch(string s, string p);//44
    int jump(vector<int>& nums);//45
    vector<vector<int> > permute(vector<int>& nums);//46
    void rotate(vector<vector<int> >& matrix);//48
    vector<vector<string> > groupAnagrams(vector<string>& strs);//49
    double myPow(double x, int n);//50
    vector<int> spiralOrder(vector<vector<int> >& matrix);//53
    bool canJump(vector<int>& nums);
    
    string getPermutation(int n, int k);//60
    vector<vector<int> > merge(vector<vector<int> >& intervals);
    int uniquePaths(int m, int n);//62
    void setZeroes(vector<vector<int> >& matrix);
    void sortColors(vector<int>& nums);//75
    string minWindow(string s, string t);//76
    vector<vector<int> > subsets(vector<int>& nums);//78
    bool exist(vector<vector<char> >& board, string word);//79
    int largestRectangleArea(vector<int>& heights);//84
    int numDecodings(string s);//91

    vector<int> inorderTraversal(TreeNode* root);//94
    bool isValidBST(TreeNode* root);

    vector<int> preOrder1(TreeNode* root);
    vector<int> inOrder1(TreeNode* root);
    vector<int> aftOrder1(TreeNode* root);

    vector<vector<int> > levelOrder(TreeNode* root);//102
    vector<vector<int> > levelOrderBFS(TreeNode* root);//102
    vector<vector<int> > levelOrderDFS(TreeNode* root);//102
    vector<vector<int> > zigzagLevelOrder(TreeNode* root);//103
    bool isSymmetric(TreeNode* root);//104

    int maxDepth(TreeNode* root);//104
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

    TreeNode* sortedArrayToBST(vector<int>& nums);//108
    int maxPathSum(TreeNode* root);//124

    Node* connect(Node* root);//116

    vector<vector<int> > generate(int numRows);//118
    int maxProfit(vector<int>& prices);

    bool isPalindrome(string s);
    int ladderLength(string beginWord, string endWord, vector<string>& wordList);
    int longestConsecutive(vector<int>& nums);//128

    void solve(vector<vector<char> >& board);

    int strStr(string haystack, string needle);//28

};




#endif // SOLUTION_H
