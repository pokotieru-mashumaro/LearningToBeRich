/*
各クラスのコンストラクタとデストラクタは、特定のメッセージを表示しなければなりません。
Brainクラスを実装します。
このクラスには、ideasという名前の100個のstd::stringの配列が含まれます。
これにより、DogとCatはBrain*のプライベート属性を持つことになります。
DogとCatは、作成時にnew Brain();を使用してBrainを作成します。
DogとCatは、破棄時にBrainを削除します。main関数で、Animalオブジェクトの配列を作成し、その配列にデータを入れます。
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
    {
        std::cout << "Animal -----------------------\n" << std::endl;

        const Animal *ani = new Animal();
        const Animal *j = new Dog();

        const Animal *i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        ani->makeSound();

        delete ani;
        delete j;
        delete i;
    }
    std::cout << std::endl;
    {
        std::cout << "\n\nWrongAnimal -----------------------\n" << std::endl;

        const WrongAnimal *ani = new WrongAnimal();
        const Animal *j = new Dog();

        const WrongAnimal *i = new WrongCat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        ani->makeSound();

        delete ani;
        delete j;
        delete i;
    }
    return (0);
}
