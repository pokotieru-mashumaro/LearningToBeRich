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
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 3); 

	int num = dist(gen);

	switch (num % 3)
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
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "こんなことはありえない" << std::endl;
}

void identify(Base& p)
{
    try {
        A& a = dynamic_cast<A&>(p);
		(void) a;
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        B& b = dynamic_cast<B&>(p);
		(void) b;
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        C& c = dynamic_cast<C&>(p);
		(void) c;
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    std::cout << "こんなことはありえない" << std::endl;
}

int main()
{
	Base *base = generate();
	A a;
	B b;
	C c;

	identify(base);
	identify(*base);
	identify(&a);
	identify(a);
	identify(&b);
	identify(b);
	identify(&c);
	identify(c);
  return 0;
}
