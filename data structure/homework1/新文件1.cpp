#include<iostream> 
#include<iomanip>
#include <bits/stdc++.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
void SelectionSort(int arr[], int n);
void QuickSort(int arr[],int end);


int S[1000000];
int Q[1000000];

int main() {
	int N = 1000000;
	
	DWORD star_time;
	DWORD end_time;
	double times;
	srand( time(NULL) );
	
	for(int i = 0;i < N;i++){
		//fair comparison
		int x = rand();
		S[i] = x;
		Q[i] = x;
	}

	ofstream newFile;
    newFile.open("test1000000.txt");

	//-------------SelectionSort-----------//
	newFile << "SelectionSort :"<<endl;
	for (int i=0; i < N; i++){
        newFile << S[i] << " ";
    }
    newFile << endl;
    
    star_time = GetTickCount();
    SelectionSort(S,N);
    end_time = GetTickCount();
    times= static_cast<double>(end_time - star_time)/1000;
    newFile << "Selection sort執行時間 : "<<setprecision(5)<<times << "s." << endl;
    
    for (int i=0; i < N; i++){
        newFile << S[i] << " ";
    }
    newFile << endl;
    //-------------SelectionSort-----------//
    
    newFile << endl;
    
    //-------------QuickSort--------------//
    newFile << "QuickSort :"<<endl;
    for (int i=0; i < N; i++){
        newFile << Q[i] << " ";
    }
    newFile << endl;

	star_time = GetTickCount();
	QuickSort(Q,N);
	end_time = GetTickCount();
	times= static_cast<double>(end_time - star_time)/1000;
    newFile << "QuickSort sort執行時間 : "<<setprecision(5)<<times << "s." << endl;
	
    for (int i=0; i < N; i++){
        newFile << Q[i] << " ";
    }
    newFile << endl;
    //-------------QuickSort--------------//
    
    newFile.close();
    return 0;
}

int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void originequickSort(int arr[], int start, int end)//from:https://www.geeksforgeeks.org/cpp-program-for-quicksort/
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    originequickSort(arr, start, p - 1);
 
    // Sorting the right part
    originequickSort(arr, p + 1, end);
}

void QuickSort(int arr[],int end){
	originequickSort(arr, 0, end-1);
}

 //-------------------------------------------------------------------------------------------------------------

void arrayswap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void SelectionSort(int arr[], int n)//from:https://www.geeksforgeeks.org/selection-sort/
{
    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n-1; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        if(min_idx!=i)
            arrayswap(&arr[min_idx], &arr[i]);
    }
}
