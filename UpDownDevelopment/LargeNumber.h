#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::ostream;
using std::vector;

// ������ ����� ��������� ����������� ����
struct LargeNumber
{
	static const int length = 302;
	char m_digits[length];           // ����� ����
	int last;                      // ����� �������� �����
};
// ��������� �������� �������� �����
void MultByTwo(LargeNumber& x);
// ��������� ��������� �������� �����
void Print(const LargeNumber& x);
// �������� ��������� 2 �� ������� n, 1<=n<=1000
void PowerLast();


// �������� ��������� ��� ���������� �������� �����
struct NumNode
{
	unsigned short num;
	NumNode* link;
	NumNode(unsigned short x, NumNode* p = nullptr) :num(x), link(p) {}
};
// ��������� ��������� �������� ���'��
void EraseList(NumNode*& x);
// ��������� �������� �������� �����
void MultByTwo(NumNode* x);
// ��������� ��������� �������� �����
void Print(const NumNode* x);
// �������� ��������� 2 �� ������� n
void PowerByList();



// ���� ��� ���������� �������� �����
class LargePositiveInteger
{
private:
	vector<char> m_digits;
public:
	LargePositiveInteger() { m_digits.push_back(0); }
	LargePositiveInteger& operator=(unsigned);
	LargePositiveInteger& MultByTwo();
	LargePositiveInteger& operator*=(unsigned);
	friend ostream& operator<<(ostream&, const LargePositiveInteger&);
};

void PowerLastest();
