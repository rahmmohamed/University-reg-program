#include <stdio.h>
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isFileEmpty(const string& filename) {
    ifstream file(filename);
    return file.peek() == ifstream::traits_type::eof();
}
   
int getid(){
      ifstream file("students.txt"); // open file for reading

    if (!file.is_open()) {
       
        cout << "Error opening file!" << endl;
        return 0;
    }
    if(isFileEmpty("students.txt"))
    {
        return 0;
    }

 
int id;
string name;
int age;
bool note;
int asd1,asd2;
    while (file >> id >> name >> age>> note >>asd1>>asd2) { id=id;}
       
    
    file.close();
    return id;
}
void addStudent(int *id) {
    string name;int age;bool note = false;

  printf("Enter student name: ");
  cin >> name;
    printf("Enter student age: ");
  cin >> age;
 *id = *id + 1;  // Increment ID for the new student
    cout << "Adding a new student...\n" << endl;
  // Store student details (name, age, id) in your data structure here
    cout << "Student added with ID: " << *id << endl;
ofstream file("students.txt", ios::app);
    if (file.is_open()) {
        file << *id << " " << name << " " << age << " "<<note<<" "<<0<<" "<<0<< endl;
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
        bool note;
        int asd1,asd2;
        while(file >> id >> name >> age>> note >>asd1>>asd2)
       { cout<<"id : "<<id<<"\t"<<"name"" : "<<name<<"\t" << "age:"<< age<<endl;}
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
        bool note;
        int asd1,asd2;
        while(file >> id >> name >> age>> note >>asd1>>asd2) {
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
void deleteStudent() {
    // Implement logic to delete a student
    int id2;
  printf("enter id to delete\n");
            cin>>id2;
   
    cout << "Deleting a student...\n" << endl;
ofstream file("temp.txt");
ifstream file2("students.txt");
if(file2.is_open())
  {
   
int id,age;string name;
bool note;
int ind=0;
int asd1,asd2;
while(file2 >> id >> name >> age>> note >>asd1>>asd2)
{  
if(id==id2)
{continue;}
ind ++; 
file << id << " " << name << " " << age << " "<<note<<" "<<asd1<<" "<<asd2<< endl;

}

file2.close();
file.close();
remove("students.txt");
rename("temp.txt","students.txt");
cout<<"student deleted\n"<<endl;
if(ind==0)
 {
remove("students.txt");
cout<<"no students left\n"<<endl;
 }
  }
else{cout<<"Unable to open file\n"<<endl;}

}
void addOrUpdateNote() {
    // Implement logic to add or update a student's note
    bool f=false;
        fstream file("students.txt", ios::in | ios::out | ios::app);
        
    if (!file.is_open()) {
        cout << "Unable to open file.\n" << endl;   
        return;
    }
    if (isFileEmpty("students.txt"))
    {
        /* code */
        cout<<"no students to add note for\n"<<endl;
        return;
    }
            ofstream tempFile("temp.txt");

int id;
string name;
int age;
bool note;
int asd1,asd2;

while (file >> id >> name >> age>> note >>asd1>>asd2)
{
    cout<<"do you want to add note for student with name"<<name<<" (1 for yes, 0 for no): ";
    int choice;
    cin>>choice;

    if(choice==1)
    {
        f=true;
        int asd1,asd2;
        note=true;
        cout<<"enter note asd1: ";
        cin>>asd1;
        cout<<"enter note asd2: ";
        cin>>asd2;
        tempFile << id << " " << name << " " << age << " "<<note<<" "<<asd1<<" "<<asd2<< endl;
    }
    else if(choice==0 && f==true)
    {
        note=false;
        asd1=0;
        asd2=0;
        tempFile << id << " " << name << " " << age << " "<<note<<" "<<asd1<<" "<<asd2 <<endl;
    }

    else
    {
        note=false;
    }

}

file.close();
tempFile.close();
if (f==true)
{
    remove("students.txt");
    rename("temp.txt", "students.txt");
}
if (f==false)
{
    /* code */
    remove("temp.txt");
    cout<<"no notes added\n"<<endl;
}




}


int main() {
   
    int id=getid();
    printf("there are %d students\n",id);
    cout << "Hello, !\n" << endl;
        cout << "1- ADD STUDENT\n" << endl;
    cout << "2- Show all\n" << endl;

    cout << "3- gSearch\n" << endl;
    cout << "4-Delete  !\n" << endl;
    cout << "5-add or udpate note !\n" << endl;
    cout << "Enter your choice (1-5): ";
int choice;
    cin >> choice;
    switch (choice) {
        case 1:
         {  addStudent(&id);
            break;}
        case 2:
        {
            showAllStudents();
            break;}
        case 3:
        {
            searchStudent();
            break;}
        case 4:
      {
          
            deleteStudent();
            break;}
            case 5:
            {
               addOrUpdateNote()    ;
                break;
            }
        default:
            cout << "Invalid choice. Please try again.\n" << endl;
            break;
    }

    
    return 0;
}
