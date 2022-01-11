#include <iostream>
#include <time.h>
using namespace std;
/*
열거체 : 연속된 숫자에 이름을 부여할 수 있는 기능이다. 잘쓰면 코드도 이쁘고 편하게 짤수 있다.
enum 열거체명 {} 의 형태로 구성
열거체명을 이용해서 열거체 타입의 변수를 선언도 가능하다
즉, 열거제 자체가 사용자정의 변수 타입이 될 수도 있다.\
열거체는 숫자에 이름을 붙여주는 이름이다.
*/

enum NUM
{
	NUM_0 = 10, // 아무것도 부여하지 않을 경우 0부터 1씩 차례로 값이 부여된다 , 값을 지정하였을 경우 지정한 값에서 1씩 증가한다.
	NUM_1,
	NUM_2,
	NUM_3

};

enum SRP
{
	SRP_S = 1,
	SRP_R,
	SRP_P,
	SRP_END
};

#define NUM_4 4//전처리기능자
int main()
{
	/*
	switch 문 : 분기문의 한 종류,if문을 조건을 체크하는 분기문이라면
	switch 문은 값이 뭔지를 체키하는 분기문이다.
	형태 : switch(변수) {} 형태로 구성 , 코드블럭 안에는 case break 문으로 구분
	case 상수 : 의 형태로 처리가 되고 변수값이 무엇인지에 따라서 case 뒤에 오는 상수를 비교하게 된다.
	*/

	int iNumber;
	cout << "숫자를 입력하세요 : ";
	cin >> iNumber;

	switch (iNumber) {

	case NUM_1: //INumber 값이 무엇인지에 따라서 실행되는 case 구문이 결정된다
		cout << "입력한 숫자는 1 입니다." << endl;
		break; //break 를 만나게 되면 switch 문을 빠져나가게 된다.
	case NUM_2:
		cout << "입력한 숫자는 2 입니다." << endl;
		// 브레이크가 없을 경우 바로 아래에 case 구문도 함께 실행된다.
	case NUM_3:
		cout << "입력한 숫자는 3 입니다." << endl;
		break;
	case NUM_4:
		cout << "입력한 숫자는 4 입니다." << endl;
		break;
	default: // case 로 지정되어 있지 않은 숫자가 들어올 경우 실행된다 , if문 에서의 else와 같다.
		cout << "지정되지 않은 값 입니다" << endl;
		break;
	}

	// 열거체 타입의 변수를 선언했다. 열거체 타입의 변수는 무조건 4byte를 차지한다
	// 열거체를 이용해서 선언한 변수는 값의 표현 범위가 열거체에 나열된 값들 안에서 선택되어 사용된다.
	NUM NUM;
	/*
	NUM eNUM = 10 || 타입을 변환할 수 없다는 오류가 난다. 이유는 위에 NUM이라는 변수를 선언했기 때문에 int 형 값이 들어가지 않는 것이다.  || 이때는 NUM eNUM = (NUM)10; 을 하면 들어는 간다
	*/

	//sizeof(타입 or 변수) 를 하게 되면 타입 or 변수의 메모리 크기를 반환한다
	cout << sizeof(NUM) << endl;
	//typeid(타입 or 변수).name()를 하게되면 위에 typeid안에 들어간 타입 혹은 변수의 타입을 문자열로 반환해준다.
	cout << typeid(NUM).name() << endl;


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
		++iNumber; // 9까지 출력 후 빠져나옴

		if (iNumber == 4)
			break; // 4까지만 출력하고 빠져나옴
	}
	// 콘솔창을 지우는 명령어


	/*
	for문 : 반복문의 한종류 || for(초기값 : 조건식 : 증강식) {}
			조건문이 true 일 시 코드블럭을 실행, 무한루프를 돌릴 떄는 for(::) {} 를 해주면 무한루프가 돌아간다.
			forr문에서 초기값은 처음 for문을 진입할 때 한번만 동작되고 그 후에 조건식을 체크하고 조건식이 true라면 코드블럭의 코드가 동작된 후에 증감값을 처리
			그 후 다시 조건을 체크하고 ture면 동작되고 증감 -> 조건 -> 증감 -> 조건의 순서로 처리된다. 조건이 false이거나 break를 만나게되면 for 문을  빠져 나가게된다
	for(int i = 0 : i < 100 ++i)
	{
	cout << rand() %  701 + 1000 << endl;
	}
	*/

	// 초기값 i = 0 || 조건식 i < 10 || 증감값 ++i

	/*
	먼저 for문에 진입하면서 초기값이 입력되어 i = 0 이 된다.
	그 후에 i < 10 을 체크해서 0 일 때는 true가 나오게 되어 i 값을 출력한다.
	그 후에 증감을 처리하는데 ++을 하면 0 -> 1이 되고 조건을 체크하게 된다
	1은 10보다 작음으로 true 가 나오고 1,2,3,4,5,6,7,8,9 까지(true 까지) 반복되고
	조건을 반복하다 10이 되면 조건이 false가 되므로 코드블럭을 빠져 나오게 된다
	*/
	// for문은 반복보단 동시에 동작된다
	for (int i = 0; i < 10; ++i)
	{
		cout << i << endl;
	};

	//구구단 2,3단
	for (int i = 1; i <= 9; ++i)
	{
		cout << "2 *" << i << "=" << 2 * i << endl;
		cout << "3 *" << i << "=" << 3 * i << endl;
	};

	// 1 ~ 100 사이에 짝수 출력
	// 아래 증감식 i = i + 2 의 축약형
	for (int i = 2; i <= 100; i += 2)
	{
		cout << i << endl;
	}


	// 1 ~ 100 시아의 숫자중 3과 7의 공배수만 출력하는 if문을 만들어보자.
	for (int i = 0; i <= 100; ++i)
	{
		if (i % 3 == 0 && i % 7 == 0)
			cout << i << endl;
	}

	// 중첩for문 : for문 안에 for문이 존재하는 형태
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << "i =" << i << "j =" << j << endl;
		}
	}

	//구구단을 2단 부터 9단까지 출력하는 중첩 for문을 만든다
	for (int a = 2; a <= 9; ++a)
	{
		for (int b = 1; b < 10; ++b)
		{
			cout << a << "*" << b << ":" << a * b << endl;
		}
		cout << "\n";
	};

	/*
	별을 아래 형태로 출력한다
	*
	* *
	* **
	*/
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "*";

		}
		cout << "\n";
	};


	// 위와 반대로 별을 줄인다

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 10; j >= i; j--)
		{
			cout << "*";

		}
		cout << "\n";
	};


	return 0;
}

