/* 平衡符号 符号匹配 简易计算器*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;

struct Node;
struct Opreator;
typedef struct Node *PtrToNode;
typedef struct Opreator *PtrToOpe;
// 建栈
typedef PtrToNode Stack;
typedef PtrToOpe Stack_O;

struct Node
{
    double Element;
    PtrToNode next;
};
struct Opreator
{
    char Element;
    PtrToOpe next;
};

// 判空
int Isempty(Stack S)
{
    return S->next == nullptr;
}
int Isempty(Stack_O S)
{
    return S->next == nullptr;
}

// 返回栈顶元素
double Top(Stack S)
{
    if (!(Isempty(S)))
    {
        return S->next->Element;
    }
    return 0;
}

char Top(Stack_O S)
{
    if (!(Isempty(S)))
    {
        return S->next->Element;
    }
    return 0;
}

// 进栈
void Push(Stack S, double x)
{
    PtrToNode TmpCell;
    TmpCell = (Stack)malloc(sizeof(Stack));
    if (TmpCell == nullptr)
        cout << " Out of space!!!";
    else
    {
        TmpCell->Element = x;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}

void Push(Stack_O S, char x)
{
    PtrToOpe TmpCell;
    TmpCell = (Stack_O)malloc(sizeof(Stack));
    if (TmpCell == nullptr)
        cout << " Out of space!!!";
    else
    {
        TmpCell->Element = x;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}

// 出栈
void Pop(Stack s)
{
    PtrToNode FirstCell;
    if (Isempty(s))
        cout << "Empty Stack";
    else
    {
        FirstCell = s->next;
        s->next = s->next->next;
        free(FirstCell);
    }
}
void Pop(Stack_O s)
{
    PtrToOpe FirstCell;
    if (Isempty(s))
        cout << "Empty Stack";
    else
    {
        FirstCell = s->next;
        s->next = s->next->next;
        free(FirstCell);
    }
}

// 建空输出栈
Stack CreatStack(void)
{
    Stack S;
    S = (Stack)malloc(sizeof(Stack));
    if (S == nullptr)
        cout << "Out of space!!!";
    S->next = nullptr;
    return S;
}

// 建空 操作符栈
Stack_O CreatStack_O(void)
{
    Stack_O S;
    S = (Stack_O)malloc(sizeof(Stack_O));
    if (S == nullptr)
        cout << "Out of space!!!";
    S->next = nullptr;
    return S;
}

// 判断操作符
int IsOpreator(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/')
        return 1;
    else if (a == '{' || a == '}' || a == '[' || a == ']' || a == '(' || a == ')')
        return 2;
    else if (a == '=')
        return 3;
    else
        return 0;
}
double Calculate_R(double a, double b, char c)
{
    switch (c)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    default:
        break;
    }
    return 0;
}
// 执行
Stack Opreate()
{
    Stack S = CreatStack();
    Stack_O S_O = CreatStack_O();
    char A[100];
    char B[100];
    char Ope;
    while (1)
    {
        int j = 0;
        if (Top(S_O) == '=')
            break;
        for (int i = 0; i < 100; i++)
        {
            cin >> A[i];
            if (IsOpreator(A[i]) != 0)
            {
                Ope = A[i];
                break;
            }
            else
            {
                B[j++] = A[i];
            }
        }
        double x = atof(B);
        Push(S, x);
        if (Top(S_O) == '*' || Top(S_O) == '/')
        {
            char t = Top(S_O);
            Pop(S_O);
            double p = Top(S);
            Pop(S);
            double q = Top(S);
            Pop(S);
            double re = Calculate_R(q, p, t);
            Push(S, re);
        }
        if (Top(S_O) == ')')
        {

            Pop(S_O);
            while (Top(S_O) != '(')
            {
                char t = Top(S_O);
                Pop(S_O);
                double p = Top(S);
                Pop(S);
                double q = Top(S);
                Pop(S);
                double re = Calculate_R(q, p, t);
                Push(S, re);
            }
            Pop(S_O);
        }

        Push(S_O, Ope);
    }
    Pop(S_O);
    while (S_O->next != nullptr)
    {
        char TmpCell = Top(S_O);
        Pop(S_O);
        double p = Top(S);
        Pop(S);
        double q = Top(S);
        Pop(S);
        double re = Calculate_R(q, p, TmpCell);
        Push(S, re);
    }
    return S;
}

int main()
{
    Stack S = Opreate();
    double result = Top(S);
    cout << result << " " << S->next->next->Element << endl;
}