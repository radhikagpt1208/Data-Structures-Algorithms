#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

class Student{
public:
    string firstName;
    string lastName;
    string rollno;

    Student(string f, string l, string no){
        firstName = f;
        lastName = l;
        rollno = no;
    }

    //if there are 2 students with the same name,compare them by their roll no
    //compare the roll no of the current student with the roll no given
    //hence we overload == operator
    bool operator==(const Student &s)const{
        return rollno == s.rollno;
    }
};

//to compute idx of a student
class HashFn{
public:
    //size_t is an unsigned int data type used to represent size of some memory in bytes
    //operator overloading
    size_t operator()(const Student &s)const{
        return s.firstName.length() + s.lastName.length();
    }
};

int main(){
    //key is a custom class(Student), value is int, and the hashfunc is defined
    unordered_map<Student, int, HashFn> student_map;

    Student s1("Prateek", "Narang", "010");
    Student s2("Rahul", "Kumar", "023");
    Student s3("Prateek", "Gupta", "030");
    Student s4("Rahul", "Kumar", "120");

    //Add student-marks in the hash map
    student_map[s1] = 100;
    student_map[s2] = 120;
    student_map[s3] = 11;
    student_map[s4] = 45;

    //iterate over all student
    for(auto s : student_map){
        cout<<s.first.rollno<<" "<<s.first.firstName<<" "<<s.first.lastName<<" Marks : "<<s.second<<endl;
    }

    //find the marks of a particular student
    cout<<student_map[s3]<<endl;

    return 0;
}
