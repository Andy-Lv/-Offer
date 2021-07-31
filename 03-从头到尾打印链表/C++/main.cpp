//
// Created by andy on 2021/7/31.
//

//输入一个链表，返回一个反序的链表。

#include <vector>
#include <stack>

struct ListNode
{
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(Null) {}
};

class Solution
{
public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        stack<int> nodes;
        vector<int> result;

        ListNode *node = head;

        //入栈
        while (node != NULL)
        {
            node.push(node->val);
            node=node->next;
        }

        //出栈
        while(!nodes.empty())
        {
            result.push_back(nodes.top());
            nodes.pop();
        }

        return result;
    }
};