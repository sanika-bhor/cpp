/* 
write a c++ program to implement method overring have class name as 'employee' and 'manager' 
perform calculation of total package by overrideing computePay() function 
-------------------------------------------------------------------
*/
#include<iostream>
using namespace std;

class Date
{
    public:
        int day;
        int month;
        int year;
    public:
        // Date(int d, int m,int y):day(d),month(m),year(y){}
        Date()
        {
            day = 0;
            month = 0;
            year = 0;
        }
        Date(int d, int m, int y)
        {
            this->day=d;
            this->month=m;
            this->year=y;
        }
};
class Employee
{
    protected:
        string name;
        double basicSalary;
        int workingDays;
        double dailyAllowance;
        Date joinDate;
        
    public:
        Employee()
        {
            this->name="sanika bhor";
            this->basicSalary=256000;
            this->workingDays=25;
            this->dailyAllowance=2000;
            Date date(7,11,2024);
            this->joinDate=date;
        }

        Employee(string name, double basicSalary, int workingDays, double dailyAllowance, Date joinDate)
        {
            this->name=name;
            this->basicSalary=basicSalary;
            this->workingDays=workingDays;
            this->dailyAllowance=dailyAllowance;
            this->joinDate=joinDate;
        }

        virtual double computePay()
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
            cout<<"\nJoin Date: "<<joinDate.day<<"/"<<joinDate.month<<"/"<<joinDate.year;
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
        Manager(string name, double basicSalary, int workingDays, double dailyAllowance, Date joinDate, double bonus) : Employee(name, basicSalary, workingDays, dailyAllowance, joinDate)
        {
            this->bonus=bonus;
        }

        double computePay() override
        {
            double package=basicSalary+(workingDays*dailyAllowance)+bonus;
            return package;
        }

};


class director:public Employee
{
    private:
        int shareholding;
        int earningPerShare;
    public:
        director()
        {
            shareholding=10;
            earningPerShare=2000;
        }
        director(string name, double basicSalary, int workingDays, double dailyAllowance, Date joinDate, int shareholding, int earningPerShare) : Employee(name, basicSalary, workingDays, dailyAllowance,joinDate)
        {
            this->shareholding=shareholding;
            this->earningPerShare=earningPerShare;
        }
        double computePay() override
        {
            double package = basicSalary + (workingDays * dailyAllowance) + (shareholding * (earningPerShare));
            return package;
        }
};

class ceo : public Employee
{
private:
    double monthlyIncentive;

public:
    ceo()
    {
        monthlyIncentive = 5000;
    }
    ceo(string name, double basicSalary, int workingDays, double dailyAllowance, Date joinDate, double monthlyIncentive) : Employee(name, basicSalary, workingDays, dailyAllowance,joinDate)
    {
        this->monthlyIncentive = monthlyIncentive;
    }
    double computePay() override
    {
        double package = basicSalary + (workingDays * dailyAllowance) + monthlyIncentive;
        return package;
    }
};
int main()
{
    Date date(8,11,2024);
    cout<<"\n\n Employee 1";
    Employee employee1;
    employee1.display();
    double packageEmployee1=employee1.computePay();
    cout<<"\nPackage: "<<packageEmployee1;

    cout<<"\n\n Employee 2";
     Employee employee2("sumit bhor",256000,25,2000,date);
    employee2.display();
    double packageEmployee2=employee2.computePay();
    cout<<"\nPackage: "<<packageEmployee2;

    cout<<"\n\n manager 1";
    Manager manager1;
    manager1.display();
    double packageManager1=manager1.computePay();
    cout<<"\nPackage: "<<packageManager1;


    cout<<"\n\n manager 2";
    Manager manager2("sumit bhor",256000,25,2000,date,120000);
    manager2.display();
    double packageManager2=manager2.computePay();
    cout<<"\nPackage: "<<packageManager2;


// in this case when we do not use virtual function for overriding then it call the computePay() function of employee class
// but by using virtual it override the base class function add call the function of manager class 
    cout<<"\n\n manager 3";
    Employee *ptrEmp=new Manager("rishika narawade",25000,25,2000,date,12000);
    ptrEmp->display();
    double packageEmployee3=ptrEmp->computePay();
    cout<<"\nPackage: "<<packageEmployee3;

    cout << "\n\n director";
    Employee *ptrEmpDirector = new director("rishika narawade", 25000, 25, 2000,date, 20,5000);
    ptrEmpDirector->display();
    double packageEmployee4 = ptrEmpDirector->computePay();
    cout << "\nPackage: " << packageEmployee4;

    cout << "\n\n CEO";
    Employee *ptrEmpCEO = new ceo("rishika narawade", 25000, 25, 2000, date,200000);
    ptrEmpCEO->display();
    double packageEmployee5 = ptrEmpCEO->computePay();
    cout << "\nPackage: " << packageEmployee5;

    return 0;
}