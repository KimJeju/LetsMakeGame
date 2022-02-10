#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

/*
0 : ��
1 : ��
2 : ������
3 : ������
4 : ��ź
5 : �Ŀ�������
6 : ���б� ������
7 : ���������
8 : ��Ȧ
*/

// x.y��
struct _tagPoint
{
	int x;
	int y;
};


//typedef Ÿ���� �������ϴ� ����̴�.
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

typedef struct _tagPlayer
{
	_tagPoint tPos;
	bool bWallpush;
	bool bPushOnOff;
	bool bTransparency;
	int iBombPower;
}PLAYER, * PPLAYER;


//�̷� ����� && �÷��̾� ��ġ && �� ��ġ && ������ġ
void SetMaze(char Maze[21][21], PPLAYER pPlayer, PPOINT pStartPos, PPOINT pEndPos)
{
	// MazeList.txt ������ �о�ͼ� �̷� ����� �����.
	FILE* pFile = NULL;

	fopen_s(&pFile, "MazeList.txt", "rt");

	if (pFile)
	{
		char cConut;

		fread(&cConut, 1, 1, pFile);
		 
		char** pMazeList = NULL;

		int iMazeCount = atoi(&cConut);

		pMazeList = new char* [iMazeCount];


		for (int i = 0; i < iMazeCount; ++i)
		{
			int iNameCounut = 0;

			pMazeList[i] = new char[256];

			while (true)
			{
				fread(&cConut, 1, 1, pFile);

				if (cConut == '\n')
				{

				}
			}
		}

		fclose(pFile);
	}

	pStartPos->x = 0;
	pStartPos->y = 0;


	pEndPos->x = 19;
	pEndPos->y = 19;


	pPlayer->tPos = *pStartPos;
	/*
	pPlayerPos->x = 0;
	pPlayerPos->y = 0;
	*/

	strcpy_s(Maze[0], "21100000000000000000");
	strcpy_s(Maze[1], "00111111110000000000");
	strcpy_s(Maze[2], "00100100011111110000");
	strcpy_s(Maze[3], "01100100000000010000");
	strcpy_s(Maze[4], "01000111110001110000");
	strcpy_s(Maze[5], "01000000001111110000");
	strcpy_s(Maze[6], "01100000000100000000");
	strcpy_s(Maze[7], "00100000000111100000");
	strcpy_s(Maze[8], "01100000000000111100");
	strcpy_s(Maze[9], "00100011111111100000");
	strcpy_s(Maze[10], "00111100011000000000");
	strcpy_s(Maze[11], "00001000001000000000");
	strcpy_s(Maze[12], "00001110001111000000");
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      	strcpy_s(Maze[13], "00000010000001110000");
	strcpy_s(Maze[14], "00011110000000010000");
	strcpy_s(Maze[15], "00110000000111110000");
	strcpy_s(Maze[16], "00100000000100000000");
	strcpy_s(Maze[17], "00111100000111100000");
	strcpy_s(Maze[18], "00000111110000100000");
	strcpy_s(Maze[19], "00011100010000111100");
	strcpy_s(Maze[20], "00010000010011100113");


}

//�̷� ��� �ݺ�
void OutPut(char Maze[21][21], PPLAYER pPlayer)
{
	for (int i = 0; i < 21; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{

			if (Maze[i][j] == '4')
				cout << "��";

			else if (pPlayer->tPos.x == j && pPlayer->tPos.y == i)
				cout << "��";

			else if (Maze[i][j] == '0')
				cout << "��";

			else if (Maze[i][j] == '1')
				cout << "  ";

			else if (Maze[i][j] == '2')
				cout << "��";

			else if (Maze[i][j] == '3')
				cout << "��";

			else if (Maze[i][j] == '5')
				cout << "��";

			else if (Maze[i][j] == '6')
				cout << "��";

			else if (Maze[i][j] == '7')
				cout << "��";

		}
		cout << endl;
	}
	cout << "��ź�Ŀ� :" << pPlayer->iBombPower << endl;
	cout << "����� :";
	if (pPlayer->bTransparency)
		cout << "ON\t";

	else
		cout << "OFF\t";

	cout << "���б� :";
	if (pPlayer->bWallpush)
	{
		cout << "���� / " << endl;

		if (pPlayer->bPushOnOff)
			cout << "ON" << endl;

		else
			cout << "OFF" << endl;

	}
	else
		cout << "�Ұ��� / OFF" << endl;

}

bool AddiTtem(char cItemType, PPLAYER pPlayer)
{
	if (cItemType == '5')
	{
		if (pPlayer->iBombPower < 5)
			++pPlayer->iBombPower;
		return true;
	}

	else if (cItemType == '6')
	{
		pPlayer->bWallpush = true;
		pPlayer->bPushOnOff =  true;
		return true;
	}

	else if (cItemType == '7')
	{
		pPlayer->bTransparency = true;
		return true;
	}

	return false;
}

//���� �����̱� ���� �Լ�
void MoveUp(char Maze[21][21], PPLAYER pPlayer)
{

	if (pPlayer->tPos.y - 1 >= 0)
	{
		//������ üũ�Ѵ�.
		if (Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '0' && Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '4')
		{
			--pPlayer->tPos.y;
		}

		// �� �бⰡ �����ϰ� �ٷ� ��ĭ�� ���� ���
		else if (pPlayer->bWallpush && Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] == '0')
		{
			// �� �бⰡ ON ������ ���
			if (pPlayer->bPushOnOff)
			{
				//���� ��ĭ�� 0���� ũ�ų� ���� ��� �ε����� �ִٴ� �ǹ�
				if (pPlayer->tPos.y - 2 >= 0)
				{
					// ���� ��ĭ�� ���̾�� �бⰡ �����ϴ�. �׷��Ƿ� ������ üũ�Ѵ�
					if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '0')
					{
						if (pPlayer->bTransparency)
							--pPlayer->tPos.y;
					}

					//���� ��� ���� �о��.
					else if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] = '1')
					{
						// ���� ��ĭ�� ������ �ϰ�
						Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] = '0';
						// ���� ĭ�� ���� ���� ��� ������ش�
						Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] = '1';
						// �÷��̾ �̵���Ų��.
						--pPlayer->tPos.y;
					}
				}
				else if (pPlayer->bTransparency)
					--pPlayer->tPos.y;
			}
			// �� �б� OFF ������ ���
			else if (pPlayer->bTransparency)
				--pPlayer->tPos.y;
		}

		else if (pPlayer->bTransparency)
			--pPlayer->tPos.y;

		if (AddiTtem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';

	}
}

//�Ʒ� �������� ���� �Լ�
void MoveDown(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.y + 1 < 21)
	{
		//������ üũ�Ѵ�.
		if (Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '0' && Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '4')
		{
			++pPlayer->tPos.y;
		}

		// �� �бⰡ �����ϰ� �ٷ� ��ĭ�� ���� ���
		else if (pPlayer->bWallpush && Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] == '0')
		{
			// �� �бⰡ ON ������ ���
			if (pPlayer->bPushOnOff)
			{
				//���� ��ĭ�� 0���� ũ�ų� ���� ��� �ε����� �ִٴ� �ǹ�
				if (pPlayer->tPos.y + 2 < 20)
				{
					// ���� ��ĭ�� ���̾�� �бⰡ �����ϴ�. �׷��Ƿ� ������ üũ�Ѵ�
					if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '0')
					{
						if (pPlayer->bTransparency)
							++pPlayer->tPos.y;
					}

					//���� ��� ���� �о��.
					else if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] = '1')
					{
						// ���� ��ĭ�� ������ �ϰ�
						Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] = '0';
						// ���� ĭ�� ���� ���� ��� ������ش�
						Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] = '1';
						// �÷��̾ �̵���Ų��.
						++pPlayer->tPos.y;
					}
				}
				else if (pPlayer->bTransparency)
					++pPlayer->tPos.y;
			}
			// �� �б� OFF ������ ���
			else if (pPlayer->bTransparency)
				++pPlayer->tPos.y;
		}

		else if (pPlayer->bTransparency)
			++pPlayer->tPos.y;

		if (AddiTtem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';

	}
}

// ���� �������� ���� �Լ�
void MoveLeft(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x - 1 >= 0)
	{
		//������ üũ�Ѵ�.
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '0' && Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '4')
		{
			--pPlayer->tPos.x;
		}
		// �� �бⰡ �����ϰ� �ٷ� ��ĭ�� ���� ���
		else if (pPlayer->bWallpush && Maze[pPlayer->tPos.y ][pPlayer->tPos.x - 1] == '0')
		{
			// �� �бⰡ ON ������ ���
			if (pPlayer->bPushOnOff)
			{
				//���� ��ĭ�� 0���� ũ�ų� ���� ��� �ε����� �ִٴ� �ǹ�
				if (pPlayer->tPos.x - 2 >= 0)
				{
					// ���� ��ĭ�� ���̾�� �бⰡ �����ϴ�. �׷��Ƿ� ������ üũ�Ѵ�
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '0')
					{
						if (pPlayer->bTransparency)
							--pPlayer->tPos.x;
					}

					//���� ��� ���� �о��.
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] = '1')
					{
						// ���� ��ĭ�� ������ �ϰ�
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] = '0';
						// ���� ĭ�� ���� ���� ��� ������ش�
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] = '1';
						// �÷��̾ �̵���Ų��.
						--pPlayer->tPos.x;
					}
				}
				else if (pPlayer->bTransparency)
					--pPlayer->tPos.x;
			}
			// �� �б� OFF ������ ���
			else if (pPlayer->bTransparency)
				--pPlayer->tPos.x;
		}


		else if (pPlayer->bTransparency)
			--pPlayer->tPos.x;

		if (AddiTtem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';

	}
}

//������ �������� ���� �Լ�
void MoveRight(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x + 1 < 20)
	{
		//������ üũ�Ѵ�.
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '0' && Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '4')
		{
			++pPlayer->tPos.x;
		}
		// �� �бⰡ �����ϰ� �ٷ� ��ĭ�� ���� ���
		else if (pPlayer->bWallpush && Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] == '0')
		{
			// �� �бⰡ ON ������ ���
			if (pPlayer->bPushOnOff)
			{
				//���� ��ĭ�� 0���� ũ�ų� ���� ��� �ε����� �ִٴ� �ǹ�
				if (pPlayer->tPos.y + 2 <  20)
				{
					// ���� ��ĭ�� ���̾�� �бⰡ �����ϴ�. �׷��Ƿ� ������ üũ�Ѵ�
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] == '0')
					{
						if (pPlayer->bTransparency)
							++pPlayer->tPos.x;
					}

					//���� ��� ���� �о��.
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] = '1')
					{
						// ���� ��ĭ�� ������ �ϰ�
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] = '0';
						// ���� ĭ�� ���� ���� ��� ������ش�
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] = '1';
						// �÷��̾ �̵���Ų��.
						++pPlayer->tPos.y;
					}
				}
				else if (pPlayer->bTransparency)
					++pPlayer->tPos.x;
			}
			// �� �б� OFF ������ ���
			else if (pPlayer->bTransparency)
				++pPlayer->tPos.x;
		}


		else if (pPlayer->bTransparency)
			++pPlayer->tPos.x;

		if (AddiTtem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';

	}
}


// Ű���� �������� ���� �Լ�
void MovePlayer(char Maze[21][21], PPLAYER pPlayer, char cinput)
{
	switch (cinput)
	{
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayer);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayer);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayer);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayer);
		break;

	}
}


// ������ ������ const�� �����ϸ� ����Ű�� ����� ���� ������ �� �ִ�.

//��ź ��ġ�� ���� �Լ�
void CreatBomb(char Maze[21][21], const PPLAYER pPlayer, PPOINT pBombArr, int* pBombCount)
{
	if (*pBombCount == 5)
		return;

	else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '0')


		for (int i = 0; i < *pBombCount; ++i)
		{
			if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y)
				return;
		}

	pBombArr[*pBombCount] = pPlayer->tPos;
	++(*pBombCount);
	Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '4';
}

//��ź �����°� ó��
void Fire(char Maze[21][21], PPLAYER pPlayer, PPOINT pBombArr, int* pBombCount)
{

	for (int i = 0; i < *pBombCount; ++i)
	{
		Maze[pBombArr[i].x][pBombArr[i].y] = '1';


		//�÷��̾ ��ź�� �¾��� �� ���������� ������
		if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y)
		{
			pPlayer->tPos.x = 0;
			pPlayer->tPos.y = 0;
		}

		for (int j = 1; j <= pPlayer->iBombPower; ++j)
		{
			if (pBombArr[i].y - j >= 0)
			{
				if (Maze[pBombArr[i].y - j][pBombArr[i].x] = '0')

					//������ ��� Ȯ���� ���Ѵ�.
					if (rand() % 100 < 20)
					{

						int iPrecnt = rand() % 100;
						if (rand() % iPrecnt < 70)
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '5';

						else if (rand() % iPrecnt < 80)
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '6';

						else
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '7';
					}

					else
						Maze[pBombArr[i].y - j][pBombArr[i].x] = '1';

				//�÷��̾ ��ź�� �¾��� �� ���������� ������
				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y - j)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}

			//�Ʒ� ��ź
			if (pBombArr[i].y + j < 20)
			{
				if (Maze[pBombArr[i].y + j][pBombArr[i].x] = '0')
				{
					if (rand() % 100 < 20)
					{

						int iPrecnt = rand() % 100;
						if (rand() % iPrecnt < 70)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '5';

						else if (rand() % iPrecnt < 80)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '6';

						else
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '7';
					}

					else
						Maze[pBombArr[i].y + j][pBombArr[i].x] = '1';
				}

				//�÷��̾ ��ź�� �¾��� �� ���������� ������
				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y + j)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}

			//����
			if (pBombArr[i].y - j >= 0)
			{
				if (Maze[pBombArr[i].y][pBombArr[i].x - j] = '0')
				{

					if (rand() % 100 < 20)
					{

						int iPrecnt = rand() % 100;
						if (rand() % iPrecnt < 70)
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '5';

						else if (rand() % iPrecnt < 80)
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '6';

						else
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '7';
					}

					else
						Maze[pBombArr[i].y][pBombArr[i].x - j] = '1';
				}

				//�÷��̾ ��ź�� �¾��� �� ���������� ������
				if (pPlayer->tPos.x == pBombArr[i].x - j && pPlayer->tPos.y == pBombArr[i].y)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}

			//������
			if (pBombArr[i].y + j < 20)
			{
				if (Maze[pBombArr[i].y][pBombArr[i].x + j] = '0')
				{
					if (rand() % 100 < 20)
					{

						int iPrecnt = rand() % 100;
						if (rand() % iPrecnt < 20)
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '5';

						else if (rand() % iPrecnt < 10)
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '6';

						else
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '7';
					}

					else
						Maze[pBombArr[i].y][pBombArr[i].x + j] = '1';
				}

				//�÷��̾ ��ź�� �¾��� �� ���������� ������
				if (pPlayer->tPos.x == pBombArr[i].x + j && pPlayer->tPos.y == pBombArr[i].y)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
		}

	}

	*pBombCount = 0;
}

int main()
{
	srand((unsigned int)time(0));
	// 20X20 �̷θ� ������ش�.
	char strMaze[21][21] = {};

	PLAYER tPlayer = {};
	POINT tStartPos;
	POINT tEndPos;

	tPlayer.iBombPower = 1;

	int iBombCount = 0;
	POINT tBombPos[5];

	// �̷θ� �����Ѵ�.
	SetMaze(strMaze, &tPlayer, &tStartPos, &tEndPos);

	while (true)
	{
		system("cls");
		// �̷θ�  ����Ѵ�.
		OutPut(strMaze, &tPlayer);

		if (tPlayer.tPos.x == tEndPos.x && tPlayer.tPos.y && tEndPos.y)
		{
			cout << "��ǥ������ �����Ͽ����ϴ�" << endl;
			break;
		}

		cout << "t : ��ź��ġ u : ��ź��Ʈ���� i : ���б�ON/OFF" << endl;
		cout << "W : �� S : �Ʒ� A : ���� D : ������ Q : ����";
		char cinput = _getch();

		if (cinput == 'q' || cinput == 'Q')
			break;

		else if (cinput == 't' || cinput == 'T')
			CreatBomb(strMaze, &tPlayer, tBombPos, &iBombCount);

		else if (cinput == 'u' || cinput == 'U')
			Fire(strMaze, &tPlayer, tBombPos, &iBombCount);

		else if (cinput == 'i' || cinput == 'I')
		{
			if (tPlayer.bWallpush)
				tPlayer.bPushOnOff = !tPlayer.bPushOnOff;
		}

		else
			MovePlayer(strMaze, &tPlayer, cinput);

	}
	return 0;
}

