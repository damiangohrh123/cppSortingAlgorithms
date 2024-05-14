// C++ program for implementation of merge sort

#include <bits/stdc++.h>

// Merge function
std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
  std::vector<int> mergedVec;

  // Initialize left vector index and right vector index
  int l = 0;
  int r = 0;

  // Loop though both vectors and compare
  while (l < left.size() && r < right.size())
  {
    // Compare current index of left and right vector
    if (left[l] <= right[r])
    {
      mergedVec.push_back(left[l]);
      l++;
    }
    else if (right[r] <= left[l])
    {
      mergedVec.push_back(right[r]);
      r++;
    }
  }

  // If right vector is fully exhasuted and left vector still has leftover
  while (l < left.size())
  {
    // Insert remaining values of right into mergedVec
    mergedVec.push_back(left[l]);
    l++;
  }

  // If left vector is fully exhasuted and right vector still has leftover
  if (r < right.size())
  {
    // Insert remaining values of right into mergedVec
    mergedVec.push_back(right[r]);
    r++;
  }

  return mergedVec;
}

// Mergesort recursive function
std::vector<int> mergesort(std::vector<int>& vec, int low, int high)
{
  // Base case: single element vector
  if (low >= high)
  {
    return {vec[low]};
  }

  // Get the middle index of the vector
  int mid = low + (high - low) / 2;

  // Recursively split the vector into halves
  std::vector<int> left = mergesort(vec, low, mid);
  std::vector<int> right = mergesort(vec, mid + 1, high);

  return merge(left, right);
}

// Function to print a vector
void printVector(std::vector<int> vec, int size, std::string text)
{
  std::cout << text;
  for (int i = 0; i < size; i++)
  {
    std::cout << vec[i] << " ";
  }
  std::cout << "\n" << "\n";
}

// Driver code
int main()
{
  std::vector<int> original = {5, 1, 4, 8, 7, 2, 9};
  std::vector<int> sorted = mergesort(original, 0, original.size() - 1);
  
  // Print vectors
  printVector(original, original.size(), "Original vector: ");
  printVector(sorted, sorted.size(), "Sorted vector: ");

  return 0;
}