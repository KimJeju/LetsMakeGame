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
    return 0;
}