// C program to find maximum in arr[] of size n
#include <stdio.h>
//include AGGREGATE file
//#include <AGGREGATE.H>

//declare function prototype in header file
float max(float arr[], int n);
float min(float arr[], int n);
float sum(float arr[], int n);
float avg(float arr[], int n);
float pseudoavg(float arr[], int n);

//declare array of function pointers of size 5
float (*aggregates[5]) (float arr[], int n) = {max, min, sum, avg, pseudoavg};

int main()
{
    //Question 3
    float arr[] = {1.1,5.3,4.1,4.4,2.9};
    //size of the array stored in var n
    int n = sizeof(arr)/sizeof(arr[0]);
    //calling the functions and printing the returned value
    printf("Largest in given array is  %.6f.\n", max(arr, n));
    printf("Smallest in given array is  %.6f.\n", min(arr, n));
    printf("Sum of the given array is  %.6f.\n", sum(arr, n));
    printf("Average of the given array is  %.6f.\n", avg(arr, n));
    printf("Pseudo Average of the given array is  %.6f.\n", pseudoavg(arr, n));
    
    //Question 4
    float arr1[] = {1.1,5.3,4.1,4.4,2.9};
    float arr2[] = {1.1,5.3,4.1,4.4,2.9,10.1,80.3,60.1,20.4,20.9};
    //variable to store the returning value of the function
    float result;
    //go through each function of function pointer for arr1
    for(int i=0; i<5; i++){
        result = (*aggregates[i])(arr1, 5); //call the method
        printf("%f\n", result); //print the result
    }
    //go through each function of function pointer for arr2
    for(int i=0; i<10; i++){
        result = (*aggregates[i])(arr2, 10); //call the method
        printf("%f\n", result); //print the result
    }
    
    return 0;
}

// C function to find maximum in arr[] of size n
float max(float arr[], int n){
    if(n<0){
        printf("FATAL ERROR in line");
        //terminate the program
    }
    
    float max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// C function to find minimum in arr[] of size n
float min(float arr[], int n){
    if(n<0){
        printf("FATAL ERROR in line");
        //terminate the program
    }
    float min = arr[0];
    for (int i = 1; i < n; i++)
        if (min > arr[i])
            min = arr[i];
    return min;
}

// C function to find the sum of all elements in arr[] of size n
 float sum(float x[], int n) {
    if(n<0){
        printf("FATAL ERROR in line");
        //terminate the program
    }
    float s = x[0];
    for (int i = 1; i < n; i++) {
        s += x[i];
    }
    return s;
}

//average of all elements in arr[] of size n
float avg(float arr[], int n){
    if(n<0){
        printf("FATAL ERROR in line");
        //terminate the program
    }
    return sum(arr,n)/n;
}

//pseudo average of arr[] of size n
float pseudoavg(float arr[], int n){
    if(n<0){
        printf("FATAL ERROR in line");
        //terminate the program
    }
    return (max(arr, n)+min(arr, n))/2;
}