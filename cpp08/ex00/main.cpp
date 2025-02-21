/*
最初の簡単な練習は、正しいスタートを切るための方法である。
型Tを受け入れる関数テンプレートeasyfindを書く。これは2つのパラメータを受け取ります。
最初のパラメータはT型で、2番目のパラメータは整数です。
Tが整数のコンテナであると仮定すると、この関数は2番目のパラメータが1番目のパラメータの中で最初に現れるものを見つけなければなりません。
を見つけなければならない。
もし見つからない場合は、例外をスローするか、任意のエラー値を返すことができる。ヒントが必要なら、標準的なコンテナがどのように振る舞うかを分析してみよう。
もちろん、すべてが期待通りに動くことを確認するために、独自のテストを実装して提出すること。

連想コンテナを扱う必要はない。
*/

#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
    std::vector<int> vec;
    std::list<int> lst;
    
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
        lst.push_back(i);
    }

    try
    {
        easyfind(vec, 0);
        easyfind(vec, 9);
        easyfind(lst, 5);
        easyfind(vec, -1);
        easyfind(lst, 10);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
