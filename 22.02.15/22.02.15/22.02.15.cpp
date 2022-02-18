#include <iostream>
using namespace std;


template <class T>
void OutPuttype()
{
	cout << "=========== OutPutData ==========" << end;
	cout << typeid(T).name() << endl;
}

template <class T>
void OutPutData(T data)
{
	cout << "=========== OutPutData ==========" << end;
	cout << typeid(T).name() << endl;
	cout << data << endl;
}

int main()
{

	OutPuttype<int>();
	OutPuttype<float>();

	OutPutData(10);
	OutPutData(3.1);
	//OutPutData(382, 382.f);
	OutPutData('a');
	OutPutData("ㅋㅋㅋㅋㅋㅋ");

	return 0;
}

//언리얼 공부중이라 잠시중단 
//언리얼 공부중인데 업로드 불가 용랑 큼

