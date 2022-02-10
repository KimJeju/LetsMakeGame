#include <iostream>
using namespace std;

//pp는 main 함수 안에 있는 int* 타입의 p변수의 주소를 가지게 된다.
void Test(int** pp)
{
	*pp = new int;
}
int main()
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

	//int* p = NULL:

	//Test(&p);

	FILE* pFile = NULL;


	// 1번 인자 : 파일의 이중 포인터 인자.
	// 2번 인자 : 파일 경로이다. 파일이 생성되는 기준 경로는 현재 프로젝트가 있는 폴더 기준이다. 만약 실행 파일로 실행했을 경우 해당 exe파일이 있는 경로를 기준으로 생성
	// 3번 인자 : 파일 모드이다. 모드는 크게 2가지로 구분된다. 파일 읽기,쓰기,접근이 있고 파일 형태 형태는 txt,바이너리 파일 두가지가 있어서 합쳐서 표현 
	// r : 읽기 : w : 쓰기 a : 접근           t : 텍스트  b : 바이너리 파일
	
	
	/*
	fopen_s(&pFile, "hot.txt","wt");

	if (pFile != NULL)
	{
		//fwrite , fread 2개 함수 제공 
		//fputs, fgets 도 제공

		//void는 int,float 등 다양한 메모리를 저장할 순 있지만, 메모리에 접근해서 무언가 작업을 하는 것은 불가능하다. 즉, 단순 메모리 저장용
		char const* pText = "abcd";

		//1번 인자는 저장하고자 하는 값의 메모리 주소를 넣어준다.
		//2번 인자는 저장하고자 하는 값의 변수타입에 메모리 크기를 넣어준다
		//3번 인자는 저장하고자 하는 값의 개수를 넣어준다
		//4번 인자는 저장할 파일에 스트림을 넣어준다.

		fwrite(pText,1,4,pFile);

		fclose(pFile);

		cout << "파일 만들기 성공" << endl;
	}
	*/

	// --------------------------- 파일 읽기 -------------------------

	fopen_s(&pFile, "hot.txt", "rt");

		if (pFile)
		{

			char strText[5] = {};

			fread(strText, 1, 4, pFile);

			cout << strText << endl;

			fclose(pFile);

			cout << "파일읽기성공" << endl;
		}


	return 0;
}
