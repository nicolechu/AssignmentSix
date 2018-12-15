/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #6
 */

/*
 * File description
 */
#ifndef SORTS_H
#define SORTS_H
#include <iostream>

using namespace std;

class Sorts
{
public:
 void QuickSort(double* arr, int low, int high);
 void InsertionSort(double* arr, int length);
 void BubbleSort(double* arr, int length);
 void SelectionSort(double* arr, int length);
};

#endif
