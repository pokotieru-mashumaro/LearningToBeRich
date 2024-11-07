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

void print_int(int i)
{
	std::cout << "print_int" << i << std::endl;
}

void print_str(std::string s)
{
	std::cout << "print_stt" << s << std::endl;
}

template <typename T>
void print_t(T t)
{
	std::cout << "print_t" << t << std::endl;
}

int main(void)
{
	int arr1[4] = {1, 2, 3, 4};
	iter(arr1, 4, print_int);
	iter(arr1, 4, print_t);

    std::cout << "\n--------------------------\n" << std::endl;

	std::string arr2[3] = {"one", "two","three"};
    iter(arr2, 3, print_str);
	iter(arr2, 3, print_t);
}

