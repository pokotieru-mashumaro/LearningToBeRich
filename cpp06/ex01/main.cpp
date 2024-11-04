/*
ユーザーによる初期化が一切できないシリアライザクラスを実装し、以下の静的メソッドを追加します。

uintptr_t serialize(Data* ptr);
これはポインタを受け取り、それを符号なし整数型 uintptr_t に変換します。

Data* deserialize(uintptr_t raw);
これは符号なし整数パラメータを受け取り、それを Data へのポインタに変換します。

作成したクラスが期待通りに動作することを確認するためのプログラムを作成してください。
空ではない（つまりデータ・メンバを持つ）データ構造を作成する必要があります。
Data オブジェクトのアドレスに対して serialize() を使用し、その戻り値を deserialize() に渡します。次に、deserialize() の戻り値が元のポインタと等しいことを確認します。
データ構造のファイルを提出することを忘れないでください。
*/

# include "Serializer.hpp"

int main()
{
	Data data1 = {"kkomatsu"};
	uintptr_t ptr;

	std::cout << "nomal ptr = " << &data1 << std::endl;
	std::cout << "name = " << data1.name << std::endl << std::endl;

	ptr = Serializer::serialize(&data1);
	std::cout << "serialize ptr = " << ptr << std::endl << std::endl;

	Data *data2 = new Data;
	data2 = Serializer::deserialize(ptr);
	std::cout << "deserialize ptr = " << data2 << std::endl;
	std::cout << "name = " << data2->name << std::endl << std::endl;

}
