#include "List.h"

template <typename T>
void F_list::forward_list<T>::push_front(const T &data)
{

    if (empty())
    {
        m_head = new Node(data);
    }
    else
    {
        Node *tmp = new Node(data, m_head);
        m_head = tmp;
    }
}

template <typename T>
F_list::forward_list<T>::Node::Node() : m_data{NULL}, m_next{nullptr}
{
}

template <typename T>
F_list::forward_list<T>::Node::Node(const T &data) : m_data{data}, m_next{nullptr}
{
}

template <typename T>
F_list::forward_list<T>::Node::Node(const T &data, forward_list<T>::Node *next) : m_data{data}, m_next{next}
{
}

template <typename T>
F_list::forward_list<T>::~forward_list()
{
    while (m_head->m_next != nullptr)
    {
        Node *tmp = m_head->m_next;
        delete m_head;
        m_head = tmp;
    }
    delete m_head;
}

template <typename T>
F_list::forward_list<T>::forward_list()
{
}

template <typename T>
void F_list::forward_list<T>::show()
{
    Node *tmp = m_head;
    while (tmp != nullptr)
    {
        std::cout << tmp->m_data;
        tmp = tmp->m_next;
    }
}

template <typename T>
bool F_list::forward_list<T>::empty() const
{
    if (m_head == nullptr)
    {
        return true;
    }
    return false;
}

template <typename T>
void F_list::forward_list<T>::pop_front()
{
    if (empty())
    {
        throw std::logic_error("List is empty ");
    }
    else
    {
        Node *tmp = m_head->m_next;
        delete m_head;
        m_head = tmp;
    }
}

template <typename T>
void F_list::forward_list<T>::erase(size_t pos)
{
    if (pos == 1)
    {
        Node *tmp = m_head->m_next;
        tmp = tmp->m_next;
        delete tmp;
    }
    else
    {
        Node *prev = m_head;
        Node *tmp = m_head->m_next;
        pos--;
        while (tmp->m_next != nullptr && pos != 1)
        {
            tmp = tmp->m_next;
            prev = prev->m_next;
            pos--;
        }
        prev->m_next = tmp->m_next;
        delete tmp;
    }
}

template <typename T>
void F_list::forward_list<T>::insert(size_t pos, const T &data)
{
    if (empty())
    {
        throw std::logic_error("List is empty ");
    }
    else if (pos == 0)
    {
        this->push_front(data);
    }
    else
    {
        Node *prev = m_head;
        Node *next = m_head->m_next;
        pos--;
        while (next->m_next != nullptr && pos != 1)
        {
            next = next->m_next;
            prev = prev->m_next;
            pos--;
        }
        Node *newNode = new Node(data, next);
        prev->m_next = newNode;
    }
}

template <typename T>
T &F_list::forward_list<T>::front()
{
    return m_head->m_data;
}

template <typename T>
void F_list::forward_list<T>::reverse()
{
    Node *cur = m_head;
    Node *prev = nullptr;
    if (empty())
    {
        throw std::logic_error("List is empty ");
    }
    while (cur->m_next != nullptr)
    {
        Node *tmp = cur->m_next;
        cur->m_next = prev;
        prev = cur;
        cur = tmp;
    }
    cur->m_next = prev;
    m_head = cur;
}

template <typename T>
void F_list::forward_list<T>::sort()
{
    for (Node *cur = m_head; cur->m_next != nullptr; cur = cur->m_next)
    {
        bool flag = true;
        for (Node *cur1 = cur->m_next; cur1 != nullptr; cur1 = cur1->m_next)
        {
            if (cur->m_data > cur1->m_data)
            {
                std::swap(cur->m_data, cur1->m_data);
                flag = false;
            }
        }
        if (flag)
        {
            break;
        }
    }
}