/*
* sum_array.cpp
*
*It is a dynamically allocated array in which user will decide the size and data type and It will give the sum of all the elements in array.
*
* Author: Ekamleen Maan 
* Creation date: September 14, 2023
*/


    #include <iostream>	         // As you need to print data
    #include "sum_array.h"	    // The header file for the class - you need this!

    using std::cout;	        // The implementation of this class uses the object cout
    using std::endl;	        // and the object endl
    using std::cin;	



        int sumOfElements(int arr[], unsigned int size){
        int sum = 0; 
        for(int i = 0; i< size; i++)
        {
        sum += arr[i];
        }
        return sum;
        }

        void IA(int arr[], unsigned int size){
        cout<< "please enter the elements"<<endl;
        for(int i =0; i<size;i++){
        cin>>arr[i];
        }
        }

        void PA(int arr[], unsigned int size){
        cout<<"the array is: "<<endl;
        for(int i = 0; i<size; i++){
            cout<<arr[i];
        }
        }

        int main(){
        
        int * arr = nullptr;       // Pointer variable, can point to an array of int
        unsigned int arrSize = 0;  // user will define it. 

        cout<< "please enter the size"<<endl;
        cin>> arrSize;
            arr = new int[arrSize];


        if(arr!= nullptr){
        IA(arr, arrSize);
        }
        PA(arr,arrSize);

        cout<<endl;

        int sum = sumOfElements(arr,arrSize);
        cout<<"sum is : "<<sum<<endl;
        
     
        delete[] arr;
        return 0;
        }


















