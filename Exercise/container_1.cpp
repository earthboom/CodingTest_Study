#include <iostream>
#include <algorithm>

using namespace std;

struct sl_node
{
    int data;
    sl_node* next;
};

class sl
{
private:    
    sl_node* head;

public:
    void push_front(int v)
    {
        auto _node = new sl_node{v, nullptr};
        if(head != nullptr)
            _node->next = head;
        head = _node;
    }

    void pop_front(void)
    {
        auto _first = head;
        if(head)
        {
            head = head->next;
            delete _first;
        }
    }

    struct sl_iterator
    {
    private:
        sl_node* ptr;

    public:
        sl_iterator(sl_node* _p) : ptr(_p){}

        int& operator*(){return ptr->data;}

        sl_node* get() { return ptr; }

        sl_iterator& operator++(void)
        {
            ptr = ptr->next;
            return *this;
        }

        sl_iterator operator++(int)
        {
            sl_iterator _sl = *this;
            ++(*this);
            return _sl;
        }

        friend bool operator==(const sl_iterator& l, const sl_iterator&r)
        {
            return l.ptr == r.ptr;
        }

        friend bool operator!=(const sl_iterator& l, const sl_iterator&r)
        {
            return l.ptr != r.ptr;
        }
    };

    sl_iterator begin() { return sl_iterator(head); }
    sl_iterator end() { return sl_iterator(nullptr); }
    sl_iterator begin() const { return sl_iterator(head); }
    sl_iterator end() const { return sl_iterator(nullptr); }

    sl() = default;

    sl(const sl& o) : head(nullptr)
    {
        if(o.head)
        {
            head = new sl_node{0, nullptr};
            auto cur = head;
            auto it = o.begin();
            
            while(true)
            {
                cur->data = *it;

                auto tmp = it;
                ++tmp;

                if(tmp == o.end())
                    break;

                cur->next = new sl_node{0, nullptr};
                cur = cur->next;
                it = tmp;
            }
        }
    }

    sl(const initializer_list<int>& ilist) : head(nullptr)
    {
        for(auto it = rbegin(ilist); it != rend(ilist); it++)
            push_front(*it);
    }
};

int main()
{
    sl sll = {1, 2, 3};
    sll.push_front(0);

    cout << "first list : ";
    for(auto i : sll)
        cout << i << " ";
    cout << endl;

    auto sll2 = sll;
    sll2.push_front(-1);
    for(auto i : sll2)
        cout << i << " ";
    cout << endl;

    for(auto i : sll)
        cout << i << " ";
    cout << endl;    
}