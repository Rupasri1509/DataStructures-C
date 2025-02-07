#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int intArray[10];
int size;
bool isEmpty(){
   return size == 0;
}
int getMinimum(){
   return intArray[0];
}
int getLeftChildIndex(int nodeIndex){
   return 2*nodeIndex +1;
}
int getRightChildIndex(int nodeIndex){
   return 2*nodeIndex +2;
}
int getParentIndex(int nodeIndex){
   return (nodeIndex -1)/2;
}
bool isFull(){
   return size == 10;
}
/**
* Heap up the new element,until heap property is broken.
* Steps:
* 1. Compare node's value with parent's value.
* 2. Swap them, If they are in wrong order.
* */
void heapUp(int nodeIndex){
   int parentIndex, tmp;
   if (nodeIndex != 0) {
      parentIndex = getParentIndex(nodeIndex);
      if (intArray[parentIndex] > intArray[nodeIndex]) {
         tmp = intArray[parentIndex];
         intArray[parentIndex] = intArray[nodeIndex];
         intArray[nodeIndex] = tmp;
         heapUp(parentIndex);
      }
   }
}
/**
* Heap down the root element being least in value,until heap property is broken.
* Steps:
* 1.If current node has no children, done.
* 2.If current node has one children and heap property is broken,
* 3.Swap the current node and child node and heap down.
* 4.If current node has one children and heap property is broken, find smaller one
* 5.Swap the current node and child node and heap down.
* */
void heapDown(int nodeIndex){
   int leftChildIndex, rightChildIndex, minIndex, tmp;
   leftChildIndex = getLeftChildIndex(nodeIndex);
   rightChildIndex = getRightChildIndex(nodeIndex);
   if (rightChildIndex >= size) {
      if (leftChildIndex >= size)
         return;
      else
         minIndex = leftChildIndex;
   } else {
      if (intArray[leftChildIndex] <= intArray[rightChildIndex])
         minIndex = leftChildIndex;
      else
         minIndex = rightChildIndex;
   }
   if (intArray[nodeIndex] > intArray[minIndex]) {
      tmp = intArray[minIndex];
      intArray[minIndex] = intArray[nodeIndex];
      intArray[nodeIndex] = tmp;
      heapDown(minIndex);
   }
}
void insert(int value) {
   size++;
   intArray[size - 1] = value;
   heapUp(size - 1);
}
void removeMin() {
   intArray[0] = intArray[size - 1];
   size--;
   if (size > 0)
      heapDown(0);
}
main() {
   /*                     5                //Level 0
   *
   */
   insert(5);
   /*                     1                //Level 0
   *                     |
   *                 5---|                 //Level 1
   */
   insert(1);
   /*                     1                //Level 0
   *                     |
   *                 5---|---3             //Level 1
   */
   insert(3);
   /*                     1                //Level 0
   *                     |
   *                 5---|---3             //Level 1
   *                 |
   *              8--|                     //Level 2
   */
   insert(8);
   /*                     1                //Level 0
   *                     |
   *                 5---|---3             //Level 1
   *                 |
   *              8--|--9                  //Level 2
   */
   insert(9);
   /*                     1                 //Level 0
   *                     |
   *                 5---|---3              //Level 1
   *                 |       |
   *              8--|--9 6--|              //Level 2
   */
   insert(6);
   /*                     1                 //Level 0
   *                     |
   *                 5---|---2              //Level 1
   *                 |       |
   *              8--|--9 6--|--3           //Level 2
   */
   insert(2);
   printf("%d", getMinimum());
   removeMin();
   /*                     2                 //Level 0
   *                     |
   *                 5---|---3              //Level 1
   *                 |       |
   *              8--|--9 6--|              //Level 2
   */
   printf("\n%d\n", getMinimum());
   int c=0,a=1;

   for(int i=0;i<5;i++)
{
    for(int s=0;s<(5-i);s++)
    printf(" ");
for(int j=0;j<=a-1;j++)
{
if(c>5)
    break;
printf("%d ",intArray[c]);
c++;
}
a*=2;
printf("\n\t");
}
}
