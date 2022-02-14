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
