// C++ program for implementation of quicksort

#include <bits/stdc++.h>

int partition(std::vector<int>& vec, int low, int high)
{
  int pivot = vec[high];
  int i = low - 1;

  // Loop through low through high
  for (int j = low; j < high; j++)
  {
    // If current element is smaller than pivot
    if (vec[j] < pivot)
    {
      i++; // Increment i
      std::swap(vec[i], vec[j]); // Move the current element to the left side
    }
  }

  // Move the pivot to be after the biggest value but smaller than pivot
  std::swap(vec[i + 1], vec[high]);

  // Return the pivot index
  return i + 1;
}

// Quicksort recursive function
void quicksort(std::vector<int>& vec, int low, int high)
{
  // If low is lesser than high, perform recursive quicksort
  if (low < high)
  {
    int p = partition(vec, low, high);
    quicksort(vec, low, p - 1);
    quicksort(vec, p + 1, high);
  }
}

// Function to print an array
void printArray(std::vector<int> vec, int size)
{
  std::cout << "Sorted array: ";
  
  for (int i = 0; i < size; i++)
  {
    std::cout << vec[i] << " ";
  }
  
  std::cout << "\n" << "\n";
}

// Driver code
int main()
{
  std::vector<int> vec1 = {5, 1, 4, 8, 7, 2};
  size_t vec1Size = vec1.size();

  quicksort(vec1, 0, 5);

  printArray(vec1, vec1Size);

  return 0;
}