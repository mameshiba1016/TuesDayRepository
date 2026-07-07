#include <iostream>
#include <cstdlib>
#include <ctime>

void ShowArray(int ary[], int index);
void AddArray(int ary[], int index);

int main(void)
{
	//”z—ñ
	int ary[10];
	srand((unsigned int)time(NULL));

	ShowArray(ary, 10);
	std::cout << "’Ç‰Á:" << std::endl;
	AddArray(ary, 10);
	std::cout << "•\Ž¦:" << std::endl;
	ShowArray(ary, 10);
	return 0;
	
}

void AddArray(int ary[], int index)
{
	for (int i = 0; i < 10; i++)
	{
		ary[i] = rand() % 100;
	}
}