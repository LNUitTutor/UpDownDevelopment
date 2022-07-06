#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::ostream;
using std::vector;

// велике число зображено послідовністю цифр
struct LargeNumber
{
	static const int length = 302;
	char m_digits[length];           // масив цифр
	int last;                      // номер останньої цифри
};
// процедура подвоєння великого числа
void MultByTwo(LargeNumber& x);
// процедура виведення великого числа
void Print(const LargeNumber& x);
// програма піднесення 2 до степеня n, 1<=n<=1000
void PowerLast();


// спискова структура для зображення великого числа
struct NumNode
{
	unsigned short num;
	NumNode* link;
	NumNode(unsigned short x, NumNode* p = nullptr) :num(x), link(p) {}
};
// процедура звільнення динамічної пам'яті
void EraseList(NumNode*& x);
// процедура подвоєння великого числа
void MultByTwo(NumNode* x);
// процедура виведення великого числа
void Print(const NumNode* x);
// програма піднесення 2 до степеня n
void PowerByList();



// клас для зображення великого числа
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
