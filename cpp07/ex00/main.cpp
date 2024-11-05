/*
以下の関数テンプレートを実装する：
- swap： 与えられた2つの引数の値を入れ替えます。何も返さない。
- min：引数に渡された2つの値を比較し、最も小さいものを返す。2つの値が等しい場合は、2番目の値を返す。
- max：最大値： 引数に渡された2つの値を比較し、最大のものを返す。2つの値が等しい場合は、2番目の値を返す。
これらの関数は、どのようなタイプの引数でも呼び出すことができます。唯一の条件は、2つの引数が同じ型であり、すべての比較演算子をサポートしていることです。

テンプレートはヘッダーファイルで定義しなければならない。
*/

#include "whatever.hpp"

template <typename T>
void swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>
T min(T& x, T& y)
{
    return (x > y) ? y : x;
}

template <typename T>
T max(T& x, T& y)
{
    return (x > y) ? x : y;
}

int main(void)
{
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    return 0;
}