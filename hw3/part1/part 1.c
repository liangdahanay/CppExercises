#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
	Complex& operator=(const char* in){
		int size = strlen(in);
		char* tmp = new char[size+1];
		strcpy(tmp, in);
		
		char* token = strtok(tmp, "+i");
		r = atof(token);
		token = strtok(NULL, "+i");
		i = atof(token);
		
		return *this;
	} 
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}