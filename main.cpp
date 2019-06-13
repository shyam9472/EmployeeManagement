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
    this->EMP_CONTACT = contact;
  }

  string getContact(){
    return EMP_CONTACT;
  }

  void toString(){
    cout<<endl<<this->EMP_ID<<"\t"<<this->EMP_NAME<<"\t"<<this->EMP_SAL<<"\t"<<this->EMP_DEPT<<"\t"<<this->EMP_EMAIL<<"\t"<<this->EMP_CONTACT<<endl;
  }

  void insert(employee e){
    Connection h;
    h.addEmployee(e.getName(),e.getSal(),e.getDept(),e.getEmail(),e.getContact());
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

  void changeEmail(string email, int emp_id){
    Connection h;
    h.changeEmail(email, emp_id);
  }

  void changeContact(string contact, int emp_id){
      Connection h;
      h.changeContact(contact, emp_id);
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

  login initialiseLogin(string emp_uname){
    Connection h;
    login l1;
    sql::ResultSet* res;
    res = h.initialiseLogin(emp_uname);
    while(res->next()){
      login l1(res->getInt("EMP_ID"),res->getString("EMP_UNAME"),res->getString("PASSWORD"));

    }
    return l1;
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

  void insert(login l){
    Connection h;
    h.GenerateId(l.getEmpuname(), l.getPass(), l.getId());
  }

  int checkDept(string emp_uname){
    Connection h;
    int flag = 0;
    string dept;
    dept = h.checkDept(emp_uname);
    if(dept=="HR"){
      flag = 1;
    }
    return flag;
  }

  int checkId(string emp_uname){
    Connection h;
    int id;
    id = h.checkId(emp_uname);
    return id;
  }

  void changePass(string emp_uname, string pass){
    Connection h;
    h.changePass(emp_uname, pass);
  }
};


int main(){
  sql::ResultSet* res;
  Connection h;
  login l;
  employee e;
  string user,pass;
  cout<<endl<<"Welcome to EMPLOYEE MANAGEMENT System"<<endl;

  while(true){
    int a;
    cout<<endl<<"Please Enter your choice press : "<<endl<<"1. Login"<<endl<<"2. Exit"<<endl;
    cin>>a;
    if(a == 1){
      cout<<endl<<"Please login to proceed."<<endl;
      cout<<endl<<"Enter your Username : ";
      cin>>user;
      l.initialiseLogin(user);
      cout<<endl<<"Please enter your password now : ";
      cin>>pass;
      if(pass == l.passCheck(user)){
          cout<<endl<<"You have Successfully logged-in";
          int flag = l.checkDept(user);
          if(flag == 1){
            //cout<<endl<<"You are in hr section";
            int choose;
            while(true){
              cout<<endl<<"Choose your operations."<<endl<<"1. Register New employee."<<endl<<"2. Generate username and password for new Employee"<<endl<<"3. Show my details"<<endl<<"4. Change your personal details"<<endl<<"5. Change your password"<<endl<<"6. Go back to main function.";
              cin>>choose;
              if(choose == 1){
                  employee e;
                  string name;
                  int sal;
                  cout<<"Enter Name : ";
                  cin.ignore();
                  getline(cin,name);
                  e.setName(name) ;
                  cout<<"Enter Salary : ";
                  cin>>sal;
                  e.setSal(sal);
                  string dept;
                  cout<<"Enter department : ";
                  cin>>dept;
                  e.setDept(dept);
                  string email;
                  cout<<"Enter email : ";
                  cin>>email;
                  e.setEmail(email);
                  string contact;
                  cout<<"Enter contact : ";
                  cin>>contact;
                  e.setContact(contact);
                  // cout<<name<<"\t"<<sal<<"\t"<<dept<<"\t"<<email<<"\t"<<contact<<endl;
                  e.insert(e);

              }
              if(choose == 2){
                login l;
                string emp_uname,password;
                int emp_id;
                cout<<"Enter the employee Id : ";
                cin>>emp_id;
                l.setId(emp_id);
                cout<<"Enter the user name : ";
                cin>>emp_uname;
                l.setEmpuname(emp_uname);
                cout<<"Enter the Password : ";
                cin>>password;
                l.setPass(password);
                l.insert(l);
              }
              if(choose == 3){
                employee e;
                int emp_id;
                cout<<endl<<"Enter your Employee id";
                cin>>emp_id;
                if(emp_id == l.checkId(user)){
                  cout<<endl<<"EMPLOYEE ID\tNAME\tSALARY\tDEPARTMENT\tEMAIL\tCONTACT";
                  e.showMyDetails(emp_id);
                }
                else{
                  cout<<"Please enter your own Employee ID";
                }
              }
              if(choose == 4){
                int id;
                cout<<"Press\n1. Change personal email id\n2. Change mobile number";
                cin>>id;
                if(id == 1){
                  string email;
                  cout<<"Enter new email id";
                  cin>>email;
                  e.changeEmail(email,l.checkId(user));
                }
                if(id == 2){
                  string contact;
                  cout<<"Enter your new phone number.";
                  cin>>contact;
                  e.changeContact(contact,l.checkId(user));
                }
              }
              if(choose == 5){
                string password;
                cout<<"Enter your password";
                cin>>password;
                if(password == l.passCheck(user)){
                  string pass;
                  cout<<"Enter new PASSWORD";
                  cin>>pass;
                  l.changePass(user,pass);
                }
                else{
                  cout<<"Incorrect Password. Please try again.";
                }

              }
              if(choose == 6){
                break;
              }
            }
          } else{
            //cout<<endl<<"You are in non hr section";
            while(true){
              int choose;
              cout<<endl<<"Choose your operations."<<endl<<"1. Show My Details."<<endl<<"2. Change personal Details"<<endl<<"3. Change your password"<<endl<<"4. Go back to main function.";
              cin>>choose;
              if(choose == 1){
                employee e;
                int emp_id;
                cout<<endl<<"Enter your Employee id";
                cin>>emp_id;
                if(emp_id == l.checkId(user)){
                  cout<<endl<<"EMPLOYEE ID\tNAME\tSALARY\tDEPARTMENT\tEMAIL\tCONTACT";
                  e.showMyDetails(emp_id);
                }
                else{
                  cout<<"Please enter your own Employee ID";
                }
              }
              if(choose == 2){
                int id;
                cout<<"Press\n1. Change personal email id\n2. Change mobile number";
                cin>>id;
                if(id == 1){
                  string email;
                  cout<<"Enter new email id";
                  cin>>email;
                  e.changeEmail(email,l.checkId(user));
                }
                if(id == 2){
                  string contact;
                  cout<<"Enter your new phone number.";
                  cin>>contact;
                  e.changeContact(contact,l.checkId(user));
                }
              }
              if(choose == 3){
                string password;
                cout<<"Enter your password";
                cin>>password;
                if(password == l.passCheck(user)){
                  string pass;
                  cout<<"Enter new PASSWORD";
                  cin>>pass;
                  l.changePass(user,pass);
                }
                else{
                  cout<<"Incorrect Password. Please try again.";
                }

              }
              if(choose == 4){
                break;
              }
            }
          }


        } else{
          cout<<"Either username or password is incorrect"<<endl<<"Please check your user name or password to login again.";
        }
      }
      if(a == 2){
          break;
      }
}
  return 0;
}
