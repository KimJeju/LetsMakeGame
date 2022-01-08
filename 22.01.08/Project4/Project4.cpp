#include <iostream>
#include <time.h>
using namespace std;

int main() 
{
	int iNumber = 1;

	/*
	반복문 : 특정 작업을 반복해서 수행해주는 기능이다.
	종류 : for, while, do while 3종류가 존재한다.
	while(조건식) {}  의 형태로 구성된다.
	while 문은 조건식을 체크해서 코드블럭 안에 코드가 true 일 경우 동작되고 다시 조건식을 체크한다. 조건식이 false가 되면 while문을 빠져나오게 된다.
	반복문 안에서 break를 만나게 되면 해당 반복문에서 빠져나오게 된다.
	*/

	iNumber = 0;
	while (iNumber < 10)
	{
		cout << iNumber << endl;
		++iNumber;

		if (iNumber == 4)
		break;
	
	}

	return 0;
}