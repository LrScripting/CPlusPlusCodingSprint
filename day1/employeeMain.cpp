#include <stdlib.h>
#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include "employee.hpp"




int main(){

    employee emp(123, "John", "Doe", 5000, true);

    // Use the member functions of the employee class
    int empID = emp.getEmpID();
    std::string firstName = emp.getFirstName();
    std::string lastName = emp.getLastName();
    int salary = emp.getSalary();
    bool hiredStatus = emp.getHiredStatus();

    // Display the employee information
    emp.display(emp);


}
