/*
最大N個の整数を格納できるSpan クラスを開発しなさい。
N は符号なし int 変数で、コンストラクタに渡される唯一のパラメータである。

このクラスはaddNumber()というメンバ関数を持ち、Spanに1つの数値を追加する。
これは、スパンを埋めるために使用されます。
すでに N 個の要素が格納されている場合に新しい要素を追加しようとすると、例外がスローされます。

次に、2つのメンバ関数を実装します。

これらはそれぞれ、格納されているすべての数値の間の最短スパンまたは最長スパン（お望みなら距離）を求め、それを返す。
格納されている数値がない場合、または1つしかない場合は、スパンを見つけることはできません。
したがって、例外を投げる。

もちろん、あなた自身のテストを書くでしょうし、それは以下のものよりもずっと綿密なものになるでしょう。最低でも10,000個の数字を使ってスパンをテストしてください。もっと多ければなおよい。

最後になるが、イテレータの範囲を使ってSpanを埋めることができたら素晴らしいだろう。
addNumber()を何度も呼び出すのはとても面倒です。
メンバ関数を実装して、1回の呼び出しで多くの数値をSpanに追加できるようにしましょう。

ヒントがない場合は、コンテナを研究してください。 いくつかのメンバ
関数の中には、コンテナに一連の要素を追加するために、イテレータの範囲を取るものがある。
要素をコンテナに追加する。
*/

#include "Span.hpp"

int main()
{
    {
        Span sp = Span(5);

        try
        {
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
            sp.display_arr();
        }
        catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    {
        Span sp = Span(100);

        try
        {
            sp.addNumbers(100);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
            // sp.display_arr();
        }
        catch(const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
        
    }

    return 0;
}