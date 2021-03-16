#include<iostream>
using namespace std;

int merge_sort(int *arr , int s , int e){
    int mid = (s + e)/2;
    int i = s;
    int j = mid + 1;
    int k = s;

    int temp[100000];
    int cnt = 0;   //cross inversion

    while(i <= mid && j <= e){
        if(arr[i] <= arr[j]){      //no inversions in this case
            temp[k] = arr[i];
            k++;
            i++;
        }
        else{
            temp[k] = arr[j];
            k++;
            j++;
            cnt += mid - i +1;
        }
    }
    //if any element is left in any of the two arrays
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= e){
        temp[k++] = arr[j++];
    }
    //copy all elements to the original array
    for(int i = s ; i <= e ; i++){
        arr[i] = temp[i] ;
    }
    return cnt;
}

int inversion_count(int *arr , int s , int e){
    //base case: if there is only 0 or 1 element,there will be no inversion
    if(s >= e){
        return 0;
    }
    int mid = (s + e)/2;
    int x = inversion_count(arr , s , mid);    //count of inversions in the first part of the array
    int y = inversion_count(arr , mid+1 , e);  //count of inversions in the second part of the array
    int z = merge_sort(arr , s ,e);            //count of cross inversions
    return x + y + z;                          //count of total inversions
}

int main(){
    int arr[] = {1, 5, 2 , 6, 3, 0};
    int n = sizeof(arr)/sizeof(int);

    cout<<inversion_count(arr , 0 , n-1);
    return 0;
}
