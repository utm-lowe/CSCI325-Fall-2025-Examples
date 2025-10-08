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
class list {
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
        deleteAfter(prev);

        return data;
    }


    void insert_after(Node *node, T data);
    void delete_after(Node *node, T data);

    Node* begin();
    Node* end();
private:
    Node* head;
    Node* tail;
};