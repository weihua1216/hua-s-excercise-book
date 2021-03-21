/* buildTree
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
来源:leetcode
完成日期:
*/

#include <stdio.h>

struct treenode
{
    int date;
    struct treenode *left;
    struct treenode *right;
};

struct treenode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
    int points[4];
    points[0] = 0;
    points[1] = preorderSize;
    points[2] = 0;
    points[3] = inorderSize;
    return build(preorder, inorder, points, preorderSize, inorderSize);
}

struct treenode *build(int *preorder, int *inorder, int *points, int preSize, int inSize)
{
    struct treenode tree;
    int a = preorder[points[0]];
    int max = points[3], min = points[0];
    int p = find(a, inorder, points[2], points[3]);
    tree.date = a;
    if (p > min)
    {
        points[0] = points[0]++;
        points[1] = points[0] + p;
        points[2] = p - (points[1] - points[0]);
        points[3] = p - 1;
        tree.left = build(preorder, inorder, points, points[1] - points[0], points[3] - points[2]);
    }
    if (p < max)
    {
        points[0] = points[1]++;
        points[1] = max;
        points[2] = p + (points[1] - points[0]);
        points[3] = p + 1;
        tree.right = build(preorder, inorder, points, points[1] - points[0], points[3] - points[2]);
    }
    return &tree;
}

int find(int target, int *nums, int head, int tail)
{
    for (int i = head; i <= tail; i++)
    {
        if (nums[i] == target)
            return i;
    }
}