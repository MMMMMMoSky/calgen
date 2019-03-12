/**
 * g++ TEST_RandomQuestion.cpp RandomQuestion.cpp Number.cpp Random.cpp -o tmp
 * 不要修改输出格式! 使用TEST_ASSERT_RandomQuestion.py来测试
 */
#include "RandomQuestion.h"
#include <fstream>
using namespace std;

int main()
{
    // Number a = 19, b = 17, c = 12;
    // cout << a - b + c << endl;
    ofstream fout("tmp.txt");
    for (int i = 0; i < 100; i++)
    {
        RandomQuestion q;
        fout << q.getQuestion() << " ";
        fout << q.getAnswer() << endl;
    }
    fout.close();
    return 0;
}