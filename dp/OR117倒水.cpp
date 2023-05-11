
/*
描述
要把m升的水倒入n个相同的容器中（假设容器足够大），允许有的容量是空的，问共有多少种不同的倒法？（用k表示）5，1，1和1，5，1和1，1，5是同一种倒法。

输入描述：
第一行是测试数据的数目x(0≤x≤20)。以下每行均包含二个整数m和n，以空格分开。1≤m，n≤10。
输出描述：
对输入的每行数据m和n，用一行输出相应的k
*/

#include <bits/stdc++.h>
using namespace std;
// 题目就是问：把大小为m的数分成1~n份，有几种方式

int process(int m, int n)
{
    if (m == 0 || n == 1) return 1;
    if (m < n)   // 最多就m个容器能放进去水
        return process(m, m);

    // 如果m > n，那么有可能每个位置都分到了水，也有可能有的位置没有分到水
    // 可能性1：有的位置没分到水,那么至少有1个容器是空的，m升水可以倒入n-1个容器（这种情况包括了更多容器为空的可能性，是完备的）
    int p1 = process(m, n - 1);
    // 可能性2：每个位置都有水了，雨露均沾的话剩下的m-n的水可以随便往n个容器里倒
    int p2 = process(m - n, n);
    return p1 + p2;
}

int main() 
{
    int x, m, n;
    cin >> x;
    while (x--)
    {
        cin >> m >> n;
        cout << process(m, n) << endl;
    }
    
}
