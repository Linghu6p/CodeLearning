#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "list"
#include <cmath>
#define N 100

using namespace std;
/* 多项式*/

/* bucket sort 桶式排序*/
// 3 5 1 6 2 4 8
int FindA_max(int A[], int n)
{
    int max = A[0];
    for (auto i = 0; i < n; ++i)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}
// 3 5 1 6 2 4 8
/* 一次性遍历 浪费时间空间*/
void bucket_sort_1(int A[], int n)
{
    int M;
    // 构建m个桶
    M = FindA_max(A, n);
    int count[M + 1];
    // 将count中的所有元素置0
    memset(count, 0, sizeof(count));
    // 将所有数字放入桶中
    for (int i = 0; i < n; ++i)
    {
        count[A[i]]++;
    }
    for (int i = 0; i <= M; ++i)
    {
        while (count[i] > 0)
        {
            cout << i;
            count[i]--;
        }
    }
}

int get_rows(int M)
{
    int row = 0;
    while (M)
    {
        M = M / 10;
        row++;
    }
    return row;
}
/* 插入桶*/
void bucket_sort_2_1(int A[], int n, int bit)
{

    int count[N][N];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n; i++)
    {
        // 16 16 
        int p = A[i] / pow(10, bit);
        p = p % 10;
        for (int j = 0; j < N; j++)
        {
            if (count[p][j] == 0)
            {
                count[p][j] = A[i]; //第一次上传错误 误写成 == 这里只是返回了一个bool类型 所以程序错误
                break;
            }
        }
    }
    int cnt = 0;
    // 重新组织数组
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (count[i][j] == 0)
            {
                break;
            }
            A[cnt++] = count[i][j];
        }
    }
} 

/* 最终码*/
void bucket_sort_2_2(int A[], int n, int rows)
{
    for (auto i = 0; i < rows; i++)
    {
        bucket_sort_2_1(A, n, i);
    }
}
int main()
{
    int n;
    int A[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    int M = FindA_max(A,n);
    int rows = get_rows(M);
    
    bucket_sort_2_2(A, n, rows);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    
}
