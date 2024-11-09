/*
さて、もっと深刻なことに移りましょう。何か変なものを作りましょう。
std::stackコンテナはとても良いものです。残念ながら、反復処理ができないSTLコンテナの1つです。それは残念です。
しかし、なぜ私たちはこれを受け入れるのでしょうか？特に、オリジナルのスタックを勝手に改造して、不足している機能を追加できるのであれば。
この不公平を修正するには、std::stackコンテナを反復処理できるようにしなければなりません。
MutantStackクラスを書いてください。これはstd::stackの実装用に作成します。
すべてのメンバ関数に加え、追加機能としてイテレータを提供します。
もちろん、期待通りに動作することを確認するために、独自のテストを書いて提出してください。
MutantStackで初めて実行し、次にMutantStackを例えばstd::listに置き換えて実行すると、2つの出力は同じになるはずです。もちろん、別のコンテナをテストする場合は、対応するメンバ関数で以下のコードを更新してください（push()はpush_back()に置き換えることができます）。

https://teratail.com/questions/315995
*/

#include "MutantStack.hpp"

int	main(void)
{
	std::cout << "<MutantStack>" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "\n<list>" << std::endl;
	{
		std::list<int> list;
		list.push_front(5);
		list.push_front(17);
		std::cout << list.front() << std::endl;
		list.pop_front();
		std::cout << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(list);
	}
	return (0);
}
