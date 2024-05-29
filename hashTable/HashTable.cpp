#include "HashTable.hpp"
#include <iostream>

HashTable::HashTable(long _a, long _c, long _m)
{
  a = _a;
  c = _c;
  m = _m;
  bucketVector.resize(m, -1);
}

HashTable::~HashTable() {}

void HashTable::insert(int key)
{
  // Make sure key is positive
  if (key < 0) return;

  // Check load factor and extend if necessary
  if (loadFactor() == 1) extend();

  // Calculate hash function
  int hashNumber = (a * key + c) % m;

  // Linear probing (Move to the right)
  int linearNumber = hashNumber;
  while (bucketVector[linearNumber] != -1)
  {
    // Move to next number (Use mod to wrap it around)
    linearNumber = (linearNumber + 1) % m;
  }

  bucketVector[linearNumber] = key;
  numOfElements++;
}

void HashTable::extend()
{
  // Create a temporary vector to store current values
  std::vector<int> temporaryVector;

  // Add all current keys in the current bucket into the temporary vector
  for (int i = 0; i < bucketVector.size(); i++)
  {
    if (bucketVector[i] > -1)
    {
      temporaryVector.push_back(bucketVector[i]);
    }
  }

  // Clear the current bucket
  bucketVector.clear();

  // Reset the number of elements
  numOfElements = 0;

  // Increase the size of the current bucket
  m *= 2;
  bucketVector.resize(m, -1);

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
  int hashNumber = (a * key + c) % m;

  // Linear probing (Move to the right)
  int linearNumber = hashNumber;
  do
  {
    if (bucketVector[linearNumber] == key)
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
  int hashNumber = (a * key + c) % m;

  // Linear probing (Move to the right)
  int linearNumber = hashNumber;
  do
  {
    if (bucketVector[linearNumber] == key)
    {
      bucketVector[linearNumber] = -1;
    }

    // Move to next number (Use mod to wrap it around)
    linearNumber = (linearNumber + 1) % m;

  } while (linearNumber != hashNumber);
}

double HashTable::loadFactor()
{
  // Static cast to make it return a double instead of an int
  return static_cast<double>(numOfElements) / bucketVector.size();
}

void HashTable::printTable()
{
  std::cout << "Hashtable: " << "\n";
  std::cout << "[";
  for (int i = 0; i < bucketVector.size(); i++)
  {
    std::cout << bucketVector[i];
    if (i < bucketVector.size() -1)
    {
      std::cout << ", ";
    }
  }
  std::cout << "]" << "\n";

  std::cout << "Load Factor: " << loadFactor() << "\n" << "\n";
}