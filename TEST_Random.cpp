#include "Random.h"
#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 100; i++)
    // while (1)
        cout << Random::randint(-2147483648, 2147483647) << endl;
    // for (int i = 0; i < 100; i++)
    //     cout << Random::randint(2147483647) << endl;
    // for (int i = 0; i < 100; i++)
    //     cout << Random::randint() << endl;
}