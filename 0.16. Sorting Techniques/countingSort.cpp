#include<iostream>
using namespace std;

void counting_sort(int *arr, int n){
    //decide the range by finding the largest number in the array(assume numbers>0)
    int largest = -1;
    for(int i = 0 ; i < n ; i++){
        largest = max(largest , arr[i]);
    }
    //create a frequency array(initialize it with 0s)
    //loop over the array
    //increment the frequency of the particular number that is occurring
    int *freq = new int[largest+1]{0};
    for(int i  = 0 ; i < n ; i++){
        freq[arr[i]]++;
    }
    //put the elements in the array  arr by reading the freq array
    int j = 0;
    for(int i =0 ; i <= largest ; i++){
        //keep putting the element in the array till its freq=0
        while(freq[i] > 0){
            arr[j] = i;
            freq[i]--;
            j++;   //to increase the pointer of the array after placing one element
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    counting_sort(arr , n);
    //print the sorted array
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
