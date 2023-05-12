//   给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。
class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> map;
        for (auto n : nums)
        {
            map[n]++;
        }

        using Type = pair<int, int>;
        using Comp = function<bool(Type&, Type&)>;
        priority_queue<Type, vector<Type>, Comp> maxheap([] (Type &lhs, Type &rhs) -> bool
        {
            return lhs.second > rhs.second;
        });

        auto it = map.begin();
        for (int i = 0; i < k; ++i, ++it)
        {
            maxheap.emplace(*it);
        }

        for (; it != map.end(); ++it)
        {
            // 小根堆元素堆顶和当前遍历到的元素比较大小，如果当前元素更大一些，就把堆顶元素赶走
            if (it->second > maxheap.top().second)
            {
                maxheap.pop();
                maxheap.emplace(*it);
            }
        }

        vector<int> ans;
        while (!maxheap.empty())
        {
            ans.emplace_back(maxheap.top().first);
            maxheap.pop();
        }

        return ans;
    }
};
