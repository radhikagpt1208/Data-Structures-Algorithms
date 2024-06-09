#include<iostream>
#include<vector>
using namespace std;

class Student{
    public:
        int marks;
        string name;
};

void bucket_sort(Student s[] , int n){
    //assuming marks are in the range 0-100
    vector<Student> v[101];
    for(int i = 0 ; i < n ; i++){
        int m = s[i].marks;
        //push the student in the respective vector acc to the marks
        v[m].push_back(s[i]);
    }
    //Iterate over the vector and print the students(higher marks first;followed by the rest)
    for(int i = 100 ; i >=0 ; i--){
        //iterate over the ith vector and print the marks and name of the students
        for(vector<Student>::iterator it = v[i].begin() ; it != v[i].end() ; it++){
            cout<<(*it).marks<<" "<<(*it).name<<endl;
        }
    }
}

int main(){
    Student s[100000];
    //number of students
    int n;
    cin>>n;

    for(int i = 0 ; i < n ; i++){
        cin>>s[i].marks>>s[i].name;
    }
    bucket_sort(s , n);
    return 0;
}
