//APPROACH:
//For every bar 'x', we calculate the area with 'x' as the smallest bar in the rectangle.
//calculate such area for every bar 'x' and find the maximum of all areas.
//For this,index of the first smaller(smaller than 'x')bar on left of x and index of first smaller bar on right of x has to be known.
//We traverse all bars from left to right, maintain a stack of bars. Every bar is pushed to stack once.
//A bar is popped from stack when a bar of smaller height is seen.
//When a bar is popped, we calculate the area with the popped bar as smallest bar.
//For left and right indexes of the popped bar: the current index tells us the 'right index'
//and index of previous item in stack is the 'left index'.
//2 formulas of areas to be used:
    //a. When stack is empty: Area = height of current bar which we consider to have the min height * rightIndex(current index)
    //                               = a[s.top()] * i
    //b. When stack is not empty: Area = height of the current bar(min bar) * (rightIndex - leftIndex - 1)
    //                                 = node that is popped(i.e,a[s.top()])*(i - s.top() - 1); where s.top() is the previous top

//STEPS
//1.Create an empty stack.
//2)Start from first bar, and do following for every bar in a[i] where i varies from 0 to n-1.
    //a) If stack is empty or arr[i] is higher than the bar at top of stack, then push i to stack.
    //b) If this bar is smaller than the top of stack,then keep removing the top of stack while top of the stack is greater.
         //Let the removed bar be arr[top]. Calculate area of rectangle with arr[top] as smallest bar.
         //For arr[top], the 'left index' is previous(previous to top)item in stack and 'right index' is 'i' (current index).
//3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.

#include<iostream>
#include<stack>
using namespace std;

int getMaxArea(int arr[], int n){
    stack<int> s;

    int max_area = 0;
    int top;      //to store top of the stack
    int area;     // To store area with top bar as the smallest bar

    int i = 0;
    while(i < n){
        // If this bar is higher than the bar on top stack, push it to stack
        if(s.empty() || arr[s.top()] <= arr[i]){
            s.push(i);
            i++;
        }
        // If this bar is lower than top of stack,then calculate area of rectangle
        //with stack top as the smallest(or minimum height)bar.
        // 'i' is 'right index' for the top and element before top in stack is 'left index'
        else{
            top = s.top();
            s.pop();
            // Calculate the area with arr[top] stack as smallest bar
            if(s.empty()){
                area = arr[top] * i;
            }
            else{
                area = arr[top] * (i - s.top() - 1);
            }
            // update max area, if needed
            if(max_area < area)
                max_area = area;
        }
    }
    //now pop the remaining bars from stack and calculate area with every popped bar as the smallest bar
    while(!s.empty()){
        top = s.top();
        s.pop();
        if(s.empty()){
            area = arr[top] * i;
        }
        else{
            area = arr[top] * (i - s.top() - 1);
        }
        if(max_area < area){
            max_area = area;
        }
    }
    return max_area;
}

int main(){
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr)/sizeof(int);
    cout << "Maximum area is " << getMaxArea(arr, n);
    return 0;
}
