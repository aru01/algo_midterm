//
//  main.cpp
//  3zadacha
//
//  Created by Аружан Туткенова on 3/5/20.
//  Copyright © 2020 Аружан Туткенова. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
    
    Node(int _data) {
        data = _data;
        next = nullptr;
        prev = nullptr;
    }
};

struct LinkedList {
public:
    Node *head, *tail;
    int cont = 0;
    
    LinkedList() {
        head = tail = nullptr;
    }
    
    int cnt(int x) {
            return cont;
        
    }
    
    int getNth(int n, Node *node) {

        if (head == nullptr) {
            return -1;
        }
        else {
            return node;
        }

        
    void insertLast(int x) {
        auto node = new Node(x);
        while(tail->next != nullptr)
            tail = tail -> next;
        tail -> next = node;
        node -> prev = tail;
        return;
        
    }
    
    void insertFirst(int x) {
        auto node = new Node(x);
        if (head == nullptr) {
            head = node;
            tail = node;
            return;
        } else {
            head -> prev = node;
            node -> next = head;
            head = node;
        }
        cont++;
    }
    
    void deleteFirst() {
        head = head -> next;
        if (head != nullptr) {
            head->prev = nullptr;
            cont--;
        } else {
            tail = nullptr;
        }
    }
    
    void deleteLast() {
        tail = tail -> prev;
        if (tail != nullptr) {
            tail->next = nullptr;
            cont--;
        } else {
            head = nullptr;
        }
    }
    
    void del(int x) {
        auto cur = head;
        while (cur && cur -> data != x) {
            cur = cur -> next;
        }
        if (!cur) return;
        if (cur == head) deleteFirst();
        else
            if (cur == tail) deleteLast();
            else {
                cur -> next -> prev = cur -> prev;
                cur -> prev -> next = cur -> next;
            }
    }
    
    void print() {
        auto cur = head;
        while (cur) {
            if (cur != head) cout << " ";
            cout << (cur -> data);
            cur = cur -> next;
        }
        cout << "\n";
    }
};

int main() {
    int n, x;
    string s;
    auto linkedList = new LinkedList();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (s == "insertFirst") {
            cin >> x;
            linkedList -> insertFirst(x);
        }
        if (s == "delete") {
            cin >> x;
            linkedList -> del(x);
        }
        if (s == "deleteFirst") {
            linkedList -> deleteFirst();
        }
        if (s == "deleteLast") {
            linkedList -> deleteLast();
        }
        
        if (s == "insertLast") {
            cin >> x;
            linkedList -> insertLast(x);
        }
        
        if (s == "cnt") {
            cin >> x;
            cout << linkedList -> cnt(x) << "\n";
        }
        
        if (s == "getNth") {
            cin >> x;
            cout << linkedList -> getNth(x) << "\n";
        }
    }
    linkedList -> print();
}
