/*
パブリックな仮想デストラクタのみを持つベースクラスを実装します。 ベースをパブリックに継承する空のクラスA、B、Cの3つを作成します。

これら4つのクラスは、正統派のカノニカルフォームで設計する必要はありません。

以下の関数を実装します。
  Base * generate(void);
A、B、またはCをランダムにインスタンス化し、そのインスタンスをBaseポインタとして返します。 ランダムな選択の実装には、お好きなものをお使いください。

  void identify(Base* p);
p が指すオブジェクトの実際の型を「A」、「B」、または「C」と表示します。

  void identify(Base& p);
p が指すオブジェクトの実際の型を「A」、「B」、または「C」と表示します。この関数内でポインタを使用することは禁止されています。

typeinfo ヘッダを含めることは禁止されています。
期待通りに動作することを確認するためのプログラムを作成してください。
*/

#include "Base.hpp"

Base * generate(void)
{
  switch (rand() % 3)
  {
    case 0:
		  return (new A());
		  break;
	  case 1:
		  return (new B());
		  break;
	  case 2:
		  return (new C());
		  break;
	  default:
		  perror("こんなことはありえない");
		  return (NULL);
	}
}

void identify(Base* p)
{

}

void identify(Base& p)
{

}

int main()
{
  return 0;
}
