#include "LargeNumber.h"
#include <Windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	PowerLast();
	system("pause");
	PowerByList();
	system("pause");
	PowerLastest();
	system("pause");
	unsigned n;
	cout << " ? n: "; cin >> n;
	LargePositiveInteger L;
	L = 1;
	for (unsigned i = 2; i <= n; ++i) L *= i;
	cout << n << "! = " << L;
	system("pause");
	return 0;
}