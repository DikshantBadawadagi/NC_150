#include <bits/stdc++.h>
using namespace std;

class Node {
public: 
    int key, value;
    Node* next;
    Node* prev;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mpp;
    int capacity;
    Node* dummy; 
    Node* tail;  

    LRUCache(int capacity) {
        this->capacity = capacity;
        dummy = new Node(-1, -1);
        tail = new Node(-1, -1);
        dummy->next = tail;
        tail->prev = dummy;
    }
    
    void moveToFront(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = dummy->next;
        node->prev = dummy;
        dummy->next->prev = node;
        dummy->next = node;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }
        Node* node = mpp[key];
        moveToFront(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->value = value;
            moveToFront(node);
            return;
        }

        if (mpp.size() >= capacity) {
            Node* lru = tail->prev;
            mpp.erase(lru->key);
            lru->prev->next = tail;
            tail->prev = lru->prev;
            delete lru;
        }

        Node* newNode = new Node(key, value);
        mpp[key] = newNode;
        newNode->next = dummy->next;
        newNode->prev = dummy;
        dummy->next->prev = newNode;
        dummy->next = newNode;
    }
};
