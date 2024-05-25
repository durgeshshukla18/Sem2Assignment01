#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert_start(int index, int data) {
        if (index < 0) {
            cout << "Index out of range" << endl;
            return;
        }
        Node* new_node = new Node(data);
        if (index == 0) {
            new_node->next = head;
            head = new_node;
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            if (current == nullptr) {
                cout << "Index out of range" << endl;
                return;
            }
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Index out of range" << endl;
            return;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    void remove_index(int index) {
        if (index < 0 || head == nullptr) {
            cout << "Index out of range" << endl;
            return;
        }
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            if (current->next == nullptr) {
                cout << "Index out of range" << endl;
                return;
            }
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << "Index out of range" << endl;
            return;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    int size() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    bool is_empty() {
        return head == nullptr;
    }

    void rotate(int k) {
        if (k <= 0 || head == nullptr) {
            return;
        }
        int length = size();
        k = k % length;
        if (k == 0) {
            return;
        }
        Node* current = head;
        for (int i = 0; i < length - k - 1; ++i) {
            current = current->next;
        }
        Node* new_head = current->next;
        current->next = nullptr;
        current = new_head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = head;
        head = new_head;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr) {
            Node* next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        head = prev;
    }

    void append(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }

    void prepend(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void merge(LinkedList& other_list) {
        if (other_list.head == nullptr) {
            return;
        }
        if (head == nullptr) {
            head = other_list.head;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = other_list.head;
    }

    int middle_element() {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow ? slow->data : -1;
    }

    pair<Node*, Node*> split_index(int index) {
        if (index < 0 || index >= size()) {
            cout << "Index out of range" << endl;
            return {nullptr, nullptr};
        }
        if (index == 0) {
            Node* second_half = head;
            head = nullptr;
            return {nullptr, second_half};
        }
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* second_half = current->next;
        current->next = nullptr;
        return {head, second_half};
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "None" << endl;
    }
};

int main() {
    LinkedList list;
    list.append(18);
    list.append(21);
    list.append(3);
    list.display();
    
    list.insert_start(0, 9);
    list.display();
    
    list.remove_index(3);
    list.display();
    
    list.reverse();
    list.display();
    
    list.rotate(2);
    list.display();
    
    cout << "Middle element: " << list.middle_element() << endl;
    
    
    
    return 0;
}
