/* 数组建队*/
#include <iostream>
#include <cstring>
#include <cstdlib>

#define MinQueueSize (5)

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

using namespace std;
struct QueueRecord
{
    int Capacity; //队列的容量
    int Front;    // 队头
    int Rear;     // 队尾
    int Size;     // 队长
    ElementType *Array;
};

int Isempty(Queue Q)
{
    return Q->Size == 0;
}

// 建空队
void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

static int Succ(int Value, Queue Q)
{
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}

// 入队
void Enqueue(ElementType X, Queue Q)
{
    if (IsFull(Q))
        cout << "Full Queue";
    else
    {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}
// 出队
void Dequeue(Queue Q)
{
    if (Isempty(Q))
        cout << "Empty Queue!!!";
    else
    {
        Q->Front++;
        Q->Size--;
    }
}