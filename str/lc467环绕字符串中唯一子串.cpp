/*
定义字符串 base 为一个 "abcdefghijklmnopqrstuvwxyz" 无限环绕的字符串，所以 base 看起来是这样的：

"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
给你一个字符串 s ，请你统计并返回 s 中有多少 不同非空子串 也在 base 中出现。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/unique-substrings-in-wraparound-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution 
{
public:
    int findSubstringInWraproundString(string s) 
    {
        if (s.empty()) return 0;
        int n = s.size();
        if (n == 1) return 1;
        array<int, 128> arr{0};

        int len = 1;
        arr[s[0]]++;
        for (int i = 1; i < n; ++i)
        {
            char pre = s[i - 1];
            char cur = s[i];
            if (cur - pre == 1 || (cur == 'a' && pre == 'z'))
            {
                len++;
            }
            else
            {
                len = 1;
            }
            arr[cur] = max(arr[cur], len);
        }
        
        int ans = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            ans += arr[i];
        }

        return ans;
    }
};
