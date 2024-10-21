/*
結局、Animalオブジェクトを作成しても意味がありません。
確かに、音を立てません！
間違いを避けるために、デフォルトの Animal クラスはインスタンス化できないようにすべきです。
誰もインスタンス化できないように、Animal クラスを修正します。すべては以前と同じように動作するはずです。
必要であれば、クラス名を更新して、Animal の前に A 接頭辞を追加します。
*/

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const AAnimal	*meta[6];
	// const AAnimal* animal = new AAnimal();

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

	return 0;
}
