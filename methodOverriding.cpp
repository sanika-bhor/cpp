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
    return 0;
}