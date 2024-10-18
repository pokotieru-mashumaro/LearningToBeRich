/*
すべての演習において、可能な限り最も完全なテストを提供する必要があります。
各クラスのコンストラクタとデストラクタは、特定のメッセージを表示しなければなりません。
すべてのクラスに同じメッセージを使用しないでください。まずは、単純な基本クラスである Animal を実装します。
このクラスには、1つのプロテクト属性があります。
std::string type;

Dog クラスを実装し、Animal クラスを継承します。
Cat クラスを実装し、Animal クラスを継承します。

これらの2つの派生クラスは、それぞれの名前に応じてtypeフィールドを設定する必要があります。
これにより、Dogのtypeは「Dog」に初期化され、Catのtypeは「Cat」に初期化されます。
Animalクラスのtypeは空欄のままにしておくこともできますし、お好みの値を設定することもできます。

すべての動物は、メンバー関数を使用できなければなりません。
makeSound()
これは適切な音を鳴らします（猫は吠えません）。

このコードを実行すると、DogとCatクラスの特定のサウンドが鳴り、Animalのサウンドは鳴らないはずです。

動作を理解したことを確認するために、WrongCatクラスをWrongAnimalクラスから継承する形で実装します。
上記のコードでAnimalとCatを間違ったものに置き換えると、WrongCatはWrongAnimalのサウンドを出力するはずです。

上記のテストよりも多くのテストを実装し、提出してください。
*/

#include "Animal.hpp"

int main()
{
// const Animal* meta = new Animal();
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
// i->makeSound(); //will output the cat sound!
// j->makeSound();
// meta->makeSound();
// ...
return 0;
}