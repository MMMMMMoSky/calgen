/**
 * 单元测试 Number类
 * g++ Number.cpp TEST_Number.cpp -o tmp
 */
#include "Number.h"
#include <sstream>
using namespace std;

int main()
{
    // 测试构造函数和输出
    Number a1(5, 10);
    cout << a1 << endl;
    // Number a2(10, 0);
    // cout << a2 << endl;

    // 测试输入输出
    Number a2(1, 2), b2;
    stringstream strin("123/456 abc");
    strin >> a2 >> b2;
    cout << a2 << " " << b2 << endl;

    Number aa = 1;    // 隐式调用了构造函数

    // 测试加减乘除
    Number a(15, 20), b(17, 28);
    // Number a(1, 2), b(1, 3);

    cout << a << " " << b << endl;

    a = a * b;
    cout << a << endl;
    a = a / b;
    cout << a << endl;
    a = a + b;
    cout << a << endl;
    a = a - b;
    cout << a << endl;

    cout << (a == 1) << endl;
    cout << (a <= 1) << endl;
    cout << (a > 1) << endl;
    cout << (1 == a) << endl;
    cout << (1 <= a) << endl;
    cout << (1 > a) << endl;
    cout << (a == a) << endl;
    cout << (a <= a) << endl;
    cout << (a > a) << endl;

    return 0;
}