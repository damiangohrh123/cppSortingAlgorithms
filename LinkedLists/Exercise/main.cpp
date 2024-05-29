#include <iostream>
#include "LinkedList.hpp"

int main()
{
  LinkedList ll;

  // Insert some nodes into the linked list
  ll.insertSorted(ll.getHead(), 4);

  // Display linked list
  ll.display(ll.getHead());

  std::cout << ll.search(ll.getHead(), 5) << "\n";

  ll.remove(ll.getHead(), 4);

  ll.display(ll.getHead());

  return 0;
}