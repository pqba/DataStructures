#include "../../include/Structures/LinkedList.h"

#include <stdexcept>
#include <string>

#include "../../include/Structures/Data.h"

/*
Singly Linked List Implementation.
References:
https://en.wikipedia.org/wiki/Linked_list
http://cslibrary.stanford.edu/103/LinkedListBasics.pdf
*/

LinkedList::LinkedList() {
    head = nullptr;
    ll_length = 0;
}

// Removes the entire list
LinkedList::~LinkedList() {
    clear();
}

// Size of linkedlist
int LinkedList::size() {
    return ll_length;
}
// Empties list, deletes all nodes.
void LinkedList::clear() {
    while (head != nullptr) {
        Node* current = head;
        head = head->link;
        delete current;
    }
    ll_length = 0;
}
// Returns if the linkedlist is empty
bool LinkedList::isEmpty() {
    return head == nullptr;
}

// Removes the first Node pointer which matches one in list. If nonexistent, does nothing.
void LinkedList::remove(Node* item) {
    if (head == nullptr || item == nullptr) {
        return;
    } else if (item->sameAs(head)) {
        if (head->link != nullptr) {
            setHead(head->link);
        } else {
            head = nullptr;
        }
    } else {
        Node* curr = head;
        Node* past = nullptr;
        while (curr->link != nullptr) {
            past = curr;
            curr = curr->link;
            if (curr->sameAs(item)) {
                Node* next = curr->link;
                past->link = next;
                delete curr;
                ll_length--;
                return;
            }
        }
    }
    ll_length--;
}
// Removes the Node at a specified index
void LinkedList::remove(int index) {
    checkIndex("Removal index out of bounds", index);

    int count = 0;
    Node* curr = head;
    Node* past = nullptr;

    while (count != index) {
        past = curr;
        curr = curr->link;
        count++;
    }

    if (index == 0) {
        head = curr->link;
        delete curr;
        ll_length--;
    } else {
        past->link = curr->link;
        delete curr;
        ll_length--;
    }
}
// Adds Node to the end of linked list
void LinkedList::add(Node* item) {
    if (head == nullptr) {
        head = item;
    } else {
        Node* curr = head;
        // Loop to end of list
        while (curr->link != nullptr) {
            curr = curr->link;
        }
        curr->link = item;
    }
    ll_length++;
}
// Adds Node to index in list, throws error if index out of bounds
void LinkedList::add(Node* item, int index) {
    if (index < 0 || index > size()) {
        throw std::invalid_argument("Insertion index out of bounds");
    }
    if (index == 0 && head == nullptr) {
        setHead(item);
        return;
    } else if (index == 0) {
        item->link = head;
        head = item;
        return;
    }

    int count = 0;
    Node* curr = head;

    // Move to right before insertion
    while (count != index - 1) {
        curr = curr->link;
        count++;
    }
    // curr -> item -> curr's link
    item->link = curr->link;
    curr->link = item;
    ll_length++;
}

// Gets Node at specified index.
Node* LinkedList::get(int index) {
    checkIndex("Access index out of bounds.", index);
    Node* curr = head;
    int count = 0;
    while (count != index) {
        curr = curr->link;
        count++;
    }
    return curr;
}
// Finds index for specified Node, returns -1 otherwise
int LinkedList::find(Node* nd) {
    if (head == nullptr) {
        return -1;
    }
    Node* curr = head;
    int ind = 0;
    do {
        if (curr->sameAs(nd)) {
            return ind;
        }
        curr = curr->link;
        ind++;
    } while (curr->link != nullptr);
    return -1;
}
// Sets Node at specified index.
void LinkedList::set(Node* item, int index) {
    checkIndex("Set index out of bounds.", index);
    if (index == 0) {
        setHead(item);
        return;
    }
    Node* curr = head;
    int count = 0;
    while (count < index - 1) {
        curr = curr->link;
        count++;
    }
    // Curr -> ITEM -> toSet->link;
    Node* toSet = curr->link;
    curr->link = item;
    item->link = toSet->link;
    delete toSet;  // must be removed.
}

void LinkedList::reverse() {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next;
    while (curr != nullptr) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
// Returns string representation of singly linked list.
std::string LinkedList::print() {
    Node* top = head;
    if (top == nullptr) {
        return "empty.";
    }
    std::string output;
    while (top != nullptr) {
        std::string line = top->info.print() + "=>";
        output += line;
        top = top->link;
    }
    output += "null";
    return output;
}

// Throws specified error message if inputted index is out of bounds for list.
void LinkedList::checkIndex(std::string msg, int possibleInd) {
    if (possibleInd < 0 || possibleInd >= size()) {
        throw std::invalid_argument(msg);
    }
}