#include "LargeNumber.h"

// ��������� �������� �������� �����
void MultByTwo(LargeNumber& x)
{
	char calc;                        // ��������� �������� ���������
	char transfer = 0;                // ����������� �� �������� �������
	for (int i = 0; i <= x.last; ++i) // ����������� �� ����� �������� �����
	{
		calc = x.m_digits[i] * 2 + transfer;
		x.m_digits[i] = calc % 10;      // ������� ����� ������� ��������
		transfer = calc / 10;         // ������ - ����������
	}
	if (transfer > 0)                 // ����� ����� ��� ������
		x.m_digits[++x.last] = transfer;
}

// ��������� ��������� �������� �����
void Print(const LargeNumber& x)
{
	for (int i = x.last; i >= 0; --i) cout << (int)x.m_digits[i];
	cout << '\n';
}

// �������� ��������� 2 �� ������� n, 1<=n<=1000
void PowerLast()
{
	cout << "* ���������� �������� ������� ����� 2 *\n\n";
	int n;
	cout << "������ n (n<=1000): "; cin >> n;
	LargeNumber x; // ������ ����� �
	// ��������� 2^n � ����� x
	//     ������_�����_x = 1;
	x.last = 0;
	x.m_digits[0] = 1;  // x = 2^0

	for (int k = 1; k <= n; ++k)
	{
		// �������_������_�����(x);
		MultByTwo(x); // x = 2^k
	}
	// x = 2^n
	cout << "2 � ������ " << n << " = ";
	//�����������_������_�����(x);
	Print(x);
}

/* ==================================================================================== */

// ��������� ��������� �������� ���'��
void EraseList(NumNode*& x)
{
	while (x != nullptr)
	{
		NumNode* victim = x;
		x = x->link;
		delete victim;
	}
}
// ��������� �������� �������� �����
void MultByTwo(NumNode* x)
{
	unsigned short calc;
	unsigned short transfer = 0;
	x = new NumNode(0, x);       // ��������� ����� ������� ��� ����������� �����������
	NumNode* curr = x;
	while (curr->link != nullptr)
	{
		calc = curr->link->num * 2 + transfer;
		if (calc < 10000)
		{                        // �� 4 ����� ���������� � ���� �����
			transfer = 0;
			curr->link->num = calc;
		}
		else
		{                        // � ����������� � �������� �����
			transfer = 1;
			curr->link->num = calc % 10000;
		}
		curr = curr->link;
	}
	// ���� �����, ���� ����� ����� ������
	if (transfer > 0) curr->link = new NumNode(1);
	// ��������� ����� ����� �� ������
	delete x;
}
// ��������� ��������� �������� �����
void Print(const NumNode* x)
{
	// ����� ���������� ������ ����� ��������
	NumNode* reverse = nullptr;
	while (x != nullptr)
	{
		reverse = new NumNode(x->num, reverse);
		x = x->link;
	}
	x = reverse;
	cout << x->num; // ���� ������ "�����" ��� ������� ����
	x = x->link;
	char empt = cout.fill('0');
	while (x != nullptr) // ����� "����" ������� �� ������ � � ������
	{
		cout.width(4);
		cout << x->num;
		x = x->link;
	}
	cout << '\n';
	cout.fill(empt); // ��������� ���������� �� �������������
	EraseList(reverse); // ��������� ������ ����� �� �������
}
// �������� ��������� 2 �� ������� n
void PowerByList()
{
	cout << "* ���������� �������� ������� ����� 2 *\n\n";
	int n;
	cout << "������ n: "; cin >> n;
	NumNode* x; // ������ ����� �
	// ��������� 2^n � ����� x
	//     ������_�����_x = 1;
	x = new NumNode(1);  // x = 2^0

	for (int k = 1; k <= n; ++k)
	{
		// �������_������_�����(x);
		MultByTwo(x); // x = 2^k
	}
	// x = 2^n
	cout << "2 � ������ " << n << " = ";
	//�����������_������_�����(x);
	Print(x);
	EraseList(x);
}

/* ==================================================================================== */

LargePositiveInteger& LargePositiveInteger::operator=(unsigned n)
{
	m_digits.clear();
	if (n == 0)	m_digits.push_back(0);
	else
	{
		while (n > 0)
		{
			m_digits.push_back(n % 10);
			n /= 10;
		}
	}
	return *this;
}
LargePositiveInteger& LargePositiveInteger::MultByTwo()
{
	char calc;
	char transfer = 0;
	for (int i = 0; i < m_digits.size(); ++i)
	{
		calc = m_digits[i] * 2 + transfer;
		m_digits[i] = calc % 10;
		transfer = calc / 10;
	}
	if (transfer > 0) m_digits.push_back(transfer);
	return *this;
}
LargePositiveInteger& LargePositiveInteger::operator*=(unsigned n)
{
	if (n == 0) return *this = 0;
	unsigned calc;
	unsigned transfer = 0;
	for (int i = 0; i < m_digits.size(); ++i)
	{
		calc = m_digits[i] * n + transfer;
		m_digits[i] = calc % 10;
		transfer = calc / 10;
	}
	while (transfer > 0)
	{
		m_digits.push_back(transfer % 10);
		transfer /= 10;
	}
	return *this;
}
ostream& operator<<(ostream& os, const LargePositiveInteger& L)
{
	for (int i = L.m_digits.size() - 1; i >= 0; --i) os << (int)L.m_digits[i];
	os << '\n';
	return os;
}

void PowerLastest()
{
	cout << "* ���������� �������� ������� ����� 2 *\n\n";
	int n;
	cout << "������ n: "; cin >> n;
	LargePositiveInteger x; // ������ ����� �
	// ��������� 2^n � ����� x
	//     ������_�����_x = 1;
	x = 1;  // x = 2^0

	for (int k = 1; k <= n; ++k)
	{
		// �������_������_�����(x);
		x.MultByTwo(); // x = 2^k
		// x *= 2;
	}
	// x = 2^n
	//�����������_������_�����(x);
	cout << "2 � ������ " << n << " = " << x;
}
