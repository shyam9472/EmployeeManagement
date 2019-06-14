#include <stdlib.h>
#include <iostream>
// #include <string>
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <string>
using namespace std;
class Connection {
  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res;
  sql::PreparedStatement  *prep_stmt;
public:
      Connection();
      string passCheck(string emp_uname);
      sql::ResultSet* sayHello();
      sql::ResultSet* showMyDetails(int emp_id);
      sql::ResultSet* initialiseLogin(string emp_uname);
      string checkDept(string user);
      void addEmployee(string emp_name, int emp_sal, string emp_dept, string emp_email, string emp_contact);
      void GenerateId(string emp_uname, string password, int emp_id);
      int checkId(string emp_uname);
      void changeEmail(string email, int emp_id);
      void changeContact(string contact, int emp_id);
      void changePass(string emp_uname,string pass);
      void raiseTicket(int emp_id, string issue, string dept,string status);
      sql::ResultSet* viewTicket(string dept);
      void updateTicket(int tick_id, int emp_id, string status);

};
