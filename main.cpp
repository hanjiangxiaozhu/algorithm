/*
 * @Author: your name
 * @Date: 2020-06-16 20:00:28
 * @LastEditTime: 2020-07-13 20:02:27
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /algorithm/main.cpp
 */ 
#include <iostream>

#include "solution.h"

using namespace std;


int main()
{
    solution s;
    string num ="babad";
    // string j = s.longestPalindrome(num);

    vector<int> in = {4,5,6,7,7,10,12};
    // bool ans = s.canJump(in);

    // vector<vector<int> > ans = s.threeSum(in);//15
    // vector<vector<int> > ans = s.fourSum(in,-11);//18

    /*18
    vector<int> a={1};
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    for(auto i:a){
        ListNode *temp = new ListNode(i);
        p->next = temp;
        p=temp;
    }
    ListNode *ans = s.removeNthFromEnd(head->next,1);
    */

    // int ans = s.divide(10,3);//29

    vector<int> ans = s.searchRange(in,7);

    cout << "Hello World!" << endl;
    return 0;
}
