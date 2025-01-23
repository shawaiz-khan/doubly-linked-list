# Doubly Linked List in C++

This repository contains the implementation of a **Doubly Linked List** in C++, including basic operations such as insertion, deletion, search, and display. The program supports inserting nodes at the beginning, at the end, and at a specific position. It also supports deleting nodes from the head, tail, and a specified position in the list.

## Features
- Insert at the **beginning**
- Insert at the **end**
- Insert at a **specific position**
- Delete from the **head**
- Delete from the **tail**
- Delete at a **specific position**
- **Search** for a node by its value
- **Display** the entire list

## Program Overview

### Class `Node`
- Contains the following attributes:
  - `data`: Stores the node value.
  - `key`: A unique identifier for each node (auto-generated).
  - `next`: Points to the next node in the list.
  - `prev`: Points to the previous node in the list.
  
### Functions Implemented:
- `createNode(int val)`: Creates a new node with the specified value.
- `insertAtHead(Node* &head, int val)`: Inserts a node at the head of the list.
- `insertAtEnd(Node* &head, int val)`: Inserts a node at the end of the list.
- `insertAtAnyPosition(Node* &head, int pos, int val)`: Inserts a node at a specified position.
- `deleteHead(Node* &head)`: Deletes the node at the head of the list.
- `deleteTail(Node* &head)`: Deletes the node at the tail of the list.
- `deleteAtPosition(Node* &head, int pos)`: Deletes the node at a specified position.
- `search(Node* head, int val)`: Searches for a node by its value.
- `display(Node* head)`: Displays the entire list.

### Menu System:
The program runs in a loop allowing the user to choose from various options:
- Insert at Beginning
- Insert at End
- Insert at Position
- Delete Head
- Delete Tail
- Delete at Position
- Search Value
- Display List
- Exit

## How to Run

### Prerequisites:
- C++ compiler (e.g., GCC, Clang)
- A code editor or IDE (e.g., Visual Studio Code, Code::Blocks, or Eclipse)

### Steps:
1. Clone this repository:
   ```bash
   git clone https://github.com/shawaiz-khan/doubly-linked-list.git
   ```
2. Navigate to the project directory:
   ```bash
   cd doubly-linked-list
   ```
3. Compile the code:
   ```bash
   g++ -o doubly_linked_list main.cpp
   ```
4. Run the program:
   ```bash
   ./doubly_linked_list
   ```

### Example Output:
```text
===== Doubly Linked List Menu =====
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete Head
5. Delete Tail
6. Delete at Position
7. Search Value
8. Display List
9. Exit
Enter your choice: 1
Enter value: 10
Inserted 10 at the beginning

List: 10 -> NULL
```

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributions
Feel free to fork and contribute to the project. For any issues, please open an issue in the Issues section.

## Acknowledgements
- Thanks to the open-source community for making C++ programming resources available.