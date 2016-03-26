#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
    struct Node {
        T value;
        Node *next;
        Node *prev;
    };
    Node *head;
public:
    struct iterator {
        Node *p;
        iterator(Node *ptr) : p(ptr) {}
        void operator++() { p = p->next; }
        T& operator*() { return p->value; }
        bool operator!=(const iterator &rhs) { return p != rhs.p; }
    };
    iterator begin() const { return head; }
    iterator end() const { return NULL; }

    List() : head(NULL) {}
    void push_front(const T &x)
    {
        Node *p = new Node;
        p->value = x;
        p->next = head;
        p->prev = NULL;
        if (head != NULL)
            head->prev = p;

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
    ~List()
    {
        while (head != NULL)
        {
            Node *p = head->next;
            delete head;
            head = p;
        }
    }
    void insert(int n, const T &x)
    {
        if (n == 0)
            push_front(x);
        else
        {
            Node *p = head;
            while (n != 0)
            {
                p = p->next;
                n--;
            }

            Node *node = new Node;
            node->value = x;
            node->next = p;
            node->prev = p->prev;
            if (p->prev != NULL)
                p->prev->next = node;

            p->prev = node;

        }
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
