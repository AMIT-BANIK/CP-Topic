#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (x == array[mid])
      return mid;

    // Search the right half
    if (x > array[mid])
      return binarySearch(array, x, mid + 1, high);

    // Search the right half
    return binarySearch(array, x, low, mid - 1);
  }

  return -1;
}

int main(void) {
  int array[] = {3, 4, 5, 6, 7, 8, 9};
  int x = 4;
  int n = sizeof(array) / sizeof(array[0]);
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
}
