 #include<iostream>
 #include<cstring>
 using namespace std;

void moveAtEnd(char str[1000], int i, int len)
{
    if (i >= len){
        return;
    }
    // Store current character
    char curr = str[i];

    // Check if current character is not 'x'
    if (curr != 'x')
        cout << curr;

    // recursive function call
    moveAtEnd(str, i + 1, len);

    // Check if current character is 'x'
    if (curr == 'x')
        cout << curr;

    return;
}

// Driver code
int main()
{
    char str[1000];
    cin>>str;
    int len = strlen(str);
    moveAtEnd(str, 0, len);
    return 0;
}
