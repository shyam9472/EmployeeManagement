#include<iostream>
#include "Connection.hpp"
#include "mysql_connection.h"
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
// #include "employee.hpp"
using namespace std;
class employee{
  int EMP_ID;
  string EMP_NAME;
  int EMP_SAL;
  string EMP_DEPT;
  string EMP_EMAIL;
  string EMP_CONTACT;
public:
  employee(){}
  employee(int id, string name, int sal, string dept, string email, string contact){
    this->EMP_ID = id;
    this->EMP_NAME = name;
    this->EMP_SAL = sal;
    this->EMP_DEPT = dept;
    this->EMP_EMAIL = email;
    this->EMP_CONTACT = contact;
  }
  void setId(int emp_id){
  this->EMP_ID = emp_id;
  }

  int getId(){
    return EMP_ID;
  }

  void setName(string name) {
    this->EMP_NAME = name;
  }

  string getName(){
    return EMP_NAME;
  }

  void setSal(int sal){
    this->EMP_SAL = sal;
  }

  int getSal(){
    return EMP_SAL;
  }

  void setDept(string dept){
    this->EMP_DEPT = dept;
  }

  string getDept(){
    return EMP_DEPT;
  }

  void setEmail(string email){
    this->EMP_EMAIL = email;
  }

  string getEmail(){
    return EMP_EMAIL;
  }

  void setContact(string contact){
    this->EMP_CONTACT;
  }

  string getContact(){
    return EMP_CONTACT;
  }

  void toString(){
    cout<<endl<<this->EMP_ID<<"\t"<<this->EMP_NAME<<"\t"<<this->EMP_SAL<<"\t"<<this->EMP_DEPT<<"\t"<<this->EMP_EMAIL<<"\t"<<this->EMP_CONTACT<<endl;
  }

  void showMyDetails(int emp_id){
    Connection h;
    sql::ResultSet* res;
    res = h.showMyDetails(emp_id);
    while(res->next()){
    employee e1(res->getInt("EMP_ID"),res->getString("EMP_NAME"),res->getInt("EMP_SAL"),res->getString("EMP_DEPT"),res->getString("EMP_EMAIL"),res->getString("EMP_CONTACT"));
    e1.toString();
  }
  }


};

class login{
  int EMP_ID;
  string EMP_UNAME;
  string PASSWORD;

public:
  login(){}

  login(int emp_id, string emp_uname, string password){
    this->EMP_ID = emp_id;
    this->EMP_UNAME = emp_uname;
    this->PASSWORD = password;
  }

  void setId(int emp_id){
    this->EMP_ID = emp_id;
  }

  int getId(){
    return EMP_ID;
  }

  void setEmpuname(string empuname){
    this->EMP_UNAME = empuname;
  }

  string getEmpuname(){
    return EMP_UNAME;
  }

  void setPass(string pass){
    this->PASSWORD = pass;
  }

  string getPass() {
    return PASSWORD;
  }

  string passCheck(string emp_uname){
    Connection h;
    string pass;
    pass = h.passCheck(emp_uname);
    return pass;
  }
};

int main(){
  sql::ResultSet* res;
  Connection h;
  // employee e1;

  //cout<<endl<<"Now trying to use the intialised res in different function"<<endl;
  res = h.sayHello();

  //e1.setId(res->getInt("EMP_ID"));
  int b;
   while (res->next()) {
    //cout << res->getInt("EMP_ID")<<"\t"<<res->getString("EMP_NAME")<<"\t"<< endl;
    // e1.setId(res->getInt("EMP_ID"));
    employee e1(res->getInt("EMP_ID"),res->getString("EMP_NAME"),res->getInt("EMP_SAL"),res->getString("EMP_DEPT"),res->getString("EMP_EMAIL"),res->getString("EMP_CONTACT"));
    e1.toString();
    b=e1.getId();
  }
  cout<<endl<<b<<endl;

  int emp_id;
  cout<<"Enter your EMPLOYEE CODE";
  cin>>emp_id;
  employee e;
  e.showMyDetails(emp_id);

  string emp_uname;
  login l;
  string pass;
  cout<<"Enter your username please";
  cin>>emp_uname;
  cout<<"Enter your password";
  cin>>pass;
  if(pass == l.passCheck(emp_uname)){
      cout<<"Login Successful";
  }
  else{
    cout<<"Login failed please check your username and password.";
  }


  return 0;
}
