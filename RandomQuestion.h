#ifndef RANDOMQUESTION_H
#define RANDOMQUESTION_H

#include <string>
#include <algorithm>

#include "Number.h"
#include "Random.h"

class RandomQuestion
{
  private:
    std::string question;
    Number answer;

    // 递归随机表达式二叉树
    // opNum为剩余运算符数量, ans为运算结果, op是为了返回当前节点的运算符 (当左子节点运算符优先级小于当前时, 需要加括号)
    std::string binaryRandom(int opNum, Number &ans, int &op);

    // 标识运算符
    enum OPERATOR
    {
        PLUS = 0,
        MINUS = 1,
        MULTIPLY = 2,
        DIVISION = 3,
        NUMBER = 4
    };
    // 四种运算符, 分别设为 + - * /
    static std::string operators[4];

  public:
    /* 构造函数, 随机生成题目, 运算符数量在 [opNum - range, opNum + range] 内随机 */
    RandomQuestion(int opNum = 4, int range = 2);
    const std::string &getQuestion();
    const Number &getAnswer();
};

#endif