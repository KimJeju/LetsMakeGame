#include <iostream>
using namespace std;

/*
상속 : 클래스는 서로간에 부모와 자식 관계를 형성 할 수 있다.
	   자식 클래스는 부모클래스의 멤버들을 사용할 수 있다.

부모클래스에서 public 이나 protected 로 되어 있는 멤버들은 사용가능하지만,
private 로 되어있는 멤버는 자식에서도 사용이 불가능하다.

상속의 형태 : public 상속, private 상속이 있다.



*/


class CParent
{
public:
	CParent()
	{
		cout << "CParent 생성사 출력" << endl;

	}

	~CParent()
	{
		cout << "CParent 소멸자 출력" << endl;

	}

public:
	int m_iA;

protected:
	int m_iB;

private :
	int m_iC;

public:
	void Output()
	{
		cout << "A :" << m_iA << endl;
		cout << "B :" << m_iB << endl;
		cout << "C :" << m_iC << endl;

	}
};

class CChild : public CParent
{
public:
	CChild()
	{
		m_iB = 100;
		//m_iC 는 private 기 때문에 자식 내부에서도 접근이 불가능 하지만 protected는 접근이 가능하다.
		//m_iC = 100;
		cout << "CChild 생성사 출력" << endl;

	}

	~CChild()
	{
		cout << "CChild 소멸자 출력" << endl;

	}
protected:
	int m_iD;

};

class Cchild1 : private CParent
{
public:
	Cchild1()
	{
		m_iA = 100;
		m_iB = 300;
		cout << "Cchild1 생성자 출력" << endl;

	}

	~Cchild1()
	{
		cout << "Cchild1 소멸자 출력" << endl;

	}

private:
	int m_iD;
};

class CchildChild : public CChild
{
public:
	CchildChild()
	{
		m_iD = 500;
		cout << "CchildCilde 생성자 출력" << endl;
	}

	~CchildChild()
	{
		cout << "CchildCilde 소멸자 출력" << endl;

	}

private:
	int m_iE;

};

int main()
{
	/*
	상속관계에서의 생성자 호출 순서 : 부모 -> 자식  순으로 호출된다.
	상속관계에서의 소멸자 호출 순서 : 자식 -> 부모 순으로 호출된다.
	*/

	CParent parant;
	CChild  child;
	Cchild1 child1;
	CchildChild childchild;

	parant.m_iA = 100;

	child.m_iA;


	// CChild1 클래스는 CParent를 private 상속을 하고 있으므로 CParent에 public 으로
	// 설정되어있는 멤버들도 외부에서는 접근이 불가능하다.
	
	//child1.m_iA = 300;
	//child1.OutPut();

	return 0;
}
