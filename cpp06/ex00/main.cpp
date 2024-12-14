/*
ScalarConverterクラスを作成し、最も一般的な形式のC++リテラルの文字列表現をパラメータとして受け取り、以下のスカラー型でその値を出力する、1つの静的メソッド「convert」のみを含むようにします。
• char
• int
• float
• double
このクラスは何も保存する必要がないため、ユーザーによるインスタンス化はできません。
charパラメータを除き、10進表記のみを使用します。

文字リテラルの例：’c’, ’a’, ...
単純化のため、表示不可能な文字は入力として使用しないでください。charへの変換が不可能な場合は、情報メッセージを表示します。

intリテラルの例：0, -42, 42...
floatリテラルの例：0.0f, -4.2f, 4.2f...
疑似リテラルも処理する必要があります（科学のためです）。-inff、+inff、nanf。
倍精度リテラルの例：0.0、-4.2、4.2...
疑似リテラルも処理する必要があります（娯楽のためです）。-inf、+inf、nan。

自分のクラスが期待通りに動作することを確認するためのプログラムを作成してください。

変換が意味をなさない場合やオーバーフローが発生する場合は、型変換が不可能であることをユーザーに通知するメッセージを表示します。数値の制限や特殊な値を処理するために必要なヘッダーをすべて含めます。
まず、パラメータとして渡されたリテラルの型を検出し、文字列から実際の型に変換し、その後、他の3つのデータ型に明示的に変換する必要があります。最後に、以下のように結果を表示します。
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
*/

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	ScalarConverter::convert(av[1]);
	return 0;
}
