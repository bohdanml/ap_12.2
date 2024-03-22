#include <iostream>
#include <unordered_set>



struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

bool areAllElementsInList(Node* L1, Node* L2) {
    std::unordered_set<int> elements_set;
    // Заповнюємо множину елементів списку L2
    while (L2) {
        elements_set.insert(L2->data);
        L2 = L2->next;
    }
    // Перевіряємо, чи всі елементи списку L1 є в множині елементів L2
    while (L1) {
        if (elements_set.find(L1->data) == elements_set.end()) {
            return false;
        }
        L1 = L1->next;
    }
    return true;
}

int main() {
    // Формуємо список L1
    Node* L1 = nullptr;
    insert(L1, 5);
    insert(L1, 7);
    insert(L1, 8);

    // Формуємо список L2
    Node* L2 = nullptr;
    insert(L2, 9);
    insert(L2, 7);
    insert(L2, 8);
    insert(L2, 5);

    std::cout << "List L1: ";
    printList(L1);
    std::cout << "List L2: ";
    printList(L2);

    if (areAllElementsInList(L1, L2)) {
        std::cout << "All elements of L1 are in L2." << std::endl;
    }
    else {
        std::cout << "Not all elements of L1 are in L2." << std::endl;
    }

    return 0;
}
