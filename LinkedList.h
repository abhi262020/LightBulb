#ifndef LINKEDLIST_H
#define LINKEDLIST_H
// LinkedList.h
#pragma once
#include<iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void Add(T data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    template <typename Func>
    void ForEach(Func func) {
        Node* current = head;
        while (current) {
            func(current->data);
            current = current->next;
        }
    }
};


#endif // LINKEDLIST_H
