#include<iostream>
using namespace std;

template<typename T>
int search(T arr[], int n, T key){
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return n;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    int key = 3;
    cout<<search(arr, n, key)<<endl;

    //it will also work for a float,char or any other array
    float a[] = {1.1, 1.2, 1.3};
    float k = 1.2;
    cout<<search(a, 3, k);
    return 0;
}
