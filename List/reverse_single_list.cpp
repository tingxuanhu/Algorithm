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
    friend void ReverseList(Clink& link);
};


void ReverseList(Clink& link)
{
    Node* p = link.head_->next_;
    if (p == nullptr) return; 
    link.head_->next_ = nullptr;
    
    while (p != nullptr)
    {
        Node* q = p->next_;  // 记录p将要移动去的位置，否则就找不着了
        p->next_ = link.head_->next_;
        link.head_->next_ = p;
        p = q;
    }
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
        
        ReverseList(link);
        link.show();
        cout << endl;
    }

    return 0;
}
