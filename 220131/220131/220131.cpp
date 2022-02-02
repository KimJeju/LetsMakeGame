#include <iostream>
using namespace std;

struct _tagStudent
{
	int iKor;
	int IEng;
	int iMath;
	int iTotal;
	float fAvg;
};


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
	int* pNum = &iNumber;


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

	/*
	포인터와 배열의 관계 : 배열명은 포인터다 << 완전 중요 , 배열명 자제차체가 해당 배열의
						   시작점 주소를 의미한다.
	*/

	int iArray[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "iArray Address :" << iArray << endl;
	cout << "iArray Address :" << &iArray[0] << endl;

	int* pArray = iArray;

	cout << pArray[2] << endl;

	/*
	포인터 연산 : +, - 연산을 제공한다. ++, -- 도 가능하지만 1을 증가하게되면
				  단순히 메모리주소 값이 1증가하는 것이 아니다.
				  int 포인터의 경우 int 타입에 메모리 주소를 갖게 되는데 메모리 주소에 1을 더해주면
				  1증가가 아닌 가르키는 해당 포인터 타입의 변수타입 크기 만큼 증가하게 된다.
				  int 포인터 이므로 int 의 크기인 4만큼 값이 증가하게 되는 것이다.
	*/

	cout << pArray << endl;
	cout << pArray + 2 << endl;

	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *pArray + 100 << endl;

	_tagStudent tStudent = {};

	tStudent.iKor = 100;

	_tagStudent* pStudent = &tStudent;

	//연산자 우선순위 때문에 .을 먼저 인식하게 된다 메모리주소.은 졸못된 문법이다
	//그러므로 *pStudent 를 ()로 감싸준 후에 .을 이용해서 가르키는 대상의 멤버 변수에 접근해야한다
	(*pStudent).iKor = 50;

	//메모리주소 -> 를 이용해서 가르키는 대상의 멤버에 접근할 수 있다.
	pStudent->iKor = 80;

	cout << tStudent.iKor << endl;

	// void : 타입이 없다. void의 포인터 타입을 활용할 수 있다.
	// void* 변수를 선언하게 되면 이 변수는 어떤 타입의 메모리 주소든
	// 모두 저장가능하다. 단, 역참조가 불가능하고 메모리 주소만 저장가능하다.
	void* pVoid = &iNumber;


	//*pVoid = 10; || 형 변환을 해줘야함
	int* pConvert = (int*)pVoid;
	*pConvert = 10101010;
	*((int*)pVoid) = 9999;
	cout << iNumber << endl;

	cout << "iNumber Address :" << pVoid << endl;
	pVoid = &tStudent;

	cout << "tStudent Address :" << pVoid << endl;


	int iNumber1 = 1111;
	iNumber = 2222;
	pNum = &iNumber;

	//이중 포인터  * 을 2개 붙인다. 일반포인터 변수가 일반 변수 메모리 주소를 저장하는 변수라면
	//이중포인터는 포인터의 포인터이다, 즉 이중포인터는 포인터 변수의 메모리 주소를 저장하는 포인터 이다.
	int** ppNum = &pNum;


	*ppNum = &iNumber1;
	*pNum = 3333;

	cout << "iNumber1 :" << iNumber1 << endl;
	cout << "iNumber :" << iNumber << endl;
	cout << "iNumber Addr :" << &iNumber << endl;
	cout << "pNum :" << *pNum << endl;
	cout << "pNum Addr" << &pNum << endl;
	cout << "pNum value :" << pNum << endl;
	cout << "ppNum" << *ppNum << endl;
	cout << "**ppNum : " << **ppNum << endl;
	cout << "ppNum :" << ppNum << endl;
	cout << "ppNum Addr :" << &ppNum << endl;

	//아 내일공부하자,,

	//test
	//test2

	return 0;
}

