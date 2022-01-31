#include <iostream>
using namespace std;

int main()
{
	/*
	포인터 : 가리키다. 일반변수는 일반적인 값을 저장하게 되지만
			 포인터 변수는 메모리 주소를 저장하게 된다. 모든 변수타입은 포인터 타입을
			 선언할 수 있다. int변수 주소는 int 포인터 변수에 저장을 해야한다.
			 포인터는 메모리 주소를 담아놓는 변수 이기 때문에 X86으로 개발할 때는 무조건 4byte가 나온다
			 x64 일때는 8byte가 나온다. 
	
			포인터는 스스로 아무일도 할 수 없다. 반드시 다른 변수의 메모리 주소를 가지고 있어야 일을 할 수 있는데
			가지고 있는 메모리 주소에 접근해서 값을 제어할 수 있다.
	형태 : 변수타입 *변수명 : 형태로 선언
	*/
	int iNumber = 100;
	// 변수 선언시 ^을 붙여주면 해당 타입의 포인터 변수가 선언된다
	// 변수 앞에 &을 붙여주면 해당 변수에 메모리 주소가 된다.
	// pNum 은 iNumber 의 메모리 주소값을 가지게 된다. 그러므로 pNum을 이용해서 iNumber의 값을 제어할 수 있게 된 것이다.
	int *pNum = &iNumber;
	

	// int = 4byte || char = 1byte || double = 8byte 지만 포인터를 선언할시 모두 4byte가 출력된다, 메모리를 저장했기 떄문에
	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(double*) << endl;

	// pNum을 이용해서 iNumber 값을 제어해보자.
	// 역참조를 이용해서 값을 얻어오거나 변경할 수 있다.
	// 역참조는 포인터 변수 앞에 별을 붙이게 되면 역참조가 된다.
	cout << *pNum << endl;
	*pNum = 1234;

	cout << "iNumber Value :" << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "pNum Value :" << pNum << endl;
	cout << "pNum Address :" << &pNum << endl;

	return 0;
}

