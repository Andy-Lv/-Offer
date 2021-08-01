//
// Created by andy on 2021/7/31.
//
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    if (pre.size() == 0)
    {                    //如果为空，返回NULL
        return NULL;
    }

    //依次是前序遍历左子树，前序遍历右子树，中序遍历左子树，中序遍历右子树
    vector<int> left_pre, right_pre, left_vin, right_vin;

    //前序遍历第一个节点一定为根节点
    TreeNode *head = new TreeNode(pre[0]);

    //找到中序遍历的根节点
    int root = 0;
    //遍历找到中序遍历根节点索引值
    for (int i = 0; i < pre.size(); i++)
    {
        if (pre[0] == vin[i])
        {
            root = i;
            break;
        }
    }

    //利用中序遍历的根节点，对二叉树节点进行归并
    for (int i = 0; i < root; i++)
    {
        left_vin.push_back(vin[i]);
        left_pre.push_back(pre[i + 1]);            //前序遍历第一个为根节点
    }

    for (int i = root + 1; i < pre.size(); i++)
    {
        right_vin.push_back(vin[i]);
        right_pre.push_back(pre[i]);
    }

    //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
    head->left = reConstructBinaryTree(left_pre, left_vin);
    head->right = reConstructBinaryTree(right_pre, right_vin);

    return head;
}