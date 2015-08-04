#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;
class Student{
private:
	string name;
	unsigned int age;
	string id;
	unsigned int grade;
public:
	Student(string _name, unsigned int _age, string _id, unsigned int _grade)
	:name(_name), age(_age), id(_id), grade(_grade)
	{}
	void output(){
		cout << name << "," << age << "," << id << "," << grade << endl;
	}
};

int main(int argc, char** argv){
	string name;
	unsigned int age;
	string id;
	unsigned int grade1;
	unsigned int grade2;
	unsigned int grade3;
	unsigned int grade4;
	
	string ageStr;
	string grade1Str;
	string grade2Str;
	string grade3Str;
	string grade4Str;
	
	string inputStr;
	cin >> inputStr;
	
	stringstream input(inputStr);
	
	getline(input, name, ',');
	getline(input, ageStr, ',');
	getline(input, id, ',');
	getline(input, grade1Str, ',');
	getline(input, grade2Str, ',');
	getline(input, grade3Str, ',');
	getline(input, grade4Str, ',');
	
	age = atoi(ageStr.c_str());
	grade1 = atoi(grade1Str.c_str());
	grade2 = atoi(grade2Str.c_str());
	grade3 = atoi(grade3Str.c_str());
	grade4 = atoi(grade4Str.c_str());
	
	int grade = (grade1+grade2+grade3+grade4)/4;
	
	
	Student stu(name, age, id, grade);
	stu.output();
	return 0;
}