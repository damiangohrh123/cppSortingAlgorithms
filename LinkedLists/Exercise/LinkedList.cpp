#include "LinkedList.hpp"

LinkedList::LinkedList()
{
    head = 0;
}

LinkedList::~LinkedList(){}

void LinkedList::insertSorted(LinkedList::Node*& _head,int _value)
{
    // Create a new node
    Node* newNode = new Node;
    newNode->data = _value;
    newNode->next = nullptr;

    // CASE 1: If list is empty, insert the node at the beginning
    if (_head == nullptr)
    {
        newNode->next = _head;
        _head = newNode;
        return;
    }

    // CASE 2: Traverse the list to find appropriate position for insertion
    Node* currentNode = _head;
    while (currentNode->next != nullptr && _value > currentNode->next->data)
    {
        currentNode = currentNode->next;
    }
    // Insert the node after traversing to correct node
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

int LinkedList::length(LinkedList::Node*& _head)
{
    int count = 0;
    Node* currentNode = _head;
    while (currentNode != nullptr)
    {
        currentNode = currentNode->next;
        count++;
    }    
    return count;
}

int LinkedList::search(LinkedList::Node*& _head,int _value)
{   
    int count = 0;
    Node* currentNode = _head;

    // Traverse the list
    while (currentNode != nullptr)
    {
        if (currentNode->data == _value)
        {
            return count;
        }
        currentNode = currentNode->next;
        count++;
    }
    return -1;
}

void LinkedList::remove(LinkedList::Node*& _head,int _value)
{
    Node* currentNode = _head;
    Node* previousNode = 0;

    // If the list is empty
    if (currentNode == nullptr)
    {
        return;
    }

    // If node to be deleted is the first node
    if (currentNode->data == _value)
    {
        _head = currentNode->next;
        return;
    }

    // Traverse list to find node to delete
    while (currentNode != nullptr)
    {
        if (currentNode->data == _value)
        {
            // Make previous node's next point to current node's next
            // effectively deleting the current node
            previousNode->next = currentNode->next;
            return;
        }

        // Update previous node and current node
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
}


void LinkedList::display(LinkedList::Node*& _head)
{
    Node* iterator = _head; // Do not want to move the actual head, make a copy
    
    if (iterator == NULL){
        cout << "The list is empty";
    }
    
    while(iterator != NULL)
    {
        cout << "[" + std::to_string(iterator->data) + "] ";
        iterator=iterator->next;
    }
    cout << "\n";

    // Print length
    std::cout << "length: " << LinkedList::length(LinkedList::getHead()) << "\n";
}

LinkedList::Node*& LinkedList::getHead()
{
    return*& this->head;
}

