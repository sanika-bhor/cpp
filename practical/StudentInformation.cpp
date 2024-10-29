/*Experiment No. 2: Develop a program in C++ to create a database of student’s
information system containing the following information: Name, roll number, Class,
Division, Date of Birth, Blood group, contact address, Telephone number, Driving license
no. and other. Construct the database with suitable member functions. Make use of
constructor, default constructor, copy constructor, destructor, static member functions,
friend class, this pointer, inline code and dynamic memory allocation operators-new and
delete as well as exception handling.*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Student
{
private:
    static int studCount; // Static member for student count
    string name;
    int roll_number;
    string class_name;
    string division;
    string date_of_birth;
    string blood_group;
    string contact_address;
    long long telephone_number;
    string driving_license;

public:
    // Default constructor
    Student()
    {
        name = "sanika";
        roll_number = 24010011;
        class_name = "SE";
        division = "CS";
        date_of_birth = "27/07/2005";
        blood_group = "O+";
        contact_address = "pune";
        telephone_number = 9322084169;
        driving_license = "00000000";
        studCount++; // Increment count when student is created
    }

    Student(string name, int roll, string cls, string div, string dob, string bg, string addr, long long phone, string dl)
    {
        this->name = name;
        this->roll_number = roll;
        this->class_name = cls;
        this->division = div;
        this->date_of_birth = dob;
        this->blood_group = bg;
        this->contact_address = addr;
        this->telephone_number = phone;
        this->driving_license = dl;
        studCount++;
    }

    // copy constructor
    Student(const Student &s1)
    {
        name = s1.name;
        roll_number = s1.roll_number;
        class_name = s1.class_name;
        division = s1.division;
        date_of_birth = s1.date_of_birth;
        blood_group = s1.blood_group;
        contact_address = s1.contact_address;
        telephone_number = s1.telephone_number;
        driving_license = s1.driving_license;
        studCount++;
    }

    // static member function
    static void displayCount()
    {
        cout << "\n\nstudent: " << studCount;
    }

    // Inline function to display student information
    inline void displayInfo() const
    {
        cout << "\nName: " << name;
        cout << "\nRoll Number: " << roll_number;
        cout << "\nClass: " << class_name;
        cout << "\nDivision: " << division;
        cout << "\nDate of Birth: " << date_of_birth;
        cout << "\nBlood Group: " << blood_group;
        cout << "\nContact Address: " << contact_address;
        cout << "\nTelephone Number: " << telephone_number;
        cout << "\nDriving License: " << driving_license;
    }
    // destructor
    ~Student()
    {
        cout << "\nThank you...";
    }

    // Friend class to access private members
    friend class Database;
    ;
};

// Initialize static member
int Student::studCount = 1;

class Database
{
public:
    void displayStudent(const Student &s)
    {
        cout << "\n\nDisplaying student details from Database: ";
        cout << "\nName: " << s.name;
        cout << "\nRoll Number: " << s.roll_number;
        cout << "\nClass: " << s.class_name;
        cout << "\nDivision: " << s.division;
    }
};

int main()
{
    try
    {

        Student::displayCount();
        // Creating student objects dynamically
        Student *s1 = new Student();
        s1->displayInfo();

        Student::displayCount();
        // Creating student using parameterized constructor
        Student *s2 = new Student("sumit", 24010012, "SE", "CS", "13/06/2006", "O+", "manchar", 789456123, "DL12345");
        s2->displayInfo();

        Student::displayCount();
        // Copy constructor usage
        Student *s3 = new Student(*s2);
        s3->displayInfo();

        // Database friend class usage
        Database db;
        db.displayStudent(*s1);

        // Dynamic memory deallocation
        cout << "\n";
        delete s1;
        delete s2;
        delete s3;
    }
    catch (exception &e)
    {
        cout << "Exception occurred: " << e.what() << endl;
    }

    return 0;
}