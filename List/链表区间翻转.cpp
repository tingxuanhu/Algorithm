/**
给你单链表的头指针 head ,整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reverse-linked-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if (head == nullptr) return nullptr;
        ListNode *preNode = new ListNode(0);
        preNode->next = head;

        ListNode *head_ = preNode;
        for (int i = 1; i < left; ++i)
        // while (--left)
        {
            head_ = head_->next;
        }
      
        int cnt = right - left;
        ListNode *tail_ = head_->next;
        for (int i = 0; i < cnt; ++i)
        {
            ListNode *insertNode = tail_->next;
            tail_->next = tail_->next->next;

            ListNode *headNode = head_->next;
            head_->next = insertNode;
            insertNode->next = headNode;
        }

        return preNode->next;
    }
};
