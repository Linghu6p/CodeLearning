/* Avl树 平衡二叉树*/
/* 旋转树*/
#include <iostream>
#include <cctype>
#include <vector>
#include <stack>
#include <vector>

using namespace std;

struct AvlNode;

typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
typedef int ElementType;

struct AvlNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

static int Height(Position P)
{
    if (P == nullptr)
        return -1;
    else
        return P->Height;
}

// 单旋转
static Position SingleRotateWithLeft(Position K2)
{
    Position K1;
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
    K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = max(Height(K1->Left), Height(K1->Right)) + 1;
    return K1;
}

// 双旋转
static Position DoubleRotateWithLeft(Position K3)
{
    K3->Left = SingleRotateWithLeft(K3->Left);
    return SingleRotateWithLeft(K3);
}

/* 建立Avl树 并插入节点*/
AvlTree Insert(ElementType X, AvlTree T)
{
    if (T == nullptr)
    {
        T = (AvlTree)malloc(sizeof(AvlTree));
        if (T == nullptr)
            cout << "Out of space!!!";
        else
        {
            T->Element = X;
            T->Height = 0;
            T->Left = T->Right = nullptr;
        }
    }
    else if (X < T->Element)
    {
        T->Left = Insert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2)
            if (X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
    }
    else if (X > T->Element)
    {
        T->Right = Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2)
            if (X > T->Right->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
    }
    T->Height = max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}
