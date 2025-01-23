#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int key;
    Node* next;
    Node* prev;
    
    Node(int val);
    static int generateKey();
};

int Node::generateKey() {
    static int keyCounter = 0;
    return ++keyCounter;
}

Node::Node(int val) {
    data = val;
    key = generateKey();
    next = NULL;
    prev = NULL;
}

// * Utility Functions in Doubly Linked-list *
bool isEmpty(Node* head) {
    return (head == NULL);
}

Node* createNode(int val) {
    return new Node(val);
}

// * Insertions in Doubly Linked-list *
void insertAtHead(Node*& head, int val) {
    Node* newNode = createNode(val);
    if (isEmpty(head)) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    cout << "Inserted " << val << " at the beginning" << endl;
}

void insertAtEnd(Node*& head, int val) {
    Node* newNode = createNode(val);
    if (isEmpty(head)) {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    cout << "Inserted " << val << " at end" << endl;
}

void insertAtAnyPosition(Node*& head, int pos, int val) {
    if (pos == 0) {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    int currentPos = 0;
    while (temp != NULL && currentPos < pos - 1) {
        temp = temp->next;
        currentPos++;
    }

    if (temp == NULL || temp->next == NULL) {
        insertAtEnd(head, val);
        return;
    }

    Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    cout << "Inserted " << val << " at position " << pos << endl;
}

// * Deletions in Doubly Linked-list *
void deleteHead(Node*& head) {
    if (isEmpty(head)) {
        cout << "List is empty! Nothing to delete.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }

    cout << "Deleted head node with value " << temp->data << endl;
    delete temp;
}

void deleteTail(Node*& head) {
    if (isEmpty(head)) {
        cout << "List is empty! Nothing to delete.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev == NULL) {
        head = NULL;
    } else {
        temp->prev->next = NULL;
    }

    cout << "Deleted tail node with value " << temp->data << endl;
    delete temp;
}

void deleteAtPosition(Node*& head, int pos) {
    if (isEmpty(head)) {
        cout << "List is empty! Nothing to delete.\n";
        return;
    }

    if (pos == 0) {
        deleteHead(head);
        return;
    }

    Node* temp = head;
    int currentPos = 0;
    while (temp != NULL && currentPos < pos - 1) {
        temp = temp->next;
        currentPos++;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position! No node exists at position " << pos << ".\n";
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = temp;
    }

    cout << "Deleted node at position " << pos << " with value " << nodeToDelete->data << endl;
    delete nodeToDelete;
}

// * Search & Display in Doubly Linked-list *
void search(Node* head, int val) {
    if (isEmpty(head)) {
        cout << "List is empty! Nothing to search.\n";
        return;
    }

    Node* temp = head;
    int pos = 0;

    while (temp != NULL) {
        if (temp->data == val) {
            cout << "Value " << val << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Value " << val << " not found in the list.\n";
}

void display(Node* head) {
    if (isEmpty(head)) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    cout << "List: ";

    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " -> ";
        }
        temp = temp->next;
    }

    cout << " -> NULL" << endl;
}

int main() {
    Node* head = NULL;
    int choice, val, pos;

    do {
        cout << "\n===== Doubly Linked List Menu =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete Head\n";
        cout << "5. Delete Tail\n";
        cout << "6. Delete at Position\n";
        cout << "7. Search Value\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Enter value: "; 
                cin >> val; 
                insertAtHead(head, val); 
                break;
            case 2: 
                cout << "Enter value: "; 
                cin >> val; 
                insertAtEnd(head, val); 
                break;
            case 3: 
                cout << "Enter position & value: "; 
                cin >> pos >> val; 
                insertAtAnyPosition(head, pos, val); 
                break;
            case 4: 
                deleteHead(head); 
                break;
            case 5: 
                deleteTail(head); 
                break;
            case 6: 
                cout << "Enter position: "; 
                cin >> pos; 
                deleteAtPosition(head, pos); 
                break;
            case 7: 
                cout << "Enter value: "; 
                cin >> val; 
                search(head, val); 
                break;
            case 8: 
                display(head); 
                break;
            case 9: 
                cout << "Exiting program...\n"; 
                break;
            default: 
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
