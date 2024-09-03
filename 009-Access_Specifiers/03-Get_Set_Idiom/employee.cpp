#include <iostream>
#include <string>

class Employee 
{
    private:
    std::string name;
    std::string address;
    double salary_fixed;
    double salary_variable;

    public:
    Employee(void)
    {
        salary_fixed = 1200;
        salary_variable = 10;
    }

    std::string getName(void)
    {
        return(name);
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    void setAddress(std::string address)
    {
        this->address = address;
    }

    std::string getAddress(void)
    {
        return(address);
    }

    double getSalarayFixed(void)
    {
        return(salary_fixed);
    }

    double salary(void)
    {
        return(salary_fixed + salary_variable);
    }
};

int main(void)
{
    Employee employee;
    employee.setName("Hemant");
    employee.setAddress("Pune");

    std::cout << employee.getName() << std::endl;
    std::cout << employee.getSalarayFixed() << std::endl;
    std::cout << employee.salary() << std::endl;
    
}