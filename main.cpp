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
    cout<<"New employee details have been added Successfully";
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
    cout<<"Your personal email updated Successfully";
  }

  void changeContact(string contact, int emp_id){
      Connection h;
      h.changeContact(contact, emp_id);
      cout<<"Your contacts updated Successfully";
    }

  string selectDept(){
    int choose;
    string dept;
    cout<<endl<<"1. DEVELOPMENT\n2. TESTING\n3. HR\n4. HOUSEKEEPING\n5. IT\n6. SALES"<<endl;
    cin>>choose;
    if(choose == 1){
        dept = "DEVELOPMENT";
    }
    if(choose == 2){
        dept = "TESTING";
    }
    if(choose == 3){
        dept = "HR";
    }
    if(choose == 4){
        dept = "HOUSEKEEPING";
    }
    if(choose == 5){
        dept = "IT";
    }
    if(choose == 6){
        dept = "SALES";
    }
  return dept;
  }

int checkCon(string contact){
  int a = contact.length();
  return a;
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
    cout<<"Generated Id-Password Successfully";
  }

  string checkDept(string emp_uname){
    Connection h;
    string dept;
    dept = h.checkDept(emp_uname);
    return dept;
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
    cout<<"Password Changed Successfully";
  }
};

class ticket_details {
  int TICK_ID;
  int RAISED_BY;
  string ISSUE;
  string DEPT_CONC;
  string STATUS;
  int RESOLVED_BY;

public:
  ticket_details(){}

  ticket_details(int tick_id, int raised_by, string issue,string dept_conc, string status, int resolved_by){
    this->TICK_ID = tick_id;
    this->RAISED_BY = raised_by;
    this->ISSUE = issue;
    this->DEPT_CONC = dept_conc;
    this->STATUS = status;
    this->RESOLVED_BY = resolved_by;
  }
  void toString(){
    cout<<endl<<this->TICK_ID<<"\t"<<this->RAISED_BY<<"\t"<<this->ISSUE<<"\t"<<this->DEPT_CONC<<"\t"<<this->STATUS<<"\t"<<this->RESOLVED_BY;
  }

  void setTickId(int tick_id){
    this->TICK_ID = tick_id;
  }

  int getTickId(){
    return TICK_ID;
  }

  void setRaisedBy(int raised_by){
    this->RAISED_BY = raised_by;
  }

  int getRaisedBy(){
    return RAISED_BY;
  }

  void setIssue(string issue){
    this->ISSUE = issue;
  }

  string getIssure(){
    return ISSUE;
  }

  void raiseTicket(int emp_id, string issue, string dept, string status){
    Connection h;
    h.raiseTicket(emp_id, issue, dept, status);
    cout<<"Ticket Raised Successfully";
  }

  void viewTicket(string dept){
    Connection h;
    sql::ResultSet* res;
    res = h.viewTicket(dept);
    int count = 0;
    cout<<"TICKET ID  RaisedBy    Issue    Department  Status  RESOLVED_BY";
    while(res->next()){
      count = count+1;
    ticket_details t(res->getInt("TICK_ID"),res->getInt("RAISED_BY"),res->getString("ISSUE"),res->getString("DEPT_CONC"),res->getString("STATUS"),res->getInt("RESOLVED_BY"));
    t.toString();
    }
    if(count == 0){
        cout<<endl<<"No tickets for your department currently"<<endl;
     }
  }

  void updateTicket(int tick_id, int emp_id, string status){
    Connection h;
    h.updateTicket(tick_id, emp_id, status);
    cout<<"Ticket Updated Successfully";
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
          string flag = l.checkDept(user);
          if(flag == "HR"){
            //cout<<endl<<"You are in hr section";
            int choose;
            while(true){
              cout<<endl<<"Choose your operations."<<endl;
              cout<<endl<<"0. LOGOUT and Go back to main function."<<endl;
              cout<<"1. Register New employee."<<endl<<"2. Generate username and password for new Employee"<<endl<<"3. Show my details"<<endl<<"4. Change your personal details"<<endl<<"5. Change your password"<<endl<<"6. Raise a ticket"<<endl<<"7. View raised tickets"<<endl<<"8. Update resolved tickets status"<<endl;
              cin>>choose;
              if(choose == 1){
                  employee e;
                  string name;
                  int sal;
                  cout<<"Enter Name (*in all caps) : ";
                  cin.ignore();
                  getline(cin,name);
                  e.setName(name) ;
                  try{
                  cout<<"Enter Salary : ";
                  cin>>sal;
                  if(cin.fail()){
                    throw 10;
                    }
                  }
                  catch(int e)
                  {
                      cout<<endl<<"Please enter in number format only"<<endl<<"Please try again";
                  }
                  e.setSal(sal);
                  string dept;
                  cout<<"Enter department : ";
                  // cin>>dept;
                  dept = e.selectDept();
                  e.setDept(dept);
                  string email;
                  cout<<"Enter email : ";
                  cin>>email;
                  e.setEmail(email);
                  string contact;
                  cout<<"Enter contact : ";
                  cin>>contact;
                  if(e.checkCon(contact) == 10){
                  e.setContact(contact);
                  e.insert(e);
                  }
                  else{
                    cout<<"The entered number should have 10 digits no more no less.";
                  }


                  // catch(char ch)
                  // {
                  //     cout<<"\nCharacter exception caught.";
                  // }
                  // catch(double d)
                  // {
                  //     cout<<"\nDouble exception caught.";
                  // }
                  // cout<<name<<"\t"<<sal<<"\t"<<dept<<"\t"<<email<<"\t"<<contact<<endl;

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
                cout<<endl<<"Press\n1. Change personal email id\n2. Change mobile number"<<endl;
                cin>>id;
                if(id == 1){
                  string email;
                  cout<<"Enter new email id";
                  cin>>email;
                  e.changeEmail(email,l.checkId(user));
                }
                if(id == 2){
                  conagain:
                  string contact;
                  cout<<"Enter your new phone number : "<<endl;
                  cin>>contact;
                  if(e.checkCon(contact) == 10){
                  e.setContact(contact);
                  e.changeContact(contact,l.checkId(user));
                  }
                  else{
                    cout<<"The entered number should have 10 digits no more no less."<<endl;
                    goto conagain;
                  }

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
                ticket_details t;
                employee e;
                int emp_id = l.checkId(user);
                string issue,dept,status;
                cout<<"Enter your Issue here : "<<endl;
                cin.ignore();
                getline(cin, issue);
                cout<<"Select the department Concerned : ";
                // cin>>dept;
                dept = e.selectDept();
                status = "PENDING";
                if(dept == "HR" ){
                t.raiseTicket(emp_id, issue, dept, status );
              }
              else{
                cout<<"Please select either from HR/IT/HOUSEKEEPING";
              }
              }
              if(choose == 7 ){
                ticket_details t;
                cout<<endl;
                t.viewTicket(l.checkDept(user));
              }
              if(choose == 8 ){
                ticket_details t;
                int tick_id,emp_id;
                string status;
                cout<<"Enter the ticket number : ";
                cin>>tick_id;
                cout<<"Enter the new status : ";
                cin>>status;
                cout<<"Enter your employee id : ";
                cin>>emp_id;
                t.updateTicket(tick_id,emp_id,status);
              }
              if(choose == 0){
                break;
              }
            }
          } else{
            //cout<<endl<<"You are in non hr section";
            while(true){
              int choose;
              cout<<endl<<"Choose your operations."<<endl;
              cout<<endl<<"0. LOGOUT and Go back to main function."<<endl;
              cout<<"1. Show My Details."<<endl<<"2. Change personal Details"<<endl<<"3. Change your password"<<endl<<"4. Raise Ticket"<<endl;
              if(l.checkDept(user) == "IT" || l.checkDept(user)=="HOUSEKEEPING"){
                cout<<"5. View tickets."<<endl<<"6. Update Resolved ticket status :"<<endl;
              }
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
                cout<<endl<<"Press\n1. Change personal email id\n2. Change mobile number"<<endl;
                cin>>id;
                if(id == 1){
                  string email;
                  cout<<"Enter new email id";
                  cin>>email;
                  e.changeEmail(email,l.checkId(user));
                }
                if(id == 2){
                  conagain1:
                  string contact;
                  cout<<endl<<"Enter your new phone number : "<<endl;
                  cin>>contact;
                  if(e.checkCon(contact) == 10){
                  e.setContact(contact);
                  e.changeContact(contact,l.checkId(user));
                  }
                  else{
                    cout<<"The entered number should have 10 digits no more no less."<<endl;
                    goto conagain1;
                  }
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
                ticket_details t;
                int emp_id = l.checkId(user);
                string issue,dept,status;
                cout<<"Enter your Issue here : "<<endl;
                cin.ignore();
                getline(cin, issue);
                cout<<"Enter the department Concerned : ";
                cin>>dept;
                status = "PENDING";
                t.raiseTicket(emp_id, issue, dept, status );
              }
              if(l.checkDept(user) == "IT" || l.checkDept(user)=="HOUSEKEEPING"){
                if(choose == 5){
                  ticket_details t;
                  t.viewTicket(l.checkDept(user));
                }
                if(choose == 6){
                  ticket_details t;
                  int tick_id,emp_id;
                  string status;
                  cout<<"Enter the ticket number : ";
                  cin>>tick_id;
                  cout<<"Enter the new status : ";
                  cin>>status;
                  cout<<"Enter your employee id : ";
                  cin>>emp_id;
                  t.updateTicket(tick_id,emp_id,status);
                }
              }
              if(choose == 0){
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
