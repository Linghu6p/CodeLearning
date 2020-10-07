// 表达式树建立
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cctype>

#define EmptyOS (-1)
#define MinStakeSize (5)

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Tree;
struct StackRecord;
typedef struct StackRecord *Stack;
using namespace std;
struct Node
{
    char data;
    Tree left;
    Tree right;
};

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    Tree *Array;
};

void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyOS;
}

void DisposeStack(Stack S)
{
    if (S != nullptr)
    {
        free(S->Array);
        free(S);
    }
}
Stack CreatStack(int MaxElements)
{
    Stack S;
    if (MaxElements < MinStakeSize)
        cout << "StackSize is too small";
    S = (Stack)malloc(sizeof(Stack));
    if (S == nullptr)
        cout << " Out of space!!!";
    S->Array = (Tree *)malloc(sizeof(Tree) * MaxElements);
    if (S->Array == nullptr)
        cout << "Out of space!!";
    S->Capacity = MaxElements;
    MakeEmpty(S);
    return S;
}

int Isempty(Stack S)
{
    return S->TopOfStack == EmptyOS;
}
/*
int IsFull(Stack S)
{
    return S->Capacity >= sizeof(S->Array) / sizeof(Tree);
}
*/
void Push(Tree T, Stack S)
{
    S->Array[++S->TopOfStack] = T;
}
Tree TopAndPop(Stack S)
{
    if (!Isempty(S))
        return S->Array[S->TopOfStack--];
    cout << " Empty Stack";
    return 0;
}

Tree Top(Stack S)
{
    if (!Isempty(S))
        return S->Array[S->TopOfStack];
    cout << "Empty Stack";
    return 0;
}

Tree MakeTree(char X)
{
    Tree T;
    T = (Tree)malloc(sizeof(Tree));
    T->data = X;
    T->left = nullptr;
    T->right = nullptr;
    return T;
}
void Insertleft(Tree T, char X)
{
    if (T == nullptr)
        cout << "Out of space";
    else
    {
        if (T->left == nullptr)
        {
            Tree S;
            S = (Tree)malloc(sizeof(Tree));
            S->data = X;
            S->left = T->left;
            T->left = S;
            S->right = nullptr;
        }
        else
        {
            cout << "left son has data";
        }
    }
}
void Insertright(Tree T, char X)
{
    if (T == nullptr)
        cout << "Out of space";
    else
    {
        if (T->right == nullptr)
        {
            Tree S;
            S = (Tree)malloc(sizeof(Tree));
            S->data = X;
            S->left = T->right;
            T->right = S;
            S->right = nullptr;
        }
        else
        {
            cout << "right son has data";
        }
    }
}

void InsertTreeleft(Tree T, Tree S)
{
    if (T == nullptr)
        cout << "Out of space";
    else
    {
        if (T->left == nullptr)
        {
            T->left = S;
        }
        else
        {
            cout << "Left son has data";
        }
    }
}
void InsertTreeright(Tree T, Tree S)
{
    if (T == nullptr)
        cout << "Out of space";
    else
    {
        if (T->right == nullptr)
        {
            T->right = S;
        }
        else
        {
            cout << "Right son has data";
        }
    }
}

void pre_order(Tree T)
{
    if (T == nullptr)
        return;
    else
    {
        cout << T->data << endl;
        pre_order(T->left);
        pre_order(T->right);
    }
}
void mid_order(Tree T)
{
    if (T == nullptr)
        return;
    else
    {
        mid_order(T->left);
        cout << T->data << " ";
        mid_order(T->right);
    }
}
int Jud(char a)
{
    switch (a)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return 1;
        break;

    default:
        return 0;
        break;
    }
}
Stack opt(char A[], int n)
{
    Stack S = CreatStack(10);
    int i = 0;
    while (i < n)
    {
        Tree T = MakeTree(A[i++]);
        Push(T, S);
        if (Jud(Top(S)->data))
        {
            Tree X = MakeTree(TopAndPop(S)->data);
            InsertTreeright(X, TopAndPop(S));
            InsertTreeleft(X, TopAndPop(S));
            Push(X, S);
        }
    }
    return S;
}

int main()
{
    string s;
    cin >> s;
    int count = s.size();
    char A[count];
    int k = 0;
    for (auto i : s)
        A[k++] = i;
    Stack S = opt(A, count);
    Tree T = Top(S);
    mid_order(T);
}