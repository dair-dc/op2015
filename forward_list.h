#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

template <typename T>
class ForwardList {
    struct Node {
        T value;
        Node *next;
    };
    Node *head;
public:
    ForwardList() : head(NULL) {}
    void push_front(const T &x)
    {
        Node *p = new Node;
        p->value = x;
        p->next = head;
        head = p;
    }
    void print()
    {
        Node *p = head;
        while (p != NULL)
        {
            std::cout << p->value << std::endl;
            p = p->next;
        }
    }
    ~ForwardList()
    {
        while (head != NULL)
        {
            Node *p = head->next;
            delete head;
            head = p;
        }
    }
    bool insert(int n, const T &x)
    {
        if (n == 0)
            push_front(x);
        else
        {
            Node *p = head;
            while (p != NULL && n != 1)
            {
                p = p->next;
                n--;
            }
            if (p == NULL)
                return false;

            Node *node = new Node;
            node->value = x;
            node->next = p->next;
            p->next = node;
        }
        return true;
    }
    size_t size() const
    {
        size_t n = 0;
        for (Node *p = head; p != NULL; p = p->next)
            n++;

        return n;
    }
    T& operator[](size_t n)
    {
        Node *p = head;

        for (size_t i = 0; i < n; i++)
            p = p->next;

        return p->value;
    }
};
#endif
