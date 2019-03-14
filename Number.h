#ifndef NUMBER_H
#define NUMBER_H

#include <cmath>
#include <string>
#include <iostream>

class Number; // 前置声明, 用于友元函数的声明

/**
 * 分数运算
 */

class Number
{
  private:
    int numerator;   // 分子
    int denominator; // 分母, 取值范围[1, MAX_INT]

    static void regularize(Number &n); // 约分, 并保证分母为正

    static int gcd(int a, int b); // 辗转相除求最大公约数, 用于约分

  public:
    /* 构造函数 */
    Number(int number = 0);
    Number(int numerator, int denominator);

    std::string toString() const; // 转换成字符串

    /* 获取私有成员变量 */
    int getNumerator() const;
    int getDenominator() const;

    /* 重载算术运算符 */
    const Number operator+(const Number &rhs) const;
    const Number operator-(const Number &rhs) const;
    const Number operator*(const Number &rhs) const;
    const Number operator/(const Number &rhs) const;

    /* 重载负号 */
    Number operator-(void) const;

    /* 重载赋值运算符 */
    const Number &operator+=(const Number &rhs);
    const Number &operator-=(const Number &rhs);
    const Number &operator*=(const Number &rhs);
    const Number &operator/=(const Number &rhs);
    const Number &operator=(const Number &rhs);
    const Number &operator=(int rhs);

    /* 重载比较运算符 */
    bool operator<(const Number &rhs) const;
    bool operator>(const Number &rhs) const;
    bool operator<=(const Number &rhs) const;
    bool operator>=(const Number &rhs) const;
    bool operator==(const Number &rhs) const;
    bool operator<(int rhs) const;
    bool operator>(int rhs) const;
    bool operator<=(int rhs) const;
    bool operator>=(int rhs) const;
    bool operator==(int rhs) const;

    /* 定义输入输出流 */
    friend std::ostream &operator<<(std::ostream &out, const Number &n);
    friend std::istream &operator>>(std::istream &in, Number &n);
};

/* 重载 int op Number 的运算符以支持 1 < Number(2) 这样的写法 */
bool operator<(int lhs, const Number &rhs);
bool operator>(int lhs, const Number &rhs);
bool operator<=(int lhs, const Number &rhs);
bool operator>=(int lhs, const Number &rhs);
bool operator==(int lhs, const Number &rhs);

#endif