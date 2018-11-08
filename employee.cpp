#include<fstream>
#include<iostream>
#include <string>
#include <climits>
#include <map>
using namespace std;
// class employee 
class Employee
        {
public:
      
 Employee(std::string,std::string,std::string,std::string,std::string,std::string); //constructor
  Employee();  //constructor with default settings
 /* the set methode to set each employee object */
                       void setId(std::string);
                       void setName(string);
                       void   setPosition(string);
                       void   setDepartment(string);
                       void   setBirthday(string);
                       void   setSalary(string);
 /*the get methods to get each employee object */
                       string getId() ;
                       string  getName();
                       string  getPosition();
                       string  getDepartment() ;
                       string  getBirthday () ;
                       string  getSalary () ;
                       static      map<string, Employee> nameMap;
                       static      map<string, Employee> idMap;
 private:
  // initalizing each object as strings
  string  id;
  string  name;
  string  position;
  string  department;
  string  birthday;
  string  salary;
  
  };
  // constructor
 Employee::Employee(std::string empId,std::string empName, std::string empPos, std::string empDep, std::string birth,std::string sal)
{
	  id = empId;
    name = empName;
  position = empPos;
  department = empDep;
  birthday = birth;
  salary  = sal;
} 
/* setting the  string object to be eqaul to the text file object*/
Employee::Employee()
{
  id ="";
	name = "";
	position = "";
	department = "";
	birthday = "";
  salary="";
}
/*the following are the get and set methods for each oject in the employee class*/
string Employee::getId()
{
return id;
}
void Employee::setId(string empId)
{
id = empId;
}

string Employee::getName()
{
return name;
}
void Employee::setName(string empName)
{
name = empName;
}
string Employee::getPosition()
{
return position;
}
void Employee::setPosition(string empPos)
{
position =empPos;
}

string Employee::getDepartment()
{
return department; 
}
void Employee::setDepartment(string empDep)
{
department = empDep;
}
string Employee::getBirthday()
{
return birthday;
}
void Employee::setBirthday(string birth)
{
birthday = birth;
}

string Employee::getSalary()
{
return salary;
}
void Employee::setSalary(string sal)
{
salary = sal;
}
int main(){
//read the file
ifstream ifile("emp.txt");
 ofstream ofs; // creating an object to open the file
 ofs.open ("emp2.txt", ofstream::out | ofstream::app); // opening the file to output 
int Linecounter=0; // counter to count each record

Employee e1;
// while read till end of line
while (!ifile.eof()){ 
Linecounter++;

string id1 ="";
string name1="";
string position1="";
string department1="";
string birthday1="";
string salary1="";

/* the get line function reads each line and uses the delimiter ":" to separate each field*/
getline(ifile ,id1,':');
e1.setId(id1);

getline(ifile ,name1 ,':');
e1.setName(name1);


getline(ifile ,position1,':');
e1.setPosition(position1);

getline(ifile ,department1 ,':');
e1.setDepartment(department1);

getline(ifile ,birthday1 ,':');
e1.setBirthday(birthday1);

ifile >> salary1;
e1.setSalary(salary1);


ifile.ignore(INT_MAX,'\n');//skip to start of next line

/* outputs each field to the emp2.txt*/
ofs<< "\n Record:"<< Linecounter << endl;
ofs << "ID:"<< e1.getId()<< endl;
 ofs << "NAME:"<< e1.getName() << endl;
  ofs << "Position:"<< e1.getPosition() <<endl;
  ofs   << "Department:"<< e1.getDepartment()<<endl;
  ofs   << "BirthDate:"<< e1.getBirthday() <<endl;
  ofs   << "Salary:"<< e1.getSalary() <<endl;
   



}

ifile.close();
return 0;
}
