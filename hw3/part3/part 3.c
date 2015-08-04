#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码

class Array2{
private:
	int** dem1;
	int i;
	int j;
public:
	Array2(int _i, int _j){
		i = _i;
		j = _j;
		dem1 = new int*[i];
		for(int k=0;k<i;k++){
			dem1[k] = new int[j];
		}
		
	}
	
	Array2(){
		
	}
	
	int* operator[](int _i){
		return dem1[_i];
	}
	
	int operator() (int _i, int _j){
		return dem1[_i][_j];
	}
	
	Array2& operator=( Array2& arr2 ){
		i = arr2.i;
		j = arr2.j;
		
		dem1 = new int*[i];
		
		for(int k=0;k<i;k++){
			
			dem1[k] = new int[j];
			
			for(int l = 0; l < j; l++){
				dem1[k][l] = arr2[k][l]; 
			}
			
		}
		return *this;
	}
	
	~Array2(){
		for(int k = 0; k<i; k++){
			delete[] dem1[k];
		}
		delete[] dem1;			
	}
	
};


int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}