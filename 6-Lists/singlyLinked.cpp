/**
 * @file singlyLinked.cpp
 * @author your name (you@domain.com)
 * @brief A demonstration of a singly linked list implementation.
 * @version 0.1
 * @date 2025-10-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>

template<typename T>
class List {
public:
    struct Node {
        Node(T data) : data(data), next(nullptr) { }
        T data;
        Node *next;
    };

    /**
     * @brief Create an empty list.
     * 
     */
    List() : head(nullptr), tail(nullptr) {} 

    /** 
     * Destroy the list
     */
    virtual ~List()
    {
        Node *cur, *next;

        // start at the head
        cur = head;

        // destroy each node
        while(cur) {
            next = cur->next; // remember the next node
            delete cur;
            cur = next;       // advance the current pointer
        }
    }

    /**
     * @brief Put data at the head of the list.
     * 
     * @param data 
     */
    void push_front(T data)
    {
        // create the node
        Node *node = new Node(data);

        // link the node
        node->next = head;
        head = node;

        // move the tail pointer if necessary
        if(tail == nullptr) {
            tail = node;
        }
    }

    /**
     * @brief Append data to the end of the list.
     * 
     * @param data 
     */
    void push_back(T data)
    {
        // Create the node
        Node *node = new Node(data);

        // Link the node
        if(tail == nullptr) {
            // empty list
            head = node;
        } else {
            // non-empty list
            tail->next = node;
        }
        tail = node;
    }
    
    /**
     * @brief Delete the first item in the list.
     * 
     * @return T 
     */
    T pop_front() 
    {
        // Get the data to return
        T data = head->data;

        // Unlink the node
        Node *doomed = head;
        head = head->next;

        // handle the tail
        if(head == nullptr) {
            tail = nullptr;
        }

        // delete
        delete doomed;

        return data;
    }

    /**
     * @brief Remove the last item from the list.
     * 
     */
    T pop_back() 
    {
        // get the data
        T data = tail->data;

        // handle 1-item case
        if(head == tail) {
            delete tail;
            head = nullptr;
            tail = nullptr;
            return data;
        }

        // find the prev node
        Node *prev;
        for(prev=head; prev->next != tail; prev = prev->next);

        // delete the tail
        delete_after(prev);

        return data;
    }


    /**
     * @brief Insert data after a given node.
     * 
     * @param node 
     * @param data 
     */
    void insert_after(Node *node, T data)
    {
        // insert after a given node. If node is nullptr, insert at head
        if(node == nullptr) {
            push_front(data);
            return;
        }

        Node *n = new Node(data);
        n->next = node->next;
        node->next = n;

        // if we inserted at the end, update tail
        if(tail == node) {
            tail = n;
        }
    }

    /**
     * @brief Delete the node after a given node.
     * 
     * @param node 
     */
    void delete_after(Node *node)
    {
        // The signature previously had a data parameter but delete_after should
        // remove the node after 'node'. If node is nullptr, delete head.

        if(node == nullptr) {
            // delete the head
            if(head == nullptr) return; // nothing to delete
            Node *doomed = head;
            head = head->next;
            if(head == nullptr) {
                tail = nullptr;
            }
            delete doomed;
            return;
        }

        Node *target = node->next;
        if(target == nullptr) return; // nothing after node

        node->next = target->next;
        if(target == tail) {
            tail = node;
        }
        delete target;
    }

    /**
     * @brief Get the first node in the list.
     * 
     * @return Node* 
     */
    Node* begin()
    {
        return head;
    }

    /**
     * @brief Get the end marker (nullptr) for the list.
     * 
     * @return Node* 
     */
    Node* end()
    {
        return nullptr;
    }
private:
    Node* head;
    Node* tail;
};


// Helper: stream insertion for List<T>
template<typename T>
std::ostream& operator<<(std::ostream& os, List<T>& lst)
{
    os << "{";
    for(auto node = lst.begin(); node != lst.end(); node = node->next) {
        os << node->data;
        if(node->next != nullptr) os << ", ";
    }
    os << "}";
    return os;
}

int main()
{
    List<int> lst;

    std::cout << "Initial empty list: " << lst << std::endl;

    // push_front on empty
    lst.push_front(10);
    std::cout << "After push_front(10): " << lst << std::endl;

    // push_back
    lst.push_back(20);
    lst.push_back(30);
    std::cout << "After push_back(20,30): " << lst << std::endl;

    // insert_after head
    auto h = lst.begin();
    lst.insert_after(h, 15); // between 10 and 20
    std::cout << "After insert_after(head,15): " << lst << std::endl;

    // insert after tail
    // find tail node
    auto node = lst.begin();
    while(node->next) node = node->next;
    lst.insert_after(node, 40);
    std::cout << "After insert_after(tail,40): " << lst << std::endl;

    // delete after head (remove 15)
    lst.delete_after(lst.begin());
    std::cout << "After delete_after(head): " << lst << std::endl;

    // delete head via delete_after(nullptr)
    lst.delete_after(nullptr);
    std::cout << "After delete_after(nullptr) [pop_front]: " << lst << std::endl;

    // pop_front
    int v = lst.pop_front();
    std::cout << "pop_front returned " << v << ", list: " << lst << std::endl;

    // pop_back
    v = lst.pop_back();
    std::cout << "pop_back returned " << v << ", list: " << lst << std::endl;

    // clear remaining
    while(lst.begin() != lst.end()) {
        lst.pop_front();
    }
    std::cout << "After clearing: " << lst << std::endl;

    // edge cases: pop from empty should be avoided; we won't call pop on empty to avoid UB

    std::cout << "All tests completed." << std::endl;
    return 0;
}