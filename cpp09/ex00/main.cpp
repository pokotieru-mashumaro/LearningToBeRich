/*
プログラムは2つ目のデータベースを入力とし、評価する異なる価格/日付を保存します。

あなたのプログラムはこれらのルールを尊重しなければならない：
- プログラム名はbtcとする。
- プログラムはファイルを引数に取る。
- このファイルの各行は以下の書式でなければならない： 「日付｜値」。
- 有効な日付は常に以下のフォーマットである： 年-月-日。
- 有効な値は、0から1000の間の浮動小数点数か正の整数でなければなりません。
この演習を検証するために、コードの中で少なくとも1つのコンテナを使用しなければなりません。 起こりうるエラーは適切なエラーメッセージで処理してください。

あなたのプログラムは、データベースに示された日付に従って、値に為替レートを掛けた結果を標準出力に表示しなければなりません。

入力で使用された日付が DB に存在しない場合は、DB に含まれる最も近い日付を使用しなければなりません。上の日付ではなく、下の日付を使うように注意してください。

おかしい！！
小数第2位で四捨五入してしまう

メモ：
なぜmapを使うのか？
- 日付をキーにして、値を取得するため
*/

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        BitcoinExchange btc(argv[1]);
        // btc.displayPrice();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
