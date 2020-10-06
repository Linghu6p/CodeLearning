#include <iostream>
#include <cstring>
#include <cstdlib>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Tree;

using namespace std;

/*树后插树*/
struct Node
{
    int data;
    Tree left;
    Tree right;
};

Tree MakeTree(int X)
{
    Tree T;
    T = (Tree)malloc(sizeof(Tree));
    T->data = X;
    T->left = nullptr;
    T->right = nullptr;
    return T;
}
void Insertleft(Tree T, int X)
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
void Insertright(Tree T, int X)
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
        cout << T->data << " ";
        pre_order(T->left);
        pre_order(T->right);
    }
}

int main()
{
    int i = 0;
    Tree S_1;
    Tree S_3;
    Tree T = MakeTree(i++);
    S_1 = T;
    S_3 = T;
    Insertleft(T, i++);
    Insertright(T, i++);
    T = T->left;
    Insertleft(T, i++);
    Insertright(T, i++);
    S_1 = S_1->right;
    Insertleft(S_1, i++);
    Tree S = MakeTree(i++);
    Tree S_2 = S;
    Insertleft(S, i++);
    Insertright(S, i++);
    S = S->left;
    Insertleft(S, i++);
    Insertright(S, i++);
    InsertTreeright(S_1, S_2);
    pre_order(S_3);
}