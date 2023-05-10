/*
对于一个长度为 n 字符串，我们需要对它做一些变形。

首先这个字符串中包含着一些空格，就像"Hello World"一样，然后我们要做的是把这个字符串中由空格隔开的单词反序，同时反转每个字符的大小写。

比如"Hello World"变形后就变成了"wORLD hELLO"。

数据范围: 
1≤n≤10 6  , 字符串中包括大写英文字母、小写英文字母、空格。
进阶：空间复杂度O(n) ， 时间复杂度 O(n)

输入描述：
给定一个字符串s以及它的长度n(1 ≤ n ≤ 10^6)
返回值描述：
请返回变形后的字符串。题目保证给定的字符串均由大小写字母和空格构成。
*/

#include <cctype>
class Solution 
{
public:
    // 此题变难可以考虑前导空格，中间多余的空格和尾部多加的空格
    void swap_(string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; ++i, --j)
        {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }


    string trans(string s, int n)   // main 入口
    {
        int right = 0;
        while (right < s.size())
        {
            int left = right;
            
            while (right < s.size() && s[right] != ' ')
            {
                ++right;
            }

            // s[right] == ' '
            swap_(s, left, right - 1);

            while (right < s.size() && s[right] == ' ')
            {
                ++right;
            }
        }

        // 整体翻转
        reverse(s.begin(), s.end());

        // 大小写转换,transform(迭代器开始，迭代器终止，输出开始位置，1元或2元函数)
        std::transform(s.begin(), s.end(), s.begin(), [](char c) 
        {
            return isupper(c) ? tolower(c) : toupper(c);  // tolower只针对大写字符有效，其他字符输入tolower输出不变化
        });

        return s;

    }
};
