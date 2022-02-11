﻿#include <iostream>
#include <functional>
using namespace std;


/*
함수포인터 : 함수의 메모리를 저장하기 위한 포인터 변수를 선언할 수 있다.
             전역함수의 경우 함수명이 곧 함수의 메모리 주소이다.

함수 포인터 선언 방법 : 반환타입 (*포인터변수명)(인자타입); 의 형태로 구성이 된다

*/



int sum(int a, int b)
{
    return a + b;
}

int OutSum(int a, int b)
{
    cout << a - b << endl;
    return a +- b;

}

float Testfunc(float a)
{
    cout << a << endl;
    return a;
}

void OutPut()
{
    cout << "OutPut Function" << endl;
}

class CHanzzo
{
public:
    CHanzzo()
    {
        m_itest = 10;
    }

    ~CHanzzo()
    {
    }


public:
    int m_itest;

public:
    void OutPut()
    {
        cout << "Hanzo" << endl;

        //this는 생략할 수 있다. 
        cout << "m_test :" << this->m_itest << endl;
    }
};

typedef struct _tagPoint
{
    int x;
    int y;
}PINOT, *PPOINT;

;

int main()
{

    int(*pFunc)(int, int) = sum;

    cout << pFunc(10, 20) << endl;

    pFunc = OutSum;

    OutSum(10, 20);

    //pFunc = OutPut;

    void(*pFunc1)() = OutPut;

    pFunc1();

    CHanzzo hanzo1, hanzo2;

    hanzo1.m_itest = 100;
    hanzo2.m_itest = 200;


    //this 포인터 : 클래스 안에서 this 를 사용할 경우 해당 객체의 메모리 주소가 된다. 즉 자기자신이 포인터이다.
    // 멤버 함수를 호출할때 this 를 호출자로 생성한다.
    hanzo1.OutPut();
    hanzo2.OutPut();


    // 멤버함수포인터 선언시 포인터 변수 이름 앞에 클래스명:: 을 붙여준다.
    // :: <- 범위지정연산자

    void (CHanzzo:: * pFunc2)() = &CHanzzo::OutPut;

    //pFunc2():
    //hanzo1.(*pFunc2)();

    (hanzo1.*pFunc2)();

    /*
    function 기능은 C++ 11 부터 지원해주는 기능이다. 이 기능은 함수포인터를
    전역,멤버 가리지 않고 쉽게 주소를 저장해서 호출 해 줄 수 있도록 만든 기능이다.

    선언방법 : function<리턴타입(인자타입)> 변수명;
    */


    function<void()> func;
    function<void()> func1;


    //bind 를 이용해서 함수를 묶어준다,

    func = bind(OutPut);
    func1 = bind(&CHanzzo::OutPut, &hanzo2);


    cout << "========= functional ========" << endl;
    func();
    func1();

    function<int(int, int)> func3;
    function<float(float)> func4;


    //함수에 인자가 있을 경우 placeholders를 이용해서 인자의 순서를 정의할 수 있다.
    //아래처럼 2,1로 넣어주면 인자가 서로 바뀌게 된다.
    func3 = bind(OutSum, placeholders::_2,placeholders::_1);


    //위에서 2,1로 바꿔줬으므로 10은 b에 20은 a에 들어가게 된다
    func3(10, 20);

    func4 = bind(Testfunc, placeholders::_1);

    func4(3.14);


    return 0;
}
