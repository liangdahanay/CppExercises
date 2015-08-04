#include <iostream>
using namespace std;
class A {
public:
    int val;
	A(int n = 0){ val = n; }
    A& GetObj() {
        return *this;
    }
};
main()  {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
}