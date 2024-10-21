/*
各クラスのコンストラクタとデストラクタは、特定のメッセージを表示しなければなりません。
Brainクラスを実装します。
このクラスには、ideasという名前の100個のstd::stringの配列が含まれます。
これにより、DogとCatはBrain*のプライベート属性を持つことになります。
DogとCatは、作成時にnew Brain();を使用してBrainを作成します。
DogとCatは、破棄時にBrainを削除します。

main関数で、Animalオブジェクトの配列を作成し、その配列にデータを入れます。
配列の半分はDogオブジェクト、残りの半分はCatオブジェクトです。
プログラムの実行が終了したら、この配列をループ処理してすべての Animal を削除します。
犬と猫は直接 Animal として削除しなければなりません。
適切なデストラクタが想定通りの順序で呼び出されるようにしなければなりません。メモリリークのチェックも忘れないでください。

Dog や Cat のコピーはシャローコピーであってはなりません。したがって、コピーがディープコピーであることを確認する必要があります。
*/

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal	*meta[6];

    for (int i = 0; i < 6; i++)
	{
		if (i < 3)
		{
			meta[i] = new Dog();
			if (meta[i] == NULL)
				return(1);
		}
		else
		{
			meta[i] = new Cat();
			if (meta[i] == NULL)
				return(1);
		}
	}

	std::cout << std::endl;
    for (int i = 0; i < 6; i++)
		delete(meta[i]);

	std::cout << std::endl;

    //ディープコピー確認
    Dog *a = new Dog();
    // Cat *a = new Cat();
    if (a == NULL)
        return 1;

	a->setIdea(0, "私は");
	a->setIdea(1, "犬です");

    Dog *b = new Dog(*a);
    // Cat *b = new Cat(*a);
    a->getIdea(0);
    a->getIdea(1);
    a->getIdea(10);
    a->getIdea(1000);
    b->getIdea(0);
    b->getIdea(1);
    b->getIdea(10);
    b->getIdea(1000);

	std::cout << std::endl;

    delete(a);
    delete(b);

    return (0);
}
