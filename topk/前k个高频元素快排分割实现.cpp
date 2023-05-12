class Solution 
{
public:
    int Partition(vector<pair<int, int>> & v, int l, int r)
    {
        int m = l + ((r - l) >> 1);
        if (v[l].second < v[r].second) swap(v[l], v[r]);   // 让v[l] > v[r]
        if (v[m].second < v[r].second) swap(v[m], v[r]);   // 让v[m] > v[r]
        if (v[m].second < v[l].second) swap(v[m], v[l]);   // 让v[l] <= v[m],这3步使得v[l]处于三者之中

        pair<int, int> tmp = v[l];
        int pivot = tmp.second;
        while (l < r)   // 整体排序逻辑是要从大到小
        {
            // 从右边找起，找到第1个比pivot大的数，换到最左边去
            while (l < r && v[r].second < pivot) { r--; }
            // 如果跳出上面的while是因为v[r] > pivot而不是l==r，那么才执行交换
            if (l < r)  
            {
                v[l] = v[r];
                l++;
            }
            // 和上面类似地，从左边找第1个比pivot小的数，换到最右边去
            while (l < r && v[l].second > pivot) { l++; };
            if (l < r)
            {
                v[r] = v[l];
                r--;
            }
        }
        // 换完后，l++，已经来到了左边比pivot小的下一个位置，也就是要放pivot的位置了
        v[l] = tmp;
        return l;   // pivot位置返回
    }

    // // 递归去Partition，每次只看半边
    // void SelectTopK(vector<pair<int, int>> &nums, int begin, int end, int k)
    // {
    //     int pos = Partition(nums, begin, end);
    //     if (pos + 1 == k)  // vec下标从0开始，pos+1对应着从0号位置到pos位置一共有的元素个数
    //     {
    //         return;
    //     }
    //     else if (pos + 1 > k)
    //     {
    //         SelectTopK(nums, begin, pos - 1, k);
    //     }
    //     else
    //     {
    //         SelectTopK(nums, pos + 1, end, k);
    //     }
    // }

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        // int n = nums.size();
        vector<int> ans;
        
        unordered_map<int, int> map;
        for (auto n : nums)
        {
            ++map[n];
        }

        using Type = pair<int, int>;
        vector<Type> log(map.begin(), map.end());

        int l = 0;
        int r = log.size() - 1;
        int pos = 0;
        while (true)
        {
            pos = Partition(log, l, r);
            if (pos + 1 == k)
            {
                break;
            }
            else if (pos + 1 > k)
            {
                r = pos - 1;
            }
            else
            {
                l = pos + 1;
            }
        }

        // SelectTopK(log, 0, n, k);
        for (int i = 0; i < k; ++i)
        {
            // ans.emplace_back(nums[i]);
            ans.emplace_back(log[i].first);
        }
        return ans;
    }
};
