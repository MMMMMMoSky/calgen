#include "RandomQuestion.h"
using namespace std;

const string &RandomQuestion::getQuestion()
{
    return question;
}

const Number &RandomQuestion::getAnswer()
{
    return answer;
}

RandomQuestion::RandomQuestion(int opNum, int range)
{
    opNum = Random::randint(opNum - range, opNum + range);
    if (opNum <= 0)
    {
        opNum = 4;
    }

    question = binaryRandom(opNum, answer, -1);
}

std::string RandomQuestion::binaryRandom(int opNum, Number &res, int faLevel)
{
    Number lhs, rhs;
    std::string str;
    int op = Random::randint(0, 3);
    int thisLevel = op >> 1;

    if (opNum == 1)
    {
        lhs = Random::randint(2, 20);   // TODO: 可以设定难度
        rhs = Random::randint(2, 20);
        str = lhs.toString() + RandomQuestion::operators[op] + rhs.toString();
    }
    else
    {
        // 当该节点与其右子节点都是乘/除的时候, 需要把右子节点加括号
        // 因为乘除混合运算不支持结合律
        int left = Random::randint(1, opNum - 1);
        str = binaryRandom(left, lhs, thisLevel) + RandomQuestion::operators[op];
        std::string rightStr = binaryRandom(opNum - left, rhs, thisLevel);
        // 如果右子节点是加减, 那么就已经有括号了   TODO: 这里的写法可以优化
        if (thisLevel == 1 && rightStr[0] != '(')
        {
            str += "(" + rightStr + ")";
        }
        else
        {
            str += rightStr;
        }
    }

    switch (op)
    {
        case PLUS:
            res = lhs + rhs;
            break;
        case MINUS:
            res = lhs - rhs;
            break;
        case MULTIPLY:
            res = lhs * rhs;
            break;
        case DIVISION:
            res = lhs / rhs;
            break;
        default:
            break;
    }

    // 当表达式二叉树的父节点的运算符优先级比该节点高时, 该节点的表达式需要加括号
    if (thisLevel < faLevel)
    {
        str = "(" + str + ")";
    }

    return str;
}

std::string RandomQuestion::operators[4] = {"+", "-", "×", "÷"};