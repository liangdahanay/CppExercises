#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
class BigInteger{
private:

	char* num;
	int size;

	void static addHelper(char* addedNum, int length1, char* addingNum, int length2);
	void static subtractHelper(char* subtractedNum, int length1, char* subtracting, int length2);
	//void static appendZero(char* originalNum, int length1, int lengthZero);
	int static Compare(char* num1, char* num2, int length);
public:

	BigInteger(const char* _num){
		int _size = strlen(_num);
		int count = 0;
		for (int i = 0; i<_size; i++){
			if (_num[i] == '0') count++;
			else break;
		}
		size = _size - count;
		if (size == 0){
			size = 1;
			num = new char[2];
			num[0] = '0';
			num[1] = '\0';
		}
		else{
			num = new char[size + 1];
			strcpy(num, _num + count);
		}
		//delete[] _num;//only once
	}

	BigInteger(const BigInteger& i2){
		size = i2.size;
		num = new char[size + 1];
		strcpy(num, i2.num);
	}
	BigInteger(){
		size = 0;
		num = NULL;
	}

	~BigInteger(){
		if (num) delete[] num;
	}

	void Print() const{
		cout << num << endl;
	}

	BigInteger& operator=(const BigInteger& i2){
		if (num == i2.num) return *this;

		size = i2.size;
		if (num) delete[] num;
		num = new char[size + 1];
		strcpy(num, i2.num);
		return *this;
	}

	friend BigInteger operator+(const BigInteger& i1, const BigInteger& i2);
	friend BigInteger operator-(const BigInteger& i1, const BigInteger& i2);
	friend BigInteger operator*(const BigInteger& i1, const BigInteger& i2);
	friend BigInteger operator/(const BigInteger& i1, const BigInteger& i2);
	//friend BigInteger& operator*(BigInteger& i1, int x);

	int Compare(const BigInteger& i2) const{
		if (size < i2.size) return -1;
		if (size > i2.size) return 1;
		for (int i = 0; i<size; i++){
			if (num[i] > i2.num[i]) return 1;
			if (num[i] < i2.num[i]) return -1;
		}
		return 0;
	}


};
//assume same size
int BigInteger::Compare(char* num1, char* num2, int length){
	for (int i = 0; i<length; i++){
		if (num1[i] > num2[i]) return 1;
		if (num1[i] < num2[i]) return -1;
	}
	return 0;
}

void BigInteger::subtractHelper(char* subtractedNum, int longSize, char* subtractingNum, int shortSize){
	int diff = longSize - shortSize;
	char carry = 0;
	for (int i = shortSize - 1; i >= 0; i--){
		char longDigit = subtractedNum[i + diff] - '0';
		char shortDigit = subtractingNum[i] - '0';
		char tmpDigit = longDigit - shortDigit - carry;
		if (tmpDigit<0){
			carry = 1;
			tmpDigit = tmpDigit + 10;
		}
		else{
			carry = 0;
		}
		subtractedNum[i + diff] = tmpDigit + '0';
	}
	//1934 - 193000
	for (int i = diff - 1; i >= 0; i--){
		char longDigit = subtractedNum[i] - '0';
		char tmpDigit = longDigit - carry;
		if (tmpDigit<0){
			carry = 1;
			tmpDigit = tmpDigit + 10;
		}
		else{
			carry = 0;
		}
		subtractedNum[i] = tmpDigit + '0';
	}
}

BigInteger operator-(const BigInteger& i1, const BigInteger& i2){
	if (i1.Compare(i2) < 0){
		BigInteger	tmpInt = i2 - i1;
		char* tmpNum = new char[tmpInt.size + 2];
		strcpy(tmpNum + 1, tmpInt.num);
		tmpNum[0] = '-';
		return BigInteger(tmpNum);
	}
	//i1>=i2
	char* tmpNum = new char[i1.size + 1];
	strcpy(tmpNum, i1.num);
	BigInteger::subtractHelper(tmpNum, i1.size, i2.num, i2.size);

	BigInteger res(tmpNum);
	delete[] tmpNum;
	return res;
}

void BigInteger::addHelper(char* addedNum, int longSize, char* addingNum, int shortSize){
	int diff = longSize - shortSize;
	char carry = 0;
	for (int i = shortSize - 1; i >= 0; i--){
		char longDigit = addedNum[i + diff] - '0';
		char shortDigit = addingNum[i] - '0';
		addedNum[i + diff] = (longDigit + shortDigit + carry) % 10 + '0';
		carry = (longDigit + shortDigit + carry) / 10;
	}

	for (int i = diff - 1; i > 0; i--){
		char longDigit = addedNum[i] - '0';
		addedNum[i] = (longDigit + carry) % 10 + '0';
		carry = (longDigit + carry) / 10;
	}
	addedNum[0] = carry + '0';
}
BigInteger operator+(const BigInteger& i1, const BigInteger& i2){
	if (i1.size < i2.size){
		return i2 + i1;
	}
	char* addedNum = new char[i1.size + 2];
	strcpy(addedNum + 1, i1.num);
	BigInteger::addHelper(addedNum, i1.size + 1, i2.num, i2.size);

	BigInteger res(addedNum);
	delete[] addedNum;
	return res;
}



BigInteger operator*(const BigInteger& i1, const BigInteger& i2){

	char* tmpNum = new char[i1.size + i2.size + 1];
	memset(tmpNum, '0', i1.size + i2.size);
	tmpNum[i1.size + i2.size] = '\0';

	for (int i = 0; i < i2.size; i++){
		char i2Digit = i2.num[i2.size - 1 - i] - '0';
		char carry = 0;
		for (int j = 0; j < i1.size; j++){
			char i1Digit = i1.num[i1.size - 1 - j] - '0';

			char tmp = (tmpNum[i1.size + i2.size - 1 - i - j] - '0' + carry + i2Digit*i1Digit) % 10;
			carry = (tmpNum[i1.size + i2.size - 1 - i - j] - '0' + carry + i2Digit*i1Digit) / 10;
			tmpNum[i1.size + i2.size - 1 - i - j] = tmp + '0';
			//cout << tmpNum[ i1.size + i2.size - 1 - i - j ]<< endl;
		}
		char tmp = (tmpNum[i2.size - 1 - i] - '0' + carry) % 10;
		//carry = (tmpNum[ i2.size - 1 - i ] - '0' + carry)/10;
		tmpNum[i2.size - 1 - i] = tmp + '0';
	}
	BigInteger res(tmpNum);
	delete[] tmpNum;
	return res;

	return BigInteger("1");
}



// i1 / i2
BigInteger operator/(const BigInteger& i1, const BigInteger& i2){

	BigInteger zero("0");
	if (i1.Compare(zero) == 0) {
		cerr << "Invalid Operand Zero!" << endl;
		exit(1);
	}
	if (i1.Compare(i2) < 0) return BigInteger("0");
	if (i1.Compare(i2) == 0) return BigInteger("1");
	if (i2.Compare(BigInteger("1")) == 0) return i1;

	int diff = i1.size - i2.size;

	//buffer for i1 mod
	char* i1Num = new char[i1.size + 1];
	strcpy(i1Num, i1.num);

	//buffer for base * i2
	char* i2NumBuffer = new char[i1.size + 1];
	memset(i2NumBuffer, '0', i1.size);
	i2NumBuffer[i1.size] = '\0';

	//pointer to original i2
	const char* i2Num = i2.num;

	//buffer for result
	char* res = new char[i1.size + 2];
	memset(res, '0', i1.size+1);
	res[i1.size+1] = '\0';

	for (int i = 0; i <= diff; i++){
		//shift
		memset(i2NumBuffer, '0', i1.size);
		i2NumBuffer[i1.size] = '\0';
		for (int j = 0; j < i2.size; j++){
			i2NumBuffer[i + j] = i2Num[j];
		}
		
		//cout << i2NumBuffer << endl;

		char count = 0;
		while (BigInteger::Compare(i1Num, i2NumBuffer, i1.size) >= 0){
			BigInteger::subtractHelper(i1Num, i1.size, i2NumBuffer + i, i1.size - i);
			count++;
		}

		//cout << i1Num << endl;

		int baseSize = diff + 1 - i;
		//cout << baseSize << endl;

		char* baseBuffer = new char[baseSize+1];
		memset(baseBuffer, '0', baseSize);
		baseBuffer[baseSize] = '\0';
		baseBuffer[0] = count + '0';
		
		//cout << baseBuffer << " " <<strlen(baseBuffer) << endl;
		//cout << count << endl;
	
		//cout << res << endl;
		BigInteger::addHelper(res, i1.size+1, baseBuffer, baseSize);

		delete[] baseBuffer;
	}
//12345
//00012

	delete[] i2NumBuffer;
	delete[] i1Num;
	BigInteger result(res);
	delete[] res;
	return result;

}

int main(int argc, char* argv[]){
	string i1Str;
	string i2Str;
	string o;
	cin >> i1Str >> o >> i2Str;

	BigInteger i1 = BigInteger(i1Str.c_str());
	BigInteger i2 = BigInteger(i2Str.c_str());
	BigInteger res;
	if (!o.compare("+")){
		res = i1 + i2;
	}
	else if (!o.compare("-")){
		res = i1 - i2;
	}
	else if (!o.compare("*")){
		res = i1 * i2;
	}
	else if (!o.compare("/")){
		res = i1 / i2;
	}
	//i1.Print();
	//i2.Print();
	res.Print();

	


	return 0;
}
