#include "HashTable.hpp"

#include <iostream>

HashTable::HashTable(long _a, long _c, long _m)
  : a(_a), c(_c), m(_m)
{
  buckets.resize(m, -1);
}

HashTable::~HashTable() {}

void HashTable::insert(int key)
{
  // Make sure key is positive
  if (key < 0) return;

  // Check load factor and extend if necessary
  if (loadFactor() == 1) extend();

  // Calculate hash function
  int hashNumber = hashNumberCalculator(key);

  // Linear probing (Move to the right)
  int linearNumber = hashNumber;
  while (buckets[linearNumber] != -1)
  {
    // Move to next number (Use mod to wrap it around)
    linearNumber = (linearNumber + 1) % m;
  }

  buckets[linearNumber] = key;
  numOfElements++;
}

void HashTable::extend()
{
  // Create a temporary vector to store current values
  std::vector<int> temporaryVector;

  // Add all current keys in the current bucket into the temporary vector
  for (int i = 0; i < buckets.size(); i++)
  {
    if (buckets[i] > -1)
    {
      temporaryVector.push_back(buckets[i]);
    }
  }

  // Clear the current bucket
  buckets.clear();

  // Reset the number of elements
  numOfElements = 0;

  // Increase the size of the current bucket
  m *= 2;
  buckets.resize(m, -1);

  // Re-hash and insert all the values back into the bucket
  for (int i = 0; i < temporaryVector.size(); i++)
  {
    int key = temporaryVector[i];
    insert(key);
  }
}

bool HashTable::find(int key)
{
  // Calculate hash function
  int hashNumber = hashNumberCalculator(key);

  // Linear probing (Move to the right)
  int linearNumber = hashNumber;
  do
  {
    if (buckets[linearNumber] == key)
    {
      return true;
    }

    // Move to next number (Use mod to wrap it around)
    linearNumber = (linearNumber + 1) % m;

  } while (linearNumber != hashNumber);

  return false;
}

void HashTable::remove(int key)
{
  // Calculate hash function
  int hashNumber = hashNumberCalculator(key);

  // Linear probing (Move to the right)
  int linearNumber = hashNumber;
  do
  {
    if (buckets[linearNumber] == key)
    {
      buckets[linearNumber] = -1;
    }

    // Move to next number (Use mod to wrap it around)
    linearNumber = (linearNumber + 1) % m;

  } while (linearNumber != hashNumber);
}

double HashTable::loadFactor()
{
  // Static cast to make it return a double instead of an int
  return static_cast<double>(numOfElements) / buckets.size();
}

void HashTable::printTable()
{
  std::cout << "Hashtable: " << "\n";
  std::cout << "[";
  for (int i = 0; i < buckets.size(); i++)
  {
    std::cout << buckets[i];
    if (i < buckets.size() -1)
    {
      std::cout << ", ";
    }
  }
  std::cout << "]" << "\n";

  std::cout << "Load Factor: " << loadFactor() << "\n" << "\n";
}

int HashTable::hashNumberCalculator(int key)
{
  return (a * key + c) % m;
}

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