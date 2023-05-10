/* 
给定正整数 k ，你需要找出可以被 k 整除的、仅包含数字 1 的最 小 正整数 n 的长度。
返回 n 的长度。如果不存在这样的 n ，就返回-1。
注意： n 不符合 64 位带符号整数。

示例 1：

输入：k = 1
输出：1
解释：最小的答案是 n = 1，其长度为 1。
示例 2：

输入：k = 2
输出：-1
解释：不存在可被 2 整除的正整数 n 。
示例 3：

输入：k = 3
输出：3
解释：最小的答案是 n = 111，其长度为 3。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/smallest-integer-divisible-by-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution 
{
public:
    int smallestRepunitDivByK(int k) 
    {
        unordered_set<int> set;
        int len = 1;
        int mod = 1 % k;
        set.emplace(mod);

        while (mod != 0)
        {
            mod = (mod * 10 + 1) % k;    // 一开始是写的num，每轮*10再+1，然后再用num % k得到mod，但整型可能会溢出，所以直接考虑mod就行
            ++len;
            if (set.find(mod) != set.end())
                return -1;
            set.emplace(mod);
        }

        return len;
    }
};


