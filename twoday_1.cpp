/*List*/

#include <iostream>
#include <string>
#include <cstring>
#define N 100;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;
using namespace std;

struct Node
{
    ElementType Element;
    Position next;
};
// 建空表
void Makeempty(List L)
{
    L = (List)malloc(sizeof(List));
    L->next = nullptr;
}

int IsEmpty(List L)
{
    return L->next == nullptr;
}
// 插入
void Insert(ElementType X, List L, Position p)
{
    Position TmpCell;
    TmpCell = (List)malloc(sizeof(List));
    if (TmpCell == nullptr)
        cout << "Out of space!!!" << endl;
    TmpCell->Element = X;
    TmpCell->next = p->next;
    p->next = TmpCell;
}
/*
void Delete(List L,ElementType X)
{

}
*/
// 循环表建立
void CreatcurcleList(List L, ElementType A[], ElementType n)
{
    Makeempty(L);
    Position p, k;
    p = L;
    for (auto i = 0; i < n; ++i)
    {
        Insert(A[i], L, p);
        p = p->next;
    }
    k = L->next;
    p->next = k;
    // return TmpCell;
}
// 5 2 1 3 5

// Josephus 约瑟夫
void Func(List L, ElementType A[], ElementType m, ElementType n)
{
    CreatcurcleList(L, A, n);
    Position p = L;
    for (int i = 0; i < n; ++i)
    {
        ElementType x;
        Position TmpCell;
        for (int j = 0; j < m; ++j)
        {
            p = p->next;
        }
        TmpCell = p->next;
        cout << TmpCell->Element << " ";
        p->next = TmpCell->next;
        free(TmpCell);
    }
}
int main()
{
    List L;
    int A[100];
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        //cout << A[i];
    }

    //CreatcurcleList(L, A,n);
    //cout << L->next->Element;
    Func(L, A, m, n);
}
