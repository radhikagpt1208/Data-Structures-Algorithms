/* We are given an array containing n numbers. All the numbers are present twice except for two numbers which are present only once.
Find the unique numbers in linear time without using any extra space. Smaller number comes before larger number.
Approach :
We first take the XOR of all the numbers. At the end, we are left with the XOR of two numbers(which are present only once as all
the other elements get canceled because n^n=0). Now,from result of XOR of the 2 remaining values,we try to find the 2 unique nos.
Let this value of XOR be 'x'. Now, it can be inferred that x can never be zero because it is the resultant of XOR of 2 unique nos.
Hence,x will contain at least 1 set bit.
Now we will try to find the position of this set bit in x. Let this position be 'i'. This would mean that at the i-th position,
only one of the two unique nos. will have a set bit and the other one will have a 0 because only then XOR of the bits at i-th
position of both the nos. results in a set bit in x.
Now we will make a list 'a' which will have those nos. that have set bit at i-th position. We will then do a XOR of all the values
in the list which will result in one unique number.
Now to find the second unique number : Since you have already found the first unique number and you also have the XOR of both the
unique nos. that is x, you can do a XOR of x with the first unique number to find the second one */

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[100005];
    int num;
    int x = 0;
    for(int i = 0; i < n; i++){
        cin>>num;
        arr[i] = num;
        x =  x ^ num;
    }
    //after computing all XOR of all elements,the final value in 'xor' = a^b where a and b are the 2 unique nos.
    int temp = x;
    //find the position of the first set bit from the right
    int pos = 0;
    while((temp&1) != 1){
        pos++;
        temp = temp>>1;
    }
    //create a mask to check if there is a set bit at position 'pos' in all the element and then do bitwise & of the mask with all the
    //elements and if it turns out to be > 0,that means the element has a set bit at pos.
    //let 'a' be the first unique no. We will keep adding the XOR of all those elements in 'a' which have a set bit at 'pos'.
    //such that 'a' will finally result in the first unique no.
    int a = 0;
    int mask = 1 << pos;
    //find nos. that contain set bit at position 'pos'
    for(int i = 0; i < n; i++){
        if((arr[i] & mask) > 0){
            a = a ^ arr[i];
        }
    }
    //second unique number
    int b = 0;
    b = x ^ a;

    cout<<min(a, b)<<" "<<max(a, b)<<endl;

    return 0;
}


















