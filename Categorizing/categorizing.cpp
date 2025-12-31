#include <iostream>
#include <vector>
using namespace std;

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {
        int minIdx = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Merge Sort Helper Functions
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

// Linear Search
int linearSearch(const vector<int>& arr, int key) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(const vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Utility to print array
void printArray(const vector<int>& arr) {
    for(int num : arr)
        cout << num << " ";
    cout << endl;
}

// Main Menu
int main() {
    vector<int> arr = {34, 7, 23, 32, 5, 62};
    int choice, key;

    do {
        cout << "\n=== Algorithm Menu ===\n";
        cout << "1. Selection Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        vector<int> tempArr = arr; // Reset array

        switch(choice) {
            case 1:
                selectionSort(tempArr);
                cout << "Sorted using Selection Sort: ";
                printArray(tempArr);
                break;
            case 2:
                mergeSort(tempArr, 0, tempArr.size() - 1);
                cout << "Sorted using Merge Sort: ";
                printArray(tempArr);
                break;
            case 3:
                cout << "Enter element to search (Linear): ";
                cin >> key;
                {
                    int index = linearSearch(arr, key);
                    if(index != -1)
                        cout << "Element found at index " << index << endl;
                    else
                        cout << "Element not found\n";
                }
                break;
            case 4:
                mergeSort(tempArr, 0, tempArr.size() - 1); // Binary search requires sorted array
                cout << "Enter element to search (Binary): ";
                cin >> key;
                {
                    int index = binarySearch(tempArr, key);
                    if(index != -1)
                        cout << "Element found at index " << index << endl;
                    else
                        cout << "Element not found\n";
                }
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}
