//include : ��������� ���⿡ ���Խ�Ų��.
/*
������� : ������ -> ���� -> ����
������ : �����۾�
��Ʈ�� + ����Ʈ + B �� ������ & ���� ����
*/
#include <iostream>
using namespace std;
//using namespace std : std��� ���ӽ����̽��� ����ϰڴ�. -> std:: ��������

// C++�� �������� main�Լ��̴�. main�Լ��� �ݵ�� �־���Ѵ�.
// C++ ǥ�� ����� ��κ� std ��� namespace �ȿ� �����ϰ� �ִ�. �̸��� ��ġ�� ���� �������ֱ� ���� ����̴�
/*
cout : �ܼ�â�� ������ִ� ����̴�. �ھ� �ִ� ""(ū����ǥ) �ȿ� �ִ� ���ڵ��� ȭ�鿡 ������ش�
���� �������� ����� ������ �ݵ�� "" �ȿ� �־��ְ� �̷����� ���ڿ� �̶�� �Ѵ�.
*/
// endl : ���� ���ڿ� (�ٹٲ�)
int main() {
	std::cout << "hello" << std::endl;

/*
���� : ���ϴ� ��, ���� �ٲ� �� �ִ�.
�뷮�� �ּҴ��� : bit
1byte = 8bit
1kbyte = 1024byte
1mbyte = 1024kbyte
1kbyte = 1024mbyte
1mbyte = 1024gbtye
1gbyte = 1024tbyte

���ڸ� ǥ���ϴ� ��� : ASCII �ڵ� ǥ�� ������ �ִ�.
false : 0
true : 0�� �ƴ� ��� ��
unsigned : ��ȣ�� ����

����   l  �뷮   l  �������� l       ǥ������         l  unsigned  ��
char   l  1byte  l   ����    l -128 - 127(��: 256)    l   0 - 255
bool   l  1byte  l  ��/����  l    true / false        l  true / false
short  l  2byte  l   ����    l    -32768 -32767       l  0 - 65535
int    l  4byte  l   ����    l  �� -22�� - 21��       l  0 - �� 43��
float  l  4byte  l�Ǽ�(�ε�) l   
double l  8byte  l   �Ǽ�    l
*/
// = : ���Կ�����. �����ʿ� �ִ� ���� �������� �����Ѵ�.

	int Number = 10;
	Number = 20;

	std::cout << Number << std::endl;

	bool bTest = true;
	bTest = false;

	cout << bTest << endl;


	//�����̳� ���ڴ� 1byte , �ѱ��̳� �ѹ� 2byte -> char ���� �ϳ��� ��������
	char cTest = 'a';
	cTest = 'b';
	cout << cTest << endl;
   
	//float �� ���� �ڿ��� f�� �ٿ��� ��, �ƴϸ� double ��
	float fNumber = 3.14f;

	cout << fNumber << endl;

	double dNumber = 3.141597;

	cout << dNumber << endl;

	/*
	��Ģ������ : + , - , *, /, %(������ ������) 
	���迬���� : >, >=(A : B ũ�ų� ����), <, <=(A : B �۰ų� ����), ==(����), !=(A�� B�� �ٸ���) / ( ���� ���� �����Ͽ� ��/�������� ����� ��ȯ )
	���������� : AND(&&)->�� �� ���϶��� ��, �� ���߿� �ϳ��� �����̸� ����, OR(||) , NOT(!) / ( ��/���� �� ��/������ �����Ͽ� ������� ��/�������� ��ȯ�Ѵ�. )
	A B AND OR
	0 0  0  0
	0 1  0  1
	1 0  0  1
	1 1  1  1

	A  NOT
	1   0
	0   1

	���� : 2����, 8���� , 10����, 16����
	2���� : 2, 8 , 10 , 16 ( 0 ~ 1 )
	8���� : 0 ~ 7
	10���� : 0 ~ 9
	16���� : 0 ~ 15 : 0 ~ 9 : 10 ~ 15 : a ~ f
	
	�������� ���� �ٸ� ������ ��ȯ�� �����ϴ�.


	���� �������� ���� ����� �������� ������ ������ �д´�.
	1010111 �� �ȴ�.

	16������ ��ȯ�غ���, 10������ �ٷ� 16������ ��ȯ�ϴ� �� ����  2������ ��ȯ�ϰ� 16������ ��ȯ �ϴ� ���� ����. 

	1010111�� ���������� ���� ���ڸ��� ��� ���, 16���� ���ڸ��� 2���� ���ڸ�
	0101 0111
	8421 8421

	2������ 1�κκ��� ���� ���Ѵ�.
	16���� 5 / 7 �� �ȴ�.

	��Ʈ���� ���������� : 2���� ������ ������ �Ѵ�. �� �� ���� �����Ͽ� ������ ��ȯ
	���� : AND(&), OR(|) , NOT(~ <- �ʵ�), XOR(�ͽ�Ŭ��ú�OR / ^)

	A   B  XOR ( �� ���� ���� �� false �ٸ� �� true )
	0   0   0
	1   0   1
	0   1   1
	1   1   0

	87 & 53 = 21
	87 : 1010111
	53 : 110101

	87 & 53 2���� 16������ ��ȯ �غ���

	���� 2������ ��ȯ�Ѵ�.

	87 / 2 = 43 --- 1
	43 / 2 = 21 --- 1
	21 / 2 = 10 --- 1
	10 /2  = 5  --- 0
	5 /2   = 2  --- 1
	2 / 2  = 1 --- 0

	53 / 2 : 26 --- 1
	26 / 2 : 13 --- 0
	13 / 2 : 6  --- 1
	6 /  2 : 3 --- 0
	3 /  2 : 1 --- 1

	��ó�� 2������ ��ȯ�� �Ŀ� 2���� �� �ڸ����� ���������� ����

	 1010111
	&0110101
	 0010101 (XOR)
	   10101 �� ����
	  

	10������ ��ȯ�ϸ�
    10101 = 1, 2 ,4 ,8 ,16 ���� ���� 1�� �κи� ����

	*/

	cout << "10 < 20 = " << (10 < 20) << endl;
	cout << "10 <= 20 = " << (10 <= 20) << endl;
	cout << "10 > 20 = " << (10 > 20) << endl;
	cout << "10 >= 20 = " << (10 >= 20) << endl;
	cout << "10 == 20 = " << (10 == 20) << endl;
	cout << "10 != 20 = " << (10 != 20) << endl;

	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> Number;

	cout << "10 ~ 20 :" << (10 <= Number && Number <= 20) << endl;
	
	cout << "87 & 53 = " << (87 & 53) << endl;




	return 0;
}