// https://www.onlinegdb.com/online_c++_compiler
// https://www.youtube.com/watch?v=xli_FI7CuzA
// https://www.geeksforgeeks.org/bubble-sort/
// C++ program for implementation of Bubble sort

#include <bits/stdc++.h>

// Bubble sort using 2 for loops
void bubbleSortForLoop(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    // Last i elements are already in place
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

// Bubble sort using an outer while loop and a nested for loop
void bubbleSortWhileLoop(int arr[], int n)
{
  bool swapped = true;
  while (swapped)
  {
    swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
      if (arr[i] > arr[i +  1])
      {
        std::swap(arr[i], arr[i + 1]);
        swapped = true;
      }
    }
    n--;
  }
}

// Function to print an array
void printArray(int arr[], int size)
{
  std::cout << "size: " << size << "\n";

  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  
  std::cout << "\n";
}

// Driver code
int main()
{
  int arr[] = {5, 1, 4, 8, 2};
  int N = sizeof(arr) / sizeof(arr[0]);
  //bubbleSortForLoop(arr, N);
  bubbleSortWhileLoop(arr, N);
  std::cout << "Sorted array: \n";
  printArray(arr, N);
  return 0;
}