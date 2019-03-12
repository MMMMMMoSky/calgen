/**
 * g++ TEST_RandomQuestion.cpp RandomQuestion.cpp Number.cpp Random.cpp -o tmp
 */
#include "RandomQuestion.h"
using namespace std;

int main()
{
    RandomQuestion q;
    cout << q.getQuestion() << endl;
    cout << q.getAnswer() << endl;
    return 0;
}