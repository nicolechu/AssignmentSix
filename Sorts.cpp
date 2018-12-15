/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #6
 */

/*
 * File description
 */

 #include <iostream>
 #include "Sorts.h"
 #include <ctime>

 using namespace std;

// needs time stamps

 void Sorts::BubbleSort(double* arr, int length)
 {
   double temp;
   for(int i = 0; i < length; i++)
   {
     for(int j = 0; j < length - i - 1; j++)
     {
       if(arr[j] > arr[j+1])
       {
         temp = arr[j];
         arr[j] = arr[j+1];
         arr[j+1] = temp;
       }
     }
   }
 }

 void Sorts::InsertionSort(double* arr, int length)
 {
   double temp;
   for(int i = 1; i < length; i++)
   {
     temp = arr[i];
     int j = i;
     while(j > 0 && arr[j-1] >= temp)
     {
       arr[i] = arr[j-1];
       j--;
     }
     arr[j] = temp;
   }
 }

 void Sorts::QuickSort(double* arr, int low, int high)
 {
   int i = low;
   int j = high;
   double temp;
   double pivot = arr[(low + high)/2];

   while(i <= j)
   {
     while(arr[i] < pivot)
      i++;
     while(arr[j] > pivot)
      j--;
     if(i <= j)
     {
       temp = arr[i];
       arr[i] = arr[j];
       arr[j] = temp;
       i++;
       j--;
     }
   }

   if(low < j)
    QuickSort(arr, low, j);
   if(i < high)
    QuickSort(arr, i, high);
 }

 void Sorts::SelectionSort(double* arr, int length)
 {
   int minIndex;
   double temp;

   for(int i = 0; i < length - 1; i++)
   {
     minIndex = i;

     for(int j = i + 1; j < length; j++)
     {
       if(arr[j] < arr[minIndex])
        minIndex = j;
     }

     if(minIndex != i)
     {
       temp = arr[i];
       arr[i] = arr[minIndex];
       arr[minIndex] = temp;
     }
   }
 }
