// C++ program for implementation of insertion sort

#include <bits/stdc++.h>

// Insertion sort recursive function
std::vector<int> insertionsort(std::vector<int> vec)
{
  for (int i = 1; i < vec.size(); i++)
  {
    // Create a copy of the current element
    int placeholder = vec[i];

    // Initialize j
    int j = i - 1;

    // Shift elements to the right until placeholder is not smaller than current element
    while (j >= 0 && placeholder < vec[j])
    {
      vec[j + 1] = vec[j];
      j--;
    }

    // Place placeholder at correct position
    vec[j + 1] = placeholder;
  }

  return vec;
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
  std::vector<int> sorted = insertionsort(original);
  
  // Print vectors
  printVector(original, original.size(), "Original vector: ");
  printVector(sorted, sorted.size(), "Sorted vector: ");

  return 0;
}