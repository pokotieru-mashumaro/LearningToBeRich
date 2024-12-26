/*
これらの制約を持つプログラムを作成しなければならない：
- プログラム名はRPNです。
- プログラムは逆ポーランドの数式を引数としてとらなければならない。
- この演算で使用され、引数として渡される数値は常に10より小さい。計算自体も結果もこの規則を考慮しない。
- プログラムはこの式を処理し、正しい結果を標準出力に出力しなければなりません。
- プログラムの実行中にエラーが発生した場合は、標準エラーにエラーメッセージを表示しなければならない。
- あなたのプログラムは、これらのトークンを使った演算を処理できなければならない： 「+ - / *」.

括弧や小数点を管理する必要はありません。

$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
$>

メモ：
なぜstackを使うのか？
- 逆ポーランド記法を計算しやすくするため
*/

#include "RPN.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2) 
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    RPN rpn(argv[1]);
    
    return 0;
}
