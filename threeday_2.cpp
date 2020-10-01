/* 数组建栈*/
#include <iostream>
#include <cstring>
#include <cstdlib>

#define EmptyOS (-1)
#define MinStakeSize (5)

struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

using namespace std;
struct StackRecord
{
    int Capacity;   //栈的容量
    int TopOfStack; //栈顶元素
    ElementType *Array;
};

// 栈顶为-1 类似于数组下标为-1建立空栈
void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyOS;
}

// 释放栈
void DisposeStack(Stack S)
{
    if (S != nullptr)
    {
        free(S->Array);
        free(S);
    }
}
// 数组实现建栈
Stack CreateStack(int MaxElements)
{
    Stack S;

    if (MaxElements < MinStakeSize)
        cout << "StackSize is too small";
    S = (Stack)malloc(sizeof(Stack));
    if (S == nullptr)
        cout << " Out of space!!!";
    // 之所以要在molloc前是因为c++需要强制转化 malloc返回的是一个void类型
    // 为数组分配空间
    S->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    if (S->Array == nullptr)
        cout << "Out of space !!!";
    S->Capacity = MaxElements;
    MakeEmpty(S);

    return S;
}

// 判空
int Isempty(Stack S)
{
    return S->TopOfStack == EmptyOS;
}
// 判满
int IsFull(Stack S)
{
    return S->Capacity >=sizeof(S->Array)/sizeof(ElementType);
}

// 元素进栈
void Push(ElementType X, Stack S)
{
    if (IsFull(S))
        cout << " Full Stack";
    else
        S->Array[++S->TopOfStack]=X;
}

// 元素出栈
void Pop(Stack S)
{
    if (Isempty(S))
        cout<< "Empty Stack";
    else
        S->TopOfStack--; 
}

// 元素出栈并返回他的值
ElementType TopAndPop(Stack S)
{
    if(!Isempty(S))
        return S->Array[S->TopOfStack--];
    cout<<" Empty Stack";
    return 0;
}

// 返回栈顶元素

ElementType Top(Stack S)
{
    if(Isempty(S))
        return S->Array[S->TopOfStack];
    cout<<"Empty Stack";
    return 0;
}
