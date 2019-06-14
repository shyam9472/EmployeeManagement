#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

int main(void)
{
	  sql::Driver *driver;
// sql::MySQL_Driver *driver;
sql::Connection *con;
//sql::PreparedStatement *stmt;
sql::PreparedStatement  *prep_stmt;

driver = get_driver_instance();
con = driver->connect("tcp://127.0.0.1:3306", "shyam", "root");
con->setSchema("EmployeeManagement");
// stmt = con->prepareStatement("INSERT INTO test(id,label) VALUES(?,?)");
// // stmt->execute("USE EmployeeManagement");
// // stmt->execute("DROP TABLE IF EXISTS test");
// //stmt->execute("CREATE TABLE test(id INT, label CHAR(1))");
// //stmt->execute("INSERT INTO test(id, label) VALUES (1, 'a')");
// stmt->setInt(1,2);
// stmt->setString(2,"b");
// stmt->execute();
// delete stmt;
prep_stmt = con->prepareStatement("INSERT INTO test(id, label ) VALUES (?, ?)");

prep_stmt->setInt(1, 6);
prep_stmt->setString(2, "t");
prep_stmt->execute();
// int a = 2;
// string b = "b";
// prep_stmt -> setInt(1, 4);
// prep_stmt -> setString(2, "d");
// prep_stmt -> execute();

delete prep_stmt;
delete con;

}
