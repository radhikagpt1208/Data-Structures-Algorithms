#include<iostream>
using namespace std;

int partition(int *arr, int s, int e){
    int i = s - 1;
    int j = s;
    int pivot = arr[e];
    for( ; j <= e - 1 ; ){
        if(arr[j] <= pivot){
            //merge the smaller element in the region 1,i.e,the region which has elements smaller than the pivot element
            i = i + 1;   //expand the smaller region
            swap(arr[i] , arr[j]);
        }
        //expand the larger region
        j = j + 1;
    }
    //place the pivot element in the correct index
    swap(arr[i + 1] , arr[e]);
    return i + 1; //index of pivot element
}

void quick_sort(int *arr, int s, int e){
    //base case: if there are 0 or 1 element
    if(s >= e){
        return;
    }
    //rec case
    int p = partition(arr, s, e);
    //once we get the pivot element index,we can sort the left and the right part
    //left part
    quick_sort(arr, s, p - 1);
    //right part
    quick_sort(arr, p + 1, e);
}

int main(){
    int arr[] = {2, 7, 8, 6, 1, 5, 4};
    int n = sizeof(arr)/sizeof(int);
    quick_sort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
