/* 最大子序列求和*/
/* Summation of maximal subsequence*/

#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;
// 4 5 6 -8
/* 连机算法*/

int on_line_algorithm(int A[], int n)
{
    int maxsum = 0, t = 0;
    for (auto i = 0; i < n; ++i)
    {
        t += A[i];
        if (t >= maxsum)
            maxsum = t;
        else if (t < 0)
            t = 0;
    }
    return maxsum;
}

/* 对分查找 修改完毕
*/
int max3(int a, int b, int c)
{
    int k = max(a, b);
    return max(k, c);
}
static int MaxSubsuM(const int A[], int Left, int Right)
{
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum = 0, MaxRightborderSum = 0;
    int LeftBorderSum = 0, RightBorderSum = 0;
    if (Left == Right)
    {
        if (A[Left] > 0)
        {
            return A[Left];
        }
        else
        {
            return 0;
        }
    }
    /**/
    int center;
    center = (Left + Right) / 2;
    MaxLeftSum = MaxSubsuM(A, Left, center);
    MaxRightSum = MaxSubsuM(A, center + 1, Right);
    for (int i = center; i >= Left; i--)
    {
        LeftBorderSum += A[i];
        if (LeftBorderSum > MaxLeftBorderSum)
        {
            MaxLeftBorderSum = LeftBorderSum;
        }
    }
    for (int i = center + 1; i <= Right; i++)
    {
        RightBorderSum += A[i];
        if (RightBorderSum > MaxRightborderSum)
        {
            MaxRightborderSum = RightBorderSum;
        }
    }
    return max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightborderSum);
}

int Result(const int A[], int N)
{
    return MaxSubsuM(A, 0, N - 1);
}

int main()
{
    int n;
    int A[100];
    cin >> n;
    for (auto i = 0; i < n; ++i)
    {
        cin >> A[i];
        //cout << A[i] << " ";
    }
    cout << MaxSubsuM(A, 0, n - 1) << " " << Result(A, n);
}
