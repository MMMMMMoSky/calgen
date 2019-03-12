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
    int lhsOp, rhsOp;                        // 左右子树的运算符
    int lft = Random::randint(0, opNum - 1); // 随机生成左子树运算符数量
    lhsStr = binaryRandom(lft, lhsAns, lhsOp);
    rhsStr = binaryRandom(opNum - lft - 1, rhsAns, rhsOp);

    if (rhsAns == 0) // 避免除数为零
    {
        op = Random::randint(0, 2);
    }
    else
    {
        op = Random::randint(0, 3); // 随机选择运算符 TODO: 添加难度设定 选定运算符
    }

    // 因为"数字"在枚举中设定的优先级比较高, 所以无需在条件中写 lhsOp != NUMBER
    // 当op优先级大于左子节点优先级时, 左子树需要加括号
    if (op / 2 > lhsOp / 2)
    {
        lhsStr = "(" + lhsStr + ")";
    }
    // 当op优先级不小于右子节点优先级时, 右子树需要加括号
    if (op / 2 >= rhsOp / 2)
    {
        rhsStr = "(" + rhsStr + ")";
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

std::string RandomQuestion::operators[4] = {"+", "-", "×", "÷"};
// std::string RandomQuestion::operators[4] = {"+", "-", "*", "/"};    // 纯ASCII字符, 方便用py验证结果