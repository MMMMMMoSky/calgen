#include "Number.h"

Number::Number(int number)
{
    *this = number;
}

Number::Number(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
    Number::regularize(*this);
}

int Number::gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void Number::regularize(Number &n)
{
    if (n.denominator == 0)
    {
        std::cout << "Error: Denominator of a factor can not be zero.";
        exit(0);
    }

    if (n.denominator < 0)
    {
        n.denominator = -n.denominator;
        n.numerator = -n.denominator;
    }

    int gcd = Number::gcd(abs(n.numerator), n.denominator);
    n.denominator /= gcd;
    n.numerator /= gcd;
}

std::ostream &operator<<(std::ostream &out, const Number &n)
{
    out << n.numerator;
    if (n.denominator > 1)
    {
        out << "/" << n.denominator;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Number &n)
{
    std::string tmp;
    in >> tmp;
    int idx = tmp.find('/');
    try
    {
        if (idx == tmp.npos)
        {
            n.numerator = std::stoi(tmp);
            n.denominator = 1;
        }
        else
        {
            n.numerator = std::stoi(tmp.substr(0, idx));
            n.denominator = std::stoi(tmp.substr(idx + 1));
            Number::regularize(n);
        }
    }
    catch (std::invalid_argument) // 异常: 输入的字符串含有 除数字和'/'之外的字符
    {
        n.numerator = 0;
        n.denominator = 1;
    }
    return in;
}

const Number &Number::operator+=(const Number &rhs)
{
    int gcd = Number::gcd(denominator, rhs.denominator);
    numerator *= rhs.denominator / gcd;
    numerator += rhs.numerator * (denominator / gcd); // 加括号, 先算除法, 减小溢出可能性
    denominator *= rhs.denominator / gcd;
    Number::regularize(*this);
    return *this;
}

const Number &Number::operator+(const Number &rhs) const
{
    Number ret = *this;
    return ret += rhs;
}

const Number &Number::operator-=(const Number &rhs)
{
    int gcd = Number::gcd(denominator, rhs.denominator);
    numerator *= rhs.denominator / gcd;
    numerator -= rhs.numerator * (denominator / gcd); // 加括号, 先算除法, 减小溢出可能性
    denominator *= rhs.denominator / gcd;
    Number::regularize(*this);
    return *this;
}

const Number &Number::operator-(const Number &rhs) const
{
    Number ret = *this;
    return ret -= rhs;
}

const Number &Number::operator*=(const Number &rhs)
{
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    Number::regularize(*this);
    return *this;
}

const Number &Number::operator*(const Number &rhs) const
{
    Number ret = *this;
    return ret *= rhs;
}

const Number &Number::operator/=(const Number &rhs)
{
    numerator *= rhs.denominator;
    denominator *= rhs.numerator;
    Number::regularize(*this);
    return *this;
}

const Number &Number::operator/(const Number &rhs) const
{
    Number ret = *this;
    return ret /= rhs;
}

Number Number::operator-(void) const
{
    Number ret = *this;
    ret.numerator = -ret.numerator;
    return ret;
}

bool Number::operator<(const Number &rhs) const
{
    return numerator * rhs.denominator < denominator * rhs.numerator; // TODO 溢出警告 但是比较小的数字够用, 至少对于calgen够用
}

bool Number::operator<=(const Number &rhs) const
{
    return numerator * rhs.denominator <= denominator * rhs.numerator;
}

bool Number::operator>(const Number &rhs) const
{
    return numerator * rhs.denominator > denominator * rhs.numerator;
}

bool Number::operator>=(const Number &rhs) const
{
    return numerator * rhs.denominator >= denominator * rhs.numerator;
}

bool Number::operator==(const Number &rhs) const
{
    return numerator == rhs.numerator && denominator == rhs.denominator;
}

bool Number::operator<(int rhs) const
{
    return numerator < denominator * rhs;
}

bool Number::operator<=(int rhs) const
{
    return numerator <= denominator * rhs;
}

bool Number::operator>(int rhs) const
{
    return numerator > denominator * rhs;
}

bool Number::operator>=(int rhs) const
{
    return numerator >= denominator * rhs;
}

bool Number::operator==(int rhs) const
{
    return numerator == denominator * rhs;
}

int Number::getDenominator() const
{
    return denominator;
}

int Number::getNumerator() const
{
    return numerator;
}

const Number &Number::operator=(const Number &rhs)
{
    numerator = rhs.numerator;
    denominator = rhs.denominator;
}

const Number &Number::operator=(int rhs)
{
    numerator = rhs;
    denominator = 1;
}

bool operator<(int lhs, const Number &rhs)
{
    return lhs * rhs.getDenominator() < rhs.getNumerator();
}

bool operator>(int lhs, const Number &rhs)
{
    return lhs * rhs.getDenominator() > rhs.getNumerator();
}

bool operator<=(int lhs, const Number &rhs)
{
    return lhs * rhs.getDenominator() <= rhs.getNumerator();
}

bool operator>=(int lhs, const Number &rhs)
{
    return lhs * rhs.getDenominator() >= rhs.getNumerator();
}

bool operator==(int lhs, const Number &rhs)
{
    return lhs * rhs.getDenominator() == rhs.getNumerator();
}

std::string Number::toString() const
{
    std::string ret = std::to_string(numerator);
    if (denominator > 1)
    {
        ret += "/" + std::to_string(denominator);
    }
    return ret;
}