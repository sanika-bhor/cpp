#include<iostream>
#include<fstream>
#include <sstream>
#include<vector>

using namespace std;
class Student
{
    public:
    int id;
    string name;
    float CGPA;

    Student(int i, string n, float c) : id(i), name(n), CGPA(c) {}
    void display()
    {
        cout<<"\nid:"<<id;
        cout<<"\nname:"<<name;
        cout<<"\nCGPA:"<<CGPA;
    }
};

int main()
{
    ifstream streamFile("student.csv");
    if(!streamFile.is_open())
    {
        cout<<"\n error in openning file";
        return 1;
    }

    string line;
    vector<Student> students;

    while (getline(streamFile,line))
    {
        if(line.empty())
        {
            continue;
        }
        istringstream iss(line);

        int id;
        string name;
        float cgpa;


        // split by space
        iss>>id>>name>>cgpa;
        students.emplace_back(id, name, cgpa);

        // //split by comma or any other symbol
        // string id1, name1, cgpa1;
        // getline(iss, id1, ',');
        // getline(iss, name1, ',');
        // getline(iss, cgpa1, ',');

        // //stoi: string to integer
        // //stof: string to float
        // int id2=stoi(id1);
        // int cgpa2=stoi(cgpa1);


        // students.emplace_back(id2,name1,cgpa2);
    }

    streamFile.close();

    for(auto student: students)
    {
        student.display();
    }


    return 0;
}