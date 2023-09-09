#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class employee {
public:
    // Constructor
    employee(int id, std::string fname, std::string lname, int salary, bool hired);

    // Getters
    const int getEmpID() const;
    const std::string getFirstName() const;
    const std::string getLastName() const;
    const int getSalary() const;
    const bool getHiredStatus() const;

    // Setters
    void setId(int& newID);
    void setFirstName(std::string& newFirstName);
    void setLastName(std::string& newLastName);
    void setSalary(int& newSalary);
    void setHiredStatus(bool& hiredStatus);

    // Display function
    void display(employee& e);

private:
    int id;
    std::string fname;
    std::string lname;
    int salary;
    bool hired;
};
