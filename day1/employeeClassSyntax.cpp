#include <stdlib.h>
#include <iostream>
#include "employee.hpp"



employee::employee(int id, std::string fname, std::string lname, int salary, bool hired) 
  : id(id), fname(fname), lname(lname), salary(salary), hired(hired) {
}

const int employee::getEmpID() const {
  return id;
}

const std::string employee::getFirstName() const {
  return fname;
}

const std::string employee::getLastName() const {
  return lname;
}

const int employee::getSalary() const {
  return salary;
}

const bool employee::getHiredStatus() const {
  return hired;
}

void employee::setId(int& newID) {
  id = newID;
}

void employee::setFirstName(std::string& newFirstName) {
  fname = newFirstName;
}

void employee::setLastName(std::string& newLastName) {
  lname = newLastName;
}

void employee::setSalary(int& newSalary) {
  salary = newSalary;
}

void employee::setHiredStatus(bool& hiredStatus) {
  hired = hiredStatus;
}

void employee::display(employee& e) {
  using std::cout;
  using std::string;

  cout << "Employee ID: " << e.getEmpID() << '\n';
  cout << "Employee name: " << e.getFirstName() << " " << e.getLastName() << '\n';
  cout << "Employee salary: " << e.getSalary() << '\n';
  cout << "Employee hired Status: " << (e.getHiredStatus() ? "Hired" : "Not Hired") << '\n';
}
