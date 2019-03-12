/**
 * g++ main.cpp Number.cpp Random.cpp RandomQuestion.cpp -o tmp
 */
#include "RandomQuestion.h"
#include <vector>
using namespace std;

int extractPara(int argc, char **argv)
{
    // TODO 解析命令行参数
}

int main(int argc, char **argv)
{
    int num = extractPara(argc, argv);

    vector<RandomQuestion> questions;
    for (int i = 0; i < num; i++)
    {
        questions.push_back(RandomQuestion());
    }

    // 下面进入用户交互
    // TODO 编写交互
    return 0;
}