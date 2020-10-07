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

Tree MakeTree()
{
    Tree T;
    T = (Tree)malloc(sizeof(Tree));
    T->FirstChild = nullptr;
    return T;
}
void Insert(Tree T, ElementType X)
{
    if (T == nullptr)
        cout << "Out of space!!!";
    else
    {
        Tree S;
        S = (Tree)malloc(sizeof(Tree));
        S->Element = X;
        if (T->FirstChild == nullptr)
        {
            S->FirstChild = T->FirstChild;
            T->FirstChild = S;
            T->NextSibling = nullptr;
        }
        else if (T->NextSibling == nullptr)
        {
            S->FirstChild = T->NextSibling;
            T->NextSibling = S;
        }
        else
        {
            cout << "Full Tree";
        }
    }
}

int IsEmpty(Tree T)
{
    return T->FirstChild == nullptr;
}
// 树后插入树
Tree InsertTree(Tree T, Tree S)
{
    if (T == nullptr)
        cout << "Out of space";
    else
    {
        if (T->FirstChild == nullptr)
        {
            T->FirstChild = S;
            T->NextSibling = nullptr;
        }
        else if (T->NextSibling == nullptr)
            T->NextSibling = S;
        else
            cout << "Full Tree";
    }
    return T;
}

// 前序遍历
void Front(Tree T)
{
    if (T == nullptr)
        return;
    cout << T->Element;
    Front(T->FirstChild);
    Front(T->NextSibling);
}

// 中序遍历
void Mid(Tree T)
{
    if (T == nullptr)
        return;
    Mid(T->FirstChild);
    cout << T->Element;
    Mid(T->NextSibling);
}

// 后序遍历
void Behind(Tree T)
{
    if (T == nullptr)
        return;
    Behind(T->FirstChild);
    Behind(T->NextSibling);
    cout << T->Element;
}
int main()
{
    Tree T = MakeTree();
    int i = 2;
    Insert(T, i++);
    T = T->FirstChild;
    Tree S = T;
    Insert(T, i++);
    Insert(T, i++);
    T = T->FirstChild;
    Insert(T, i++);
    Insert(T, i++);
    Tree T1 = MakeTree();
    Insert(T1, 0);
    T1 = T1->FirstChild;
    Insert(T1, 1);
    Tree T2= InsertTree(T1, S);
    
    Front(T2);
    cout << endl;
    Mid(T2);
    cout << endl;
    Behind(T2);
}
