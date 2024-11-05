/*
3つのパラメーターを受け取り、何も返さない関数テンプレートiterを実装する。
- 最初のパラメータは配列のアドレス。
- 2番目のパラメータは配列の長さ。
- 3番目のパラメータは配列の各要素に対して呼び出される関数である。
テストを含む main.cpp ファイルを提出する。テストの実行ファイルを生成するのに十分なコードを用意してください。
iter関数のテンプレートは、どのタイプの配列でも動作するものでなければなりません。
第3引数には、インスタンス化された関数テンプレートを指定します。
*/

#include "iter.hpp"

template <typename T>
T iter(T& x, T& y)
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