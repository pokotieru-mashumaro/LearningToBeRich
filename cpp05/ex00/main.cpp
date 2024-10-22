/*
例外クラスは正統派正規形に従って設計する必要はないことにご注意ください。しかし、その他のクラスはすべてそうしなければなりません。

オフィス、廊下、フォーム、待ち行列といった、悪夢のような人工的なものを設計してみましょう。面白そうですか？面白くないですか？残念です。
まず、この巨大な官僚的機械の最小の歯車である「官僚」から始めましょう。

官僚には、以下のものが必要です。
• 固定の名前。
• 1（最高ランク）から150（最低ランク）までのランク。

無効なグレードを使用して官僚をインスタンス化しようとすると、例外が発生しなければなりません。
Bureaucrat::GradeTooHighException または Bureaucrat::GradeTooLowException のいずれかの例外が発生します。
これらの属性、getName() と getGrade() の両方に対してゲッターを用意します。 また、官僚のグレードをインクリメントまたはデクリメントする2つのメンバー関数も実装します。 グレードが範囲外の場合、両方ともコンストラクタと同じ例外が発生します。
覚えておいてください。等級1が最高で、150が最低であるため、等級3を上げる場合は、官僚に等級2を与えることになります。
スローされた例外は、tryとcatchブロックを使用してキャッチ可能でなければなりません。
挿入（«）演算子のオーバーロードを実装して、次のようなものを表示します（角カッコは使用しません）。
名前>、官僚の等級>。
通常通り、いくつかのテストを提出して、すべてが期待通りに動作することを証明します。
*/

#include "Bureaucrat.hpp"

int main()
{
    try {
		Bureaucrat	bob("bob", 1);
		std::cout << bob;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// try {
	// 	Bureaucrat	ooo("ooo", -42);
	// 	std::cout << ooo;
	// }
	// catch (std::exception& e) {
	// 	std::cout << "Error: " << e.what() << std::endl;
	// }

    try {
		Bureaucrat	hima("hima", 150);
        // hima.decrementGrade();
		std::cout << hima;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

    return 0;
}