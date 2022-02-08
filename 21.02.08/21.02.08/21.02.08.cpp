﻿#include <iostream>
using namespace std;

int main()
{

	/*
	
	동적할당 : 메모리 생성을 원하는 시점에 할 수 있는 기능이다.
	메모리 영영중 힙영역에 공간이 할당된다. 힙의 특성상 메모리를 해제하기 전까지는 계속 남아있다.
	할당하고 메모미를 해제하지 않으면 사용하지는 않지만 공간은 계속 잡혀있게 된다.
	해당 공간은 다른 곳에서 사용이 불가능 하다.

	이런 현상을 메모리 릭 이라고 힌다.

	동적 할당은 new 키워드를 이용해서 할 수 있다.
	c언어 에서는 malloc() 함수를 이용해서 사용할 수 있다.

	new 할당할타입; 으로 처리한다.

	new 나 malloc 둘다 마찬가지로 힙 영역에 메모리 공간을 할당하고 해당 메모리의 주소를 반환해준다.

	delete 키워드를 이용해서 동적할당한 메모미를 해제할 수 있다.
	delete 뒤에 메모리 주소를 넣어주면 된다.

	*/


	// 아래처럼 할당해주면 new 뒤에 들어오는 타입인 int의 크기만큼 공간을 할당한다
	// 즉 4바이트 곤간을 할당하는 것이다. 그 뒤에 할당한 공간의 메모리 주소를 pNumber에 넣어주었다.
	
	int* pNumber = new int;

	*pNumber = 100;

	delete pNumber;

	/*
	동적배열할당 방볍 : new 타입[개수]; 의 형태로 사용할 수 있다.

	아래처럼 동적배열로 할당하면 메모리 공간에 400바이트 만큼 공간을 할당하고 해당 메모리에
	시작 주소를 반환한다.
	*/

	int* pArr = new int[100];

	pArr[1] = 300;

	delete[] pArr;

	return 0;
}