/*
https://docs.oracle.com/cd/E19957-01/805-7887/6j7dsdheo/index.html

型Tの要素を含み、以下の動作と関数を実装するクラス・テンプレートArrayを 開発しなさい：
パラメータなしの構築： 空の配列を作成する。
符号なし int n をパラメータとする構成： ヒント： int * a = new int(); をコンパイルしてから *a を表示してみてください。
コピーと代入演算子による構築。どちらの場合も、コピー元の配列やコピー後の配列を変更しても、もう一方の配列には影響しません。
メモリを確保するには、必ずnew[]演算子を使わなければならない。予防的割り当て（事前にメモリーを探しておくこと）は禁止されています。プログラムは、決して割り当てられていないメモリにアクセスしてはならない。
要素は添え字演算子を使ってアクセスできます： [ ].
演算子 [ ] で要素にアクセスするとき、そのインデックスが範囲外の場合は std::exception がスローされます。
メンバ関数 size() は、配列の要素数を返します。このメンバ関数はパラメータを取らず、現在のインスタンスを変更してはいけません。いつものように、すべてが期待通りに動作することを確認し、テストを含むmain.cppファイルを提出してください。
*/

// TODO: check copy and = 

/*

メモ

macだと45~49のコードでコピーコンストラクタと代入演算子がどちらも呼び出されてしまう。
校舎のlinuxで要検討



*/

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 10

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    numbers.display_array();
    {
        Array<int> tmp = numbers;
        tmp.display_array();

        Array<int> test(tmp);
        test.display_array();
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}