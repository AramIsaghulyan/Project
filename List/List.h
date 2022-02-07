#include <iostream>

namespace F_list
{
    template <typename T>
    class forward_list
    {
    private:
        struct Node
        {
            T m_data{};
            Node *m_next{};
            Node();
            Node(const T &);
            Node(const T &, Node *);
        };

    public:
        // constructors functions
        forward_list();
        forward_list(const T &);
        void push_front(const T &);
        bool empty() const;
        void show();
        void pop_front();
        void erase(size_t);
        void insert(size_t, const T &);
        T &front();
        void reverse();
        void sort();
        ~forward_list();

    private:
        Node *m_head;
    };
}
