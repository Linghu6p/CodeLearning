/* 树*/
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// 树的定义

typedef struct TreeNode *PtrToNode;
typedef PtrToNode Tree;
typedef int ElementType;
struct TreeNode
{
    ElementType Element;
    Tree FirstChild;  //第一个子节点 在二叉树里可以理解为左节点
    Tree NextSibling; //相邻的兄弟节点
};