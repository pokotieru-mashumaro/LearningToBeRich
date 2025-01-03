#include "PmergeMe.hpp"

/*
- あなたのプログラムは引数として正の整数列を使用できなければならない。
- あなたのプログラムは、正の整数列をソートするためにマージ・インサート・ソート・アルゴリズムを使わなければならない。
- プログラム実行中にエラーが発生した場合、標準エラーにエラーメッセージが表示されなければならない。

アルゴリズムはコンテナごとに実装することを強く推奨する。

以下は、標準出力に1行ずつ表示すべき情報についての追加ガイドラインである：
- 1行目には、ソートされていない正整数列の後に明示的なテキストを表示しなければならない。
- 2行目には、明示的なテキストの後にソートされた正の整数列を表示しなければなりません。
- 3行目には、正整数列をソートするために使用した最初のコンテナを指定し、アルゴリズムが使用した時間を示す明示的なテキストを表示しなければならない。
- 最後の行には、正整数列のソートに使用した2番目のコンテナを指定して、アルゴリズムで使用した時間を示す明示的なテキストを表示しなければならない。

仕分けに使用した時間の表示形式は自由ですが、使用した2つの容器の違いを明確に確認できる精度を選択する必要があります。
*/

int main(int argc, char **argv) 
{
    if (argc == 1) 
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    PmergeMe pmm(argv);
    
    return 0;
}
