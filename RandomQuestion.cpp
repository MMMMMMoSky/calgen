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

    int tmp;
    question = binaryRandom(opNum, answer, tmp);
}

std::string RandomQuestion::binaryRandom(int opNum, Number &ans, int &op)
{
    if (opNum == 0)
    {
        ans = Random::randint(2, 20); // TODO: 添加难度设定 有不同的数字范围
        op = NUMBER;
        return ans.toString();
    }

    Number lhsAns, rhsAns;
    std::string lhsStr, rhsStr;              // 左右子树对应的表达式 (这种写法牺牲了一点效率, 换来易读性)
    op = Random::randint(0, 3);              // 随机选择运算符 TODO: 添加难度设定 选定运算符
    int lhsOp, rhsOp;                        // 左右子树的运算符
    int lft = Random::randint(0, opNum - 1); // 随机生成左子树运算符数量
    lhsStr = binaryRandom(lft, lhsAns, lhsOp);
    rhsStr = binaryRandom(opNum - lft - 1, rhsAns, rhsOp);

    // 给左右子树加括号
    if (op == MULTIPLY || op == DIVISION) // 该节点是乘除时, 右子节点不为数字则要加括号, 左子节点为加减也要加括号
    {
        if (lhsOp == PLUS || lhsOp == MINUS)
        {
            lhsStr = "(" + lhsStr + ")";
        }
        if (rhsOp != NUMBER)
        {
            rhsStr = "(" + rhsStr + ")";
        }
    }

    switch (op)
    {
        case PLUS:      ans = lhsAns + rhsAns; break;
        case MINUS:     ans = lhsAns - rhsAns; break;
        case MULTIPLY:  ans = lhsAns * rhsAns; break;
        case DIVISION:  ans = lhsAns / rhsAns; break;
        default: break;
    }

    return lhsStr + operators[op] + rhsStr;
}

// std::string RandomQuestion::operators[4] = {"+", "-", "×", "÷"};
std::string RandomQuestion::operators[4] = {"+", "-", "*", "/"};    // 纯ASCII字符, 方便用py验证结果