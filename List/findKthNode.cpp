#include <iostream>
using namespace std;

struct Node
{
    Node(int data = 0) : val_(data), next_(nullptr) {}
    int val_;
    Node* next_;
};


class Clink
{
public:
    Clink() { head_ = new Node(); }
    ~Clink()
    {
        Node* p = head_;
        while (p != nullptr)
        {
            head_ = head_->next_;
            delete p;
            p = head_;
        }
        head_ = nullptr;
    }
    void insertHead(int val)
    {
        Node* cur = new Node(val);
        cur->next_ = head_->next_;
        head_->next_ = cur;
    }

    void show()
    {
        Node* p = head_->next_;
        while (p != nullptr)
        {
            cout << p->val_ << " ";
            p = p->next_;
        }
        cout << endl;
    }

private:
    Node* head_;
    friend bool findKthNode(Clink& link, int k, int& val);
};


bool findKthNode(Clink& link, int k, int& val)
{
    Node* head = link.head_;
    Node* p = head;
    Node* q = head;
    if (k < 1) return false;
    for (int i = 0; i < k; ++i)
    {
        q = q->next_;
        if (q == nullptr)
        {
            return false;
        }
    }
    while (q != nullptr)
    {
        q = q->next_;
        p = p->next_;
    }
    val = p->val_;
    return true;
}


int main()
{
    srand(time(0));
    for (int i = 0; i < 10; ++i)
    {
        Clink link;
        for (int j = 0; j < 10; ++j)
        {
            int val = rand() % 100;
            link.insertHead(val);
        }
        link.show();    

        int kval;
        int k = 3;
        if (findKthNode(link, k, kval))
        {
            cout << "倒数第" << k << "个节点的值：" << kval << endl;
        }
    
        cout << endl;
    }

    return 0;
}
