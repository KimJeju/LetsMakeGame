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
	NUM eNUM;
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
	system("cls");


	return 0;
}

