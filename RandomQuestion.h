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
    // opNum为剩余运算符数量, res为运算结果, faLevel为父节点的运算符优先级(+-为0, */为1)
    std::string binaryRandom(int opNum, Number &res, int faLevel);

    // 标识运算符
    enum OPERATOR {PLUS = 0, MINUS = 1, MULTIPLY = 2, DIVISION = 3};
    // 四种运算符, 分别设为 + - * / (因而计算优先级可以直接用枚举值/2)
    static std::string operators[4];

  public:
    /* 构造函数, 随机生成题目, 运算符数量在 [opNum - range, opNum + range] 内随机 */
    RandomQuestion(int opNum = 4, int range = 2);
    const std::string &getQuestion();
    const Number &getAnswer();
};

#endif