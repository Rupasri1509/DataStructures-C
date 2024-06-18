#include <stdio.h>

// swap function

void swap(int *a, int *b)
{
int temp = *b;
*b = *a;
*a = temp;
}


// Function to print the Heap as array

// will print as - 'message array[]\n'

void printArray(char message[], int arr[], int n)
{

printf("%s ",message);

for (int i = 0; i < n; ++i)
{
printf("%d ", arr[i]);
}

printf("\n");
}


// To heapify a subtree with node i as root

// Size of heap is n

void heapify(int arr[], int n, int i)
{
int largest = i; // Initialize largest as root
int leftChild = 2 * i + 1; // left child = 2*i + 1
int rightChild = 2 * i + 2; // right child = 2*i + 2

// If left child is greater than root

if (leftChild < n && arr[leftChild] > arr[largest])
largest = leftChild;

// If right child is greater than new largest

if (rightChild < n && arr[rightChild] > arr[largest])
largest = rightChild;

// If largest is not the root

if (largest != i)
{
// swap root with the new largest

swap(&arr[i], &arr[largest]);

// Recursively heapify the affected sub-tree i.e, subtree with root as largest
heapify(arr, n, largest);
}
}
void heapifyd(int arr[], int n, int i)
{
int small = i; // Initialize largest as root
int leftChild = 2 * i + 1; // left child = 2*i + 1
int rightChild = 2 * i + 2; // right child = 2*i + 2

// If left child is greater than root

if (leftChild < n && arr[leftChild] < arr[small])
small = leftChild;

// If right child is greater than new largest

if (rightChild < n && arr[rightChild] < arr[small])
small = rightChild;

// If largest is not the root

if (small != i)
{
// swap root with the new largest

swap(&arr[i], &arr[small]);

// Recursively heapify the affected sub-tree i.e, subtree with root as largest
heapifyd(arr, n, small);
}
}


// Function to build a Max-Heap from a given array

void buildHeap(int arr[], int n)
{
// Index of last non-leaf node
int lastNonLeafNode = (n / 2) - 1;

// Perform level order traversal in reverse from last non-leaf node to the root node and heapify each node
for (int i = lastNonLeafNode; i >= 0; i--)
{
heapify(arr, n, i);
}
}
void buildhea(int arr[], int n)
{
    int lastNonLeafNode = (n / 2) - 1;

// Perform level order traversal in reverse from last non-leaf node to the root node and heapify each node
for (int i = lastNonLeafNode; i >= 0; i--)
{
heapifyd(arr, n, i);
}
}
void deletemin(int a[], int n)
{
    a[0]=a[n-1];
   // a[n-1]=NULL;
    n--;
    heapifyd(a,n,0);
}
void deletemax(int a[], int n)
{
    a[0]=a[n-1];
   // a[n-1]=NULL;
    n--;
    heapify(a,n,0);
}

// Driver Code

void main()
{
// Array
int a,b;
printf("ENTER THE SIZE OF ARRAY : ");
scanf("%d",&a);
b=a;
int arr[a],arr1[a],n1;
printf("ENTER THE DATA:\n");
for(int i=0;i<a;i++)
{
    scanf("%d",&arr[i]);
    arr1[i]=arr[i];
    /*if(n1==-1)
        break;
    arr[i]=n1;*/
}

// Size of array

printArray("Array is : ", arr, a);

buildHeap(arr, a);
printArray("Array representation of MAXHeap is : ", arr, a);
buildhea(arr1,a);
printArray("Array representation of MINHeap is : ", arr1, a);
deletemin(arr1,a);
a--;
printArray("Array representation of after deletemin is : ", arr1, a);
deletemax(arr,b);
b--;
printArray("Array representation of after deletemax is : ", arr, b);
}
