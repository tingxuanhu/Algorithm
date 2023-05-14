/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        // ends记录它下标索引+1长度所对应的最长递增子序列的最末尾元素的最小值
        vector<int> ends(n, 0);
        int right = 0;
        int res = 1;

        ends[0] = nums[0];
        for (int i = 0; i < n; ++i)
        {
            int l = 0;
            int r = right;

            while (l <= r)
            {
                int m = l + (r - l) / 2;
                if (nums[i] > ends[m])
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }

            // l代表二分查找ends后，ends里≥ nums[i]的最小位置,那么l可以更新这个位置，因为比这个位置的数小同时又比前面的数大
            ends[l] = nums[i]; 
            // 如果l扩充了右边界，那么右边界要换一下
            right = max(right, l);  
            
            res = max(res, l + 1);
        }

        return res;
    }
};
