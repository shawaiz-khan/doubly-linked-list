#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;
        Node() {
            data = 0;
            next = NULL;
            prev = NULL;
        }
        Node(int val) {
            data = val;
            next = NULL;
            prev = NULL;
        }
};

bool isEmpty(Node* head) {
    if (head == NULL) {
        return true;
    } else {
        return false;
    }
}

Node* createNode(int val) {
    Node* newNode = new Node(val);
    return newNode;
}

void insertAtStart(Node* head, int val) {
    Node* newNode = createNode(val);
    if(isEmpty()) {
        head = newNode;
        cout << "Inserted " << val << " at Head Node" << endl;
    } else {
        Node* temp = head;
    }
}

void insertAtEnd(Node* &head, int val) {
    Node* newNode = createNode(val);
    if (isEmpty(head)) {
        head = newNode;
        cout << "Inserted " << val << " at Head Node" << endl;
    } else {
        Node* temp = head;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> prev = temp;
        cout << "Inserted " << val << " at end" << endl;
    }
}

int main() {
    Node* head;
    head = NULL;

    insertAtEnd(head, 10);

    return 0;
}