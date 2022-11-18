#include <iostream>

struct Elem
{
    int value_;
    Elem* next_;
    Elem(int i) : value_(i), next_(nullptr) {}
};

Elem* createList(int num)
{
    Elem* head = nullptr;
    Elem* prev = nullptr;
    for (int i = 0; i < num; ++i)
    {
        Elem* elem = new Elem(i);
        if (!head)
        {
            head = elem; // Save the first elem as head
        }
        if (prev)
        {
            prev->next_ = elem;
        }
        prev = elem;
    }
    return head;
}

void printList(Elem* head)
{
    for (Elem* p = head; p; p = p->next_)
    {
        std::cout << p->value_ << ", ";
    }
    std::cout << std::endl;
}

Elem* findElem(Elem* head, int val)
{
    for (Elem* p = head; p; p = p->next_)
    {
        if (p->value_ == val)
        {
            return p;
        }
    }
    return nullptr;
}

void printFound(Elem* head, int val)
{
    Elem* found = findElem(head, val);
    if (found)
    {
        std::cout << "Found value: " << val<< std::endl;
    }
    else
    {
        std::cout << "Value: " << val<< " not found" << std::endl;
    }
}

Elem* removeElem(Elem* head, int val)
{
    Elem* prev = nullptr;
    for (Elem* p = head; p; p = p->next_)
    {
        if (p->value_ == val)
        {
            if (!prev)
            {
                head = p->next_;
                return head;
            }
            else
            {
                prev->next_ = p->next_;
                return p;
            }
        }
        prev = p;
    }
    return nullptr;
}

int main(int argc, char* argv[])
{
    int num = 10;
    if (argc > 1)
    {
        num = atoi(argv[1]);
    }

    Elem* head = createList(num);
    printList(head);

    printFound(head, 5);
    printFound(head, 15);

    removeElem(head, 5);
    printList(head);

    head = removeElem(head, 0);
    printList(head);

    return 0;
}

