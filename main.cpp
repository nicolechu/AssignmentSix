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
 #include <fstream>
 #include <sstream>
 #include "Sorts.cpp"

 using namespace std;

 int main(int argc, char* argv[])
 {
   // command line argument (file of doubles)
   // first line = # of items to sort (# of doubles?)
   // read values into array -- need 4 copies to do 3 sorts
      // dynamic memory allocation???
      // refer to Assignment 1 (passing arrays as arguments)
   // output (for each sort) name of sort, start time stamp, end time stamp
   // use time library for time stamps

   /*
   * Creates an ifstream object inputFile and string fileName to access user's text file
     which contains doubles to be sorted
   */
   ifstream inputFile;
   string fileName;
   int numDoubles = 0;
   double *arr;
   /*
    * Takes file as command line argument
    * If no file name is entered, user is prompted to enter name of file
    * If a file name is passed, the argument is assigned to string fileName
    * If more than one file name is entered, session is terminated
    */
    switch(argc)
    {
      case 1:
        cout << "Please enter the name of your text file: ";
        cin >> fileName;
        break;
      case 2:
        fileName = argv[1];
        break;
      default:
        cout << "ERROR: Please enter one file name." << endl;
        exit;
    }

    inputFile.open(fileName);
    if(!inputFile.is_open())
    {
      cout << "ERROR: File does not exist." << endl;
      exit;
    }
    else
    {
      string line;
      int count = 0;
      while(getline(inputFile, line))
      {
        count++;

        if(count == 1)
        {
          stringstream s(line);
          s >> numDoubles;
        }
        else
        {
          if(count == 2)
          {
            // declare array of size numDoubles
            // http://www.cplusplus.com/doc/tutorial/dynamic/
            arr = new double[numDoubles]; // dynamic memory allocation
          }

          double temp;
          stringstream s(line);
          s >> temp;
          arr[count - 2] = temp;
        }
      }

      // create copies of the array (length is numDoubles)
      double arr1[numDoubles];
      double arr2[numDoubles];
      double arr3[numDoubles];

      for(int i = 0; i < numDoubles; i++)
      {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
      }


      Sorts s;

      // quick sort
      cout << "Quick Sort" << endl;

      clock_t start = clock();
      cout << start << endl;

      s.QuickSort(arr, 0, numDoubles - 1);

      clock_t end = clock();
      cout << end << endl;

      double elapsed = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
      cout << "Time elapsed (ms): " << elapsed << endl;

      // insertion sort
      cout << "Insertion Sort" << endl;

      start = clock();
      cout << start << endl;

      s.InsertionSort(arr1, numDoubles);

      end = clock();
      cout << end << endl;

      elapsed = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
      cout << "Time elapsed (ms): " << elapsed << endl;

      // bubble sort
      cout << "Bubble Sort" << endl;

      start = clock();
      cout << start << endl;

      s.BubbleSort(arr2, numDoubles);

      end = clock();
      cout << end << endl;

      elapsed = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
      cout << "Time elapsed (ms): " << elapsed << endl;

      // selection sort
      cout << "Selection Sort" << endl;

      start = clock();
      cout << start << endl;

      s.SelectionSort(arr3, numDoubles);

      end = clock();
      cout << end << endl;

      elapsed = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
      cout << "Time elapsed (ms): " << elapsed << endl;
    }
 }
