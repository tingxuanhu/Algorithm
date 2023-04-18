// https://www.nowcoder.com/practice/46bda7f0570a47b6b54a29a0a6ae4c27?tpId=182&tqId=34634&ru=/exam/oj
// 合并两个有序链表
#include <iostream>
#include <sstream>
using namespace std;

struct Node
{
    int val;
    Node* next{};
    Node(int v = 0): val(v) {}
};

class LinkedList
{
public:
    LinkedList() : head(new Node()), tail(head) {}
    void addFromTail(int val)
    {
        Node* p = new Node(val);
        tail->next = p;
        tail = tail->next;
        size_++;
    }
    int length()
    {
        return size_;
    }
    void show()
    {
        Node* p = head->next;
        while (p != nullptr) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

private:
    Node* head;
    Node* tail;
    int size_ = 0;
    friend void mergeList(LinkedList& src, LinkedList& tgt);
};


void mergeList(LinkedList& src, LinkedList& tgt)
{
    // 让tgt更长一些，把短的src往长的tgt上接
    int lenSrc = src.length();
    int lenTgt = tgt.length();
    if (lenSrc > lenTgt)
    {
        LinkedList tmp = src;
        src = tgt;
        tgt = tmp;
    }
    Node* sp = src.head->next;
    Node* tp = tgt.head->next;
    // if (sp == nullptr && tp == nullptr) return;  // src tgt 都是空
    // else if (sp == nullptr && tp != nullptr) //  （因为src更短，所以不存在src不空tgt为空)
    // {
    //     return;
    // }
    
    // 剩下的就是src和tgt都非空的情况
    Node* last = tgt.head;
    while (sp != nullptr && tp != nullptr)
    {
        if (sp->val < tp->val)
        {
            last->next = sp;
            sp = sp->next;
            last = last->next;
        }
        else
        {
            last->next = tp;
            tp = tp->next;
            last = last->next;
        }
    }
    if (sp != nullptr) 
    { 
        last->next = sp; 
    }
    if (tp != nullptr) 
    {
        last->next = tp; 
    }
}


int main() {
    LinkedList src;
    LinkedList tgt;
    int val;
    string line;
    getline(cin, line);
    istringstream iss(line);
    while (iss >> val)
    {
        src.addFromTail(val);
    }

    line.clear();
    getline(cin, line);
    iss.str(line);
    iss.clear();
    while (iss >> val)
    {
        tgt.addFromTail(val);
    }
    
    mergeList(src, tgt);
    tgt.show();
    return 0;

}
