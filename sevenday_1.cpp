#include <iostream>
#include <cstring>
#include <cstdlib>
#

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Tree;

using namespace std;

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
void post_order(Tree T)
{
    if (T == nullptr)
        return;
    else
    {
        post_order(T->left);
        post_order(T->right);
        cout << T->data << " ";
    }
}
int main()
{
    int i = 0;
    Tree T = MakeTree(i++);
    Tree S = T;
    Insertleft(T, i++);
    Insertright(T, i++);
    T = T->left;
    Insertleft(T, i++);
    Insertright(T, i++);
    T = S->right;
    Insertleft(T, i++);
    Insertright(T, i++);
    T = T->left;
    Insertleft(T, i++);
    Insertright(T, i++);

    pre_order(S);
    cout << endl;
    mid_order(S);
    cout << endl;
    post_order(S);
}
