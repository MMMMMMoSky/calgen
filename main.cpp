/**
 * g++ main.cpp Number.cpp Random.cpp RandomQuestion.cpp -o tmp
 */
#include "RandomQuestion.h"
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void printSpeci() //打印标准
{
    cout << " [格式]: -n 题目数量" << endl;
    cout << " [说明]: 命令参数个数为两个，题目数量为大于0且小于等于20的正整数，否则默认为5" << endl;
    cout << " [例子]: -n 10   随机产生10道带括号的四则运算题" << endl;
    exit(0);
}

int extractPara(int argc, char **argv) //解析命令行
{
    string standard = "-n";

    if (argc <= 2)
    {
        return 5;
    }
    if (argv[1] != standard)
    {
        printSpeci();
    }
    if (argc == 3 && stoi(argv[2]) > 0 && stoi(argv[2]) <= 20)
    {
        return stoi(argv[2]);
    }

    printSpeci();
}

int main(int argc, char **argv)
{
    int num = extractPara(argc, argv);
    Number temp;
    float grade = 0;

    cout << "本次共" << num << "道题，满分100分" << endl;

    vector<RandomQuestion> questions;

    for (int i = 0; i < num; i++)
    {
        questions.push_back(RandomQuestion());
    }

    for (int n = 0; n < num; n++)
    {
        cout << n + 1 << ". " << questions[n].getQuestion() << " = ";
        cin >> temp;
        if (temp == questions[n].getAnswer())
        {
            cout << "正确\n\n";
            grade += 1;
        }
        else
        {
            cout << "不正确! 正确答案 = " << questions[n].getAnswer() << "\n\n";
        }
    }

    cout << "本次得分: " << (grade / num) * 100 << "分" << endl;
    return 0;
}
