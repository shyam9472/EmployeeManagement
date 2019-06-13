// #include <stdlib.h>
// #include <iostream>

// #include "mysql_connection.h"
#include "Connection.hpp"
#include<string>
// #include <cppconn/driver.h>
// #include <cppconn/exception.h>
// #include <cppconn/resultset.h>
// #include <cppconn/statement.h>
// #include <cppconn/prepared_statement.h>

using namespace std;

Connection::Connection(){
   try {
     /* Create a connection */
     driver = get_driver_instance();
     con = driver->connect("tcp://127.0.0.1:3306", "shyam", "root");
     /* Connect to the MySQL test database */
     con->setSchema("EmployeeManagement");


     } catch (sql::SQLException &e) {
       cout << "# ERR: SQLException in " << __FILE__;
       cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
       cout << "# ERR: " << e.what();
       cout << " (MySQL error code: " << e.getErrorCode();
       cout << ", SQLState: " << e.getSQLState() << " )" << endl;
     }
}
sql::ResultSet* Connection::sayHello(){
  stmt = con->createStatement();
  res = stmt->executeQuery("SELECT * FROM employee;");

  // while (res->next()) {
  //   cout << res->getInt("EMP_ID")<<"\t"<<res->getString("EMP_NAME")<<"\t"<< endl;
  //
  // }
  return res;
}

sql::ResultSet* Connection::showMyDetails(int emp_id){
  prep_stmt = con->prepareStatement("SELECT * FROM employee WHERE EMP_ID = (?);");
  prep_stmt->setInt(1,emp_id);
  res = prep_stmt->executeQuery();
  return res;
}

string Connection::passCheck(string emp_uname){
  prep_stmt = con->prepareStatement("SELECT PASSWORD FROM login WHERE EMP_UNAME =(?) ; ");
  prep_stmt->setString(1,emp_uname);
  res = prep_stmt->executeQuery();
  string re;
  while(res->next()){
    re = res->getString("PASSWORD");
  }
  return re;
}

sql::ResultSet* Connection::initialiseLogin(string emp_uname){
  prep_stmt = con->prepareStatement("SELECT * FROM login WHERE EMP_UNAME = (?);");
  prep_stmt->setString(1,emp_uname);
  res = prep_stmt->executeQuery();
  return res;
}

string Connection::checkDept(string emp_uname){
  string dept;
  prep_stmt = con->prepareStatement("SELECT e.EMP_DEPT FROM employee e inner join login l on e.EMP_ID = l.EMP_ID WHERE l.EMP_UNAME = (?);");
  prep_stmt->setString(1,emp_uname);
  res = prep_stmt->executeQuery();
  while(res->next()){
    dept = res->getString("EMP_DEPT");
  }
  return dept;
}

void Connection::addEmployee(string emp_name, int emp_sal, string emp_dept, string emp_email, string emp_contact){
  prep_stmt = con->prepareStatement("INSERT INTO employee(EMP_NAME, EMP_SAL, EMP_DEPT, EMP_EMAIL, EMP_CONTACT) VALUES(?,?,?,?,?);");
  prep_stmt->setString(1, emp_name);
  prep_stmt->setInt(2, emp_sal);
  prep_stmt->setString(3, emp_dept);
  prep_stmt->setString(4, emp_email);
  prep_stmt->setString(5, emp_contact);
  prep_stmt->executeUpdate();
}

void Connection::GenerateId(string emp_uname, string password, int emp_id){
  prep_stmt = con->prepareStatement("INSERT INTO login(EMP_UNAME, PASSWORD, EMP_ID) VALUES(?,?,?);");
  prep_stmt->setString(1, emp_uname);
  prep_stmt->setString(2, password);
  prep_stmt->setInt(3, emp_id);
  prep_stmt->executeUpdate();
}

int Connection::checkId(string emp_uname){
  int id;
  prep_stmt = con->prepareStatement("SELECT EMP_ID FROM login WHERE EMP_UNAME = (?);");
  prep_stmt->setString(1,emp_uname);
  res = prep_stmt->executeQuery();
  while(res->next()){
    id = res->getInt("EMP_ID");
  }
  return id;
}

void Connection::changeEmail(string email, int emp_id){
  prep_stmt = con->prepareStatement("UPDATE employee SET EMP_EMAIL = (?) WHERE EMP_ID = (?);");
  prep_stmt->setString(1,email);
  prep_stmt->setInt(2, emp_id);
  prep_stmt->executeUpdate();
}

void Connection::changeContact(string contact, int emp_id){
  prep_stmt = con->prepareStatement("UPDATE employee SET EMP_CONTACT = (?) WHERE EMP_ID = (?);");
  prep_stmt->setString(1,contact);
  prep_stmt->setInt(2, emp_id);
  prep_stmt->executeUpdate();
}

void Connection::changePass(string emp_uname,string pass){
  prep_stmt = con->prepareStatement("UPDATE login SET PASSWORD = (?) WHERE EMP_UNAME = (?);");
  prep_stmt->setString(1,pass);
  prep_stmt->setString(2,emp_uname);
  prep_stmt->executeUpdate();
}
