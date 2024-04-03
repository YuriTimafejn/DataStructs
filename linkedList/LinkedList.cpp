#include <iostream>

class Node {
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList {
private:
    Node *header;
    Node *tail;
    int size;

public:
    LinkedList() 
    {
        header = NULL;
        tail = NULL;
        size = {0};
    }
    
    ~LinkedList()
    {
        Node *next;
        while(header != NULL)
        {
            next = header->next;
            delete header;
            header = next;
        }
    }

    int getSize() { return size; }

    void append(int data)
    {
        Node *node = new Node(data);

        if(getSize() == 0) // Check if the list is empty
        {
            header = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        size++;
    }

    void prepend(int data)
    {
        Node *node = new Node(data);

        if(header == NULL)
        {
            header = node;
            tail = node;
        } else {
            Node *tmp = header;
            header = node;
            node->next = tmp;
        }

        size++;
    }
    
    void toString()
    {
        Node *point = header;

        while(point != NULL)
        {
            std::cout << point->data << std::endl;
            point = point->next;
        }
    }

    void rmFront()
    {
        if(header != NULL)
        {
            Node *rmHeader = header;
            header = header->next;

            delete rmHeader;
            size--;
        }
    }

    void rmBack()
    {
        if(header == NULL) { return; }
        if(header->next == NULL)
        {
            rmFront();
        } else {
            Node *cur = header;
            Node *prev;

            while(cur->next != NULL)
            {
                prev = cur;
                cur = cur->next;
            }

            prev->next = NULL;
            tail = prev;
            delete cur;
            size--;
        }
    }

    void rmAt(int position)
    {
        if(position < 1 || position > getSize()) { return; }
        if(position == 1) 
        { 
            rmFront(); 
            return; 
        }
        if(position == getSize()) 
        { 
            rmBack(); 
            return;
        }

        Node *cur = header;
        Node *prev;

        for(int i=1; i < position; i++) {
            prev = cur;
            cur = cur->next;
        }

        prev->next = cur->next;
        delete cur;
        size--;
    }

    int addAt(int position, int data)
    {
        if(position < 1 || position > getSize() + 1) { return -1; }
        if(position == 1)
        {
            prepend(data);
            size++;
            return getSize();
        }
        if(position == getSize() + 1)
        {
            append(data);
            size++;
            return getSize();
        }

        Node *node = new Node(data);
        Node *cur = header;
        Node *prev;

        for(int i=1;i<position;i++) {
            prev = cur;
            cur = cur->next;
        }

        prev->next = node;
        node->next = cur;
        size++;

        return getSize();
    }
};

int main(int argc, char **argv) {
    LinkedList ll;
    ll.append(1);
    ll.append(7);
    ll.append(25);
    ll.append(42);
    ll.append(57);

    std::cout << "\n\tList size: " << ll.getSize() << std::endl;
    std::cout << "----------------------" << std::endl;
    ll.toString();

    // ll.rmFront();
    // ll.rmBack();
    // ll.rmAt(3);
    ll.addAt(3, 17);

    std::cout << "\n\tList size: " << ll.getSize() << std::endl;
    std::cout << "----------------------" << std::endl;
    ll.toString();

    return 0;
}
