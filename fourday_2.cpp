#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;
#define N 100

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

int JudOpt(char a)
{
    switch (a)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
    case '=':
        return 1;
        break;
    default:
        return 0;
        break;
    }
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
        if (b != 0)
            return a / b;
        else
            cout << "Error";
        break;
    default:
        break;
    }
    return 0;
}
void Result(char A[])
{
    Stack s = CreatStack();
    Stack_O s1 = CreatStack_O();
    char TmpCell;
    char B[100];
    char a[100];
    double x;

    int i = 0;
    while (1)
    {
        int rec = 0;
        if (Top(s1) == '=')
            break;
        for (int j = 0; j < 100; j++)
        {
            int k = JudOpt(A[i]);
            if (k != 1)
            {
                B[j] = A[i];
                rec += 1;
                i++;
            }
            else
            {
                TmpCell = A[i];
                i++;
                break;
            }
        }
        if (rec >= 1)
        {
            x = atof(B);
            Push(s, x);
        }
        if (TmpCell != '(')
        {
            if (Top(s1) == '*' || Top(s1) == '/')
            {
                char t = Top(s1);
                Pop(s1);
                double a = Top(s);
                Pop(s);
                double b = Top(s);
                Pop(s);
                double Re = Calculate_R(b, a, t);
                Push(s, Re);
            }
        }
        if (Top(s1) == ')')
        {
            Pop(s1);
            while (1)
            {
                if (Top(s1) == '(')
                {
                    Pop(s1);
                    break;
                }
                char t = Top(s1);
                Pop(s1);
                double a = Top(s);
                Pop(s);
                double b = Top(s);
                Pop(s);
                double Re = Calculate_R(b, a, t);
                Push(s, Re);
            }
        }
        Push(s1, TmpCell);
    }
    Pop(s1);

    Stack cs = CreatStack();
    double cx;
    Stack_O cs1 = CreatStack_O();
    char cc;
    while (s->next != nullptr)
    {
        cx = Top(s);
        Pop(s);
        Push(cs, cx);
    }
    while (s1->next != nullptr)
    {
        cc = Top(s1);
        Pop(s1);
        Push(cs1, cc);
    }
    while (cs1->next != nullptr)
    {
        char t = Top(cs1);
        Pop(cs1);
        double a = Top(cs);
        Pop(cs);
        double b = Top(cs);
        Pop(cs);
        double re = Calculate_R(a, b, t);
        Push(cs, re);
    }
    cout << Top(cs);
}

int main()
{
    char A[100];
    for (int i = 0; i < 100; ++i)
    {
        cin >> A[i];
        if (A[i] == '=')
            break;
    }
    Result(A);
}

/*
int main()
{
    char a[100];
    for (int i = 0; i < 100; i++)
    {
        cin >> a[i];
        if (JudOpt(a[i]) == 0)
            break;
        cout << JudOpt(a[i]);
    }
}
*/