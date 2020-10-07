/* 二叉查找树*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;
struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

// Find
SearchTree MakeEmpty(SearchTree T)
{
    if (T != nullptr)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return nullptr;
}

Position Find(ElementType X, SearchTree T)
{
    if (T == nullptr)
        return nullptr;
    if (X < T->Element)
        return Find(X, T->Left);
    else if (X > T->Element)
    {
        return Find(X, T->Right);
    }
    return T;
}

Position FindMin(SearchTree T)
{
    if (T == nullptr)
        return nullptr;
    else if (T->Left == nullptr)
    {
        return T;
    }
    else
        return FindMin(T->Left);
}
Position FindMax(SearchTree T)
{
    if (T == nullptr)
        while (T->Right != nullptr)
        {
            T = T->Right;
        }
    return T;
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if (T == nullptr)
    {
        T = (SearchTree)malloc(sizeof(SearchTree));
        if (T == nullptr)
            cout << "Out of space!!!";
        else
        {
            T->Element = X;
            T->Left=T->Right = nullptr;
        }
    }
    else if (X<T->Element)
    {
        T->Left = Insert(X,T->Left);
    }
    else if (X>T->Element)
    {
        T->Right = Insert(X,T->Right);
    }

    return T;
}

SearchTree Delete(ElementType X,SearchTree T)
{
    Position TmpCell;
    if (T == nullptr)
        cout <<"Element NotFound!!!";
    else if (X<T->Element)
        T->Left = Delete(X,T->Left);
    else if (X>T->Element)
        T->Right = Delete(X,T->Left);
    else if (T->Left&&T->Right)
    {
        TmpCell = FindMin(T->Right);
        T->Element = T->Element;
        T->Right = Delete(T->Element,T->Right);
    }
    else
    {
        TmpCell = T;
        if(T->Left == nullptr)
            T = T->Right;
        else if (T->Right == nullptr)
        {
            T = T->Left;
            free(TmpCell);
        }
    }
    return T;
}