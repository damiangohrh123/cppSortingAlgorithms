#include <iostream>
#include "HashTable.hpp"

int main()
{
  long a = 2;
  long c = 0;
  long m = 5;

  HashTable ht(a, c, m);
  ht.insert(7);
  ht.insert(6);
  ht.insert(3);
  ht.insert(2);
  ht.insert(4);
  ht.insert(11);

  ht.printTable();

  std::cout << "Removing 3" << "\n";
  ht.remove(3);

  ht.printTable();

  std::cout << ht.find(8) << "\n";
  std::cout << ht.find(11) << "\n";

  return 0;
}