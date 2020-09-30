/* 栈*/
/* 未用模板描述*/
/* 头插建栈*/
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Node;
typedef struct Node *PtrToNode;
// 建栈
typedef PtrToNode Stack;
typedef int ElementType;

struct Node
{
    ElementType Element;
    PtrToNode next;
};

// 判空
int Isempty(Stack S)
{
    return S->next==nullptr;
}

// 返回栈顶元素
ElementType Top(Stack S)
{
    if (!(Isempty(S)))
    {
        return S->next->Element;
    }
    cout<<"Empty Stack";
    return 0;
}

// 进栈
void Push(Stack S,ElementType x)
{
    PtrToNode TmpCell;
    TmpCell = (Stack)malloc(sizeof(Stack));
    if (TmpCell == nullptr)
        cout << " Out of space!!!";
    else
    {
        TmpCell->Element = x;
        TmpCell->next= S->next;
        S->next = TmpCell;
    }
}

// 12 3 5 
// 出栈
void Pop(Stack s)
{
    PtrToNode FirstCell;
    if(Isempty(s))
        cout<<"Empty Stack";
    else
    {
        FirstCell = s->next;
        s->next=s->next->next;
        free(FirstCell);
    }
    
}
// 建空栈
void Make_Empty(Stack S)
{
    if(S==nullptr)
    {
        cout<<"Error!";
    }
    else
    {
        while (!(Isempty(S)))
        {
            Pop(S);
        }
        
    }
}

Stack CreatStack(void)
{
    Stack S;
    S = (Stack)malloc(sizeof(S));
    if(S== nullptr)
        cout<<"Out of space!!!";
    S->next == nullptr;
    Make_Empty(S);
    return S;
}



