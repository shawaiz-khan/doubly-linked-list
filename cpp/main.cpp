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

void insertAtHead(Node* &head, int val) {
    Node* newNode = createNode(val);
    if(isEmpty(head)) {
        head = newNode;
        cout << "Inserted " << val << " at Head Node" << endl;
    } else {
        Node* temp = head;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        cout << "Inserted " << val << " at the beginning" << endl;
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
    Node* head = NULL;
    int choice, val, pos;

    do {
        cout << endl << "===== Doubly Linked List Menu =====" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete Head" << endl;
        cout << "5. Delete Tail" << endl;
        cout << "6. Delete at Position" << endl;
        cout << "7. Traverse Forward" << endl;
        cout << "8. Traverse Backward" << endl;
        cout << "9. Display List" << endl;
        cout << "10. Search Value" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                insertAtHead(head, val);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                // insertAtTail(head, val);
                break;
            case 3:
                cout << "Enter position and value to insert: ";
                cin >> pos >> val;
                // insertAtPosition(pos, val);
                break;
            case 4:
                // deleteHead();
                break;
            case 5:
                // deleteTail();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                // deleteAtPosition(pos);
                break;
            case 7:
                // traverseForward();
                break;
            case 8:
                // traverseBackward();
                break;
            case 9:
                // display();
                break;
            case 10:
                cout << "Enter value to search: ";
                cin >> val;
                // search(val);
                break;
            case 0:
                cout << "Exiting program...";
                break;
            default:
                cout << "Invalid choice! Please try again.";
        }
    } while (choice != 0);

    return 0;
}