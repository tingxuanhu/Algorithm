// https://www.nowcoder.com/questionTerminal/e5d90aac4c8b4628aa70d9b6597c0560
// 移除第k个链表节点
#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int v=0) : val(v), next(nullptr) {}
};

class LinkedList
{
public:
    LinkedList(): head(new Node()), tail(head) {}

    void addNode(int val)
    {
        Node* p = new Node(val);
        tail->next = p;
        tail = tail->next;
        size++;
    }

    void removeKthNode(int k)
    {
        Node* lp = this->head->next;
        Node* fp = this->head->next;
        Node* pre = this->head;   // 记录删除节点的前一个
        if (lp == nullptr) return;
        while (k--)
        {
            fp = fp->next;
            if (fp == nullptr) // 没有k个元素，自然没有倒数第k个
            {
                return;
            }
        }

        while (fp != nullptr)
        {
            fp = fp->next;
            lp = lp->next;
            pre = pre->next;
        }

        pre->next = lp->next;
        delete lp;
        lp = nullptr;
    }

    void show()
    {
        Node* p = head->next;
        while (p != nullptr)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

private:
    Node* head;
    Node* tail;
    int size = 0;
};


int main() {
    int n, k, val;
    cin >> n >> k;
    LinkedList list_;
    while (n--)
    {
        cin >> val;
        list_.addNode(val);
    }

    list_.removeKthNode(k);
    list_.show();
}
