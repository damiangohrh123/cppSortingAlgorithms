#include <iostream>
#include "LinkedList.hpp"

int main()
{
  LinkedList ll;

  // Insert some nodes into the linked list
  ll.insertSorted(ll.getHead(), 2);
  ll.insertSorted(ll.getHead(), 5);
  ll.insertSorted(ll.getHead(), 3);
  ll.insertSorted(ll.getHead(), 4);
  ll.insertSorted(ll.getHead(), 9);
  ll.insertSorted(ll.getHead(), 6);

  // Display linked list
  ll.display(ll.getHead());

  std::cout << ll.search(ll.getHead(), 5) << "\n";

  ll.remove(ll.getHead(), 4);

  ll.display(ll.getHead());

  return 0;
}