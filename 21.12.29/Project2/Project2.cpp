#include <time.h> //시간관련 기능
#include <iostream>
using namespace std;


//상수 : 변하지 않는 수 , 값 지정 후 못바꿈
//상수는 선언과 동시에 값을 지정해 두어야 한다. -> const (상수)
// 0X ~ 각 16진수 표현방법
int main() {
    const int iAttack = 0x00000001; // 1
    const int iArmor = 0x00000002; // 10
    const int iHP = 0x00000004;   // 100
    const int iMP = 0x00000008;  // 1000
    const int icritical = 0x00000010; // 10000

    // 001 | 100 = 101 | 10000 = 10101
    int iBuf = iAttack | iHP | icritical;

    /*
    연산자 축약형: 연산자를 줄여서 사용할 수 있다
    아래를 풀어서 쓰면 iBuf = iBuf ^iHP
    10101 ^ 00100 = 10001
    */
    iBuf ^= iHP;

    // 10001 ^ 00100 = 10101
    iBuf ^= iHP;

    // 10101 & 00001 = 1 
    cout << "ATTACK : " << (iBuf & iAttack) << endl;

    // 10101 & 00010 = 0
    cout << "Armor :" << (iBuf & iArmor) << endl;

    // 10101 & 00100 = 1
    cout << "HP :" << (iBuf & iHP) << endl;

    // 10101 & 01000 = 0
    cout << "MP :" << (iBuf & iMP) << endl;

    // 10101 & 10000 = 1
    cout << "critical :" << (iBuf & icritical) << endl;

    /*
    쉬프트 연산자 : <<, >> 값 대 값을 연산하여 값으로 나오게한다, 이 연산자 또한 이진수 단위의 연산을 하게 된다.

         (2의 N)
    20 << 2 = 80
    20 << 3 = 160
    20 << 4 = 320
    20을 2진수로 변환한다.
    1010000
    10100000
    101000000
    -----------
    20 >> 2 = 5
    20 >> 3 = 2

    101
    10
    */


    int iHigh = 187;
    int iLow = 13560;

    int iNumber = iHigh;
    iNumber <<= 16;

    // iNumber에는 187이 들어가있다 . 이 값을 -> 이 방향으로  16비트 이동시키면 상위 16비트에 값이 들어가게 된다.

    // 하위 16비트를 채운다

    iNumber |= iLow;

    // High 값 출력

    cout << "high :" << (iNumber >> 16) << endl;
    cout << "Low :" << (iNumber & 0x0000ffff) << endl;

    /*
    증감연산자 : ++, -- 가 있다. 1증가. 1감소이다.
    */

    iNumber = 10;
    //전치
    ++iNumber;
    //후치
    iNumber++;

    cout << ++iNumber << endl;
    cout << iNumber++ << endl; // 출력하면 13이 나온다. 출력 후 값을 1 증가시키기 때문에
    cout << iNumber << endl; // 출력하면 14가 나온다. 전에 출력한 값 1을 받아오기 때문에.

    /*
    분기문에는 크게 if문과 switch문이 있다.
    if문 : 조건을 체크해주는 기능이다.
    형태 : if(조건식) {} <- 코드블럭
    특징 : 조건식이 true가 될 경우 코드블럭 안에 코드가 동작 false일 경우에는 동작되지 않는다.
    */

    if (true) {
        cout << "동작한다" << endl;
    }

    if (false) {
        cout << "동작안함" << endl;
    }

    //버프가 있는지 확인한다.
    if ((iBuf & iAttack) !=0) {
        cout << "어택버프 있음" << endl;
    }
    //if문 아래에 들어갈 코드가 1줄일 경우 {}을 생략할 수 있다
    if ((iBuf & iArmor) != 0)
        cout << "아머버프 있음" << endl;

    if ((iBuf & iHP) != 0)
        cout << "HP버프있음" << endl;

    if ((iBuf & iMP) !=0)
        cout << "MP버프있음" << endl;

    if ((iBuf & icritical) !=0)
        cout << "크리티컬버프 있음" << endl;
    /*
    else : if문과 반드시 같이 사용이 되어야 한다.
    if문 조건이 false 일 경우 else가 있다면 else구문안에 코드가 동작한다
    
    else if : if문과 반드시 같이 사용이 되어야 한다.
    if문 아래 와야하고 else보다 위에 ㅣㅇㅆ어야 한다.
    else if 는 자신의 위에 있는 조건식이 false일 경우 다음 else if의 조건식을 체크한다.
    else if는 몇개든 사용이 가능하다.
    */

    if (false) {
        cout << "if문 조건이 true입니다" << endl;
    }
    else {
        cout << "if문 조건이 false입니다" << endl;
    };

    cout << "숫자를 입력하세요 :";
    cin >> iNumber;

    if (10 <= iNumber && iNumber <= 20)
    {
        cout << "10~20사이에 숫자입니다" << endl;
    }
    else if(21 <= iNumber && iNumber <= 30) {
        cout << "21~30사이입니다" << endl;
    }
    else if(31 <= iNumber && iNumber <= 40) {
        cout << "30~40사이입니다" << endl;
    }
    else { //마지막에 else가 없을 시 아무것도 동작하지 않음. 
        cout << "그 외 숫자입니다" << endl;
    }

 //난수 발생 | 변수의 형변환(타입케스팅 | 안쓸 시 경고) 
    srand((unsigned int)time(0));
 //srand() : 난수선언 기능  
        cout << rand() << endl;
        cout << rand() << endl;
        cout << rand() << endl;
        cout << (rand() % 101) << endl;
        cout << (rand() % 101 + 100) << endl; // 100 ~ 200
//rand() : 임의에 값을 얻어오는 변수
        cout << (rand() % 10000 / 100.f) << endl; // .00 자리 까지 나타냄 -> 10000을 지정해서 나누기 100.float

    
    return 0;
}

//Hello World