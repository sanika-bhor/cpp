#include<iostream>
using namespace std;

class Employee
{
    protected:
        string name;
        double basicSalary;
        int workingDays;
        double dailyAllowance;
    public:
        Employee()
        {
            this->name="sanika bhor";
            this->basicSalary=256000;
            this->workingDays=25;
            this->dailyAllowance=2000;
        }

        Employee(string name, double basicSalary, int workingDays, double dailyAllowance)
        {
            this->name=name;
            this->basicSalary=basicSalary;
            this->workingDays=workingDays;
            this->dailyAllowance=dailyAllowance;
        }

        double computePay()
        {
            double package=basicSalary+(workingDays*dailyAllowance);
            return package;
        }

        void display()
        {
            cout<<"\n\nname:"<<this->name;
            cout<<"\nBasic Salary: "<<this->basicSalary;
            cout<<"\nWorking Days: "<<this->workingDays;
            cout<<"\ndaily allowance: "<<this->dailyAllowance;
        }

};

class Manager:public Employee
{
    private:
        double bonus;
    public: 
        Manager()
        {
            this->bonus=100000;
        }
        Manager(string name, double basicSalary, int workingDays, double dailyAllowance, double bonus):Employee(name,basicSalary,workingDays,dailyAllowance)
        {
            this->bonus=bonus;
        }

        double computePay()
        {
            double package=basicSalary+(workingDays*dailyAllowance)+bonus;
            return package;
        }

};
int main()
{
    Employee employee1;
    employee1.display();
    double packageEmployee1=employee1.computePay();
    cout<<"\nPackage: "<<packageEmployee1;

     Employee employee2("sumit bhor",256000,25,2000);
    employee2.display();
    double packageEmployee2=employee2.computePay();
    cout<<"\nPackage: "<<packageEmployee2;

    return 0;
}