#include <stdio.h>
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
int getid(){
    ifstream file("students.txt");
    if(file.is_open()) {
        int id , age;
        string name;
        while(file>>id>>name>>age)
        {
            id=id;
        }
        file.close();
        return id;
    } else {
        cout << "Unable to open file.\n" << endl;
        return 0;

    }
}
void addStudent(int *id) {
    string name;int age;
  printf("Enter student name: ");
  cin >> name;
    printf("Enter student age: ");
  cin >> age;
  int k=*id;
  k++;
  *id=k;
  // Store student details (name, age, id) in your data structure here
    cout << "Student added with ID: " << *id << endl;
ofstream file("students.txt", ios::app);
    if (file.is_open()) {
        file << *id << " " << name << " " << age << endl;
        file.close();
        cout << "Student details saved to file.\n" << endl;
    } else {
        cout << "Unable to open file.\n" << endl;
    }
    
}
void showAllStudents() {
    // Implement logic to display all students
    cout << "Displaying all students...\n" << endl;
    ifstream file("students.txt");
    if(file.is_open()) {
        int id , age;
        string name;
        while(file>>id>>name>>age)
        cout<<"id : "<<id<<"\t"<<"name"" : "<<name<<"\t" << "age:"<< age<<endl;
        file.close();
    } else {
        cout << "Unable to open file.\n" << endl;
    }
}
void searchStudent() {
    // Implement logic to search for a student
     string name2;
    cout << "Enter student name to search: ";
    cin >> name2;
    int age2;
    cout << "Enter student age to search: ";
    cin >> age2;
    cout << "Searching for a student...\n" << endl;
    ifstream file("students.txt");
    if(file.is_open()) {
        int id , age;
        string name;
        bool found = false;
        while(file>>id>>name>>age) {
            if(name == name2 && age == age2) {
                cout << "Student found: ID: " << id << ", Name: " << name << ", Age: " << age << endl;
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "Student not found.\n" << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file.\n" << endl;
    }

}
void deleteStudent(int id2) {
    // Implement logic to delete a student

   
    cout << "Deleting a student...\n" << endl;
ofstream file("temp.txt");
ifstream file2("students.txt");
if(file2.is_open())
  {
   
int id,age;string name;
int ind=0;
while(file2>>id>>name>>age)
{  
if(id==id2)
continue;
ind ++; 
file<<ind<<" "<<name<<" "<<age<<endl;

}

file2.close();
file.close();
remove("students.txt");
rename("temp.txt","students.txt");
if(ind==0)
 {
remove("students.txt");
cout<<"no students left\n"<<endl;
 }
  }
else{cout<<"Unable to open file\n"<<endl;}

}



int main() {
    while(true){
    int id=getid();
    printf("there are %d students\n",id);
    cout << "Hello, !\n" << endl;
        cout << "1- ADD STUDENT\n" << endl;
    cout << "2- Show all\n" << endl;

    cout << "3-Search\n" << endl;
    cout << "4-Delete  !\n" << endl;
int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            addStudent(&id);
            break;
        case 2:
        
            showAllStudents();
            break;
        case 3:
           
            searchStudent();
            break;
        case 4:
        int id2;
            printf("enter id to delete\n");
            cin>>id2;
            deleteStudent(id2);
            break;
        default:
            cout << "Invalid choice. Please try again.\n" << endl;
            break;
    }
    return 0;
    }
   
}