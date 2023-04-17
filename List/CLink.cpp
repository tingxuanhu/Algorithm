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
    Clink()
    {
        head_ = new Node();
    }
    ~Clink()  // head也要析构掉
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
    void insertTail(int val)
    {
        Node* p = head_;
        while (p->next_ != nullptr)
        {
            p = p->next_;
        }
        Node* cur = new Node(val);
        p->next_ = cur;
    }
    void remove(int val)   // 删第一个值为val的
    {
        Node* p = head_->next_;
        Node* pre = head_;
        while (p != nullptr)
        {
            if (p->val_ != val)
            {
                pre = p;
                p = p->next_;
            }
            else
            {
                pre->next_ = p->next_;
                delete p;
                p = nullptr;
                return;
            }
        }
    }
    void removeAll(int val) // 删除所有值为val的
    {
        Node* p = head_->next_;
        Node* pre = head_;
        while (p != nullptr)
        {
            if (p->val_ != val)
            {
                pre = p;
                p = p->next_;
            }
            else
            {
                pre->next_ = p->next_;
                delete p;
                p = pre->next_;
            }
        }
    }
    bool find(int val)
    {
        Node* p = head_->next_;
        while (p != nullptr)
        {
            if (p->val_ != val)
            {
                p = p->next_;
            }
            else
            {
                return true;
            }
        }
        return false;
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
};




int main()
{

    return 0;
}
