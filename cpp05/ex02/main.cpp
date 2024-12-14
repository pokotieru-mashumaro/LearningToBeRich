/*
基本フォームが揃ったので、今度は実際に何かを行うフォームをいくつか作成します。
いずれの場合も、基本クラス Form は抽象クラスでなければなりません。そのため、AForm に名前を変更する必要があります。フォームの属性はプライベートにしておく必要があり、それらは基本クラスにあることを念頭に置いてください。
以下の具体的なクラスを追加します。

• ShrubberyCreationForm: 必要な評点: サイン 145、実行 137
作業ディレクトリにファイル <target>_shrubbery を作成し、その中に ASCII ツリーを書き込みます。

• RobotomyRequestForm: 必要な評点: サイン 72、実行 45
ドリル音を鳴らします。その後、50% の確率で <target> が正常にロボット化されたことを通知します。それ以外の場合、ロボット化に失敗したことを通知します。

• PresidentialPardonForm: 必要な成績：サイン25、エグゼクティブ5
<target>がザフォード・ビブローロックスによって恩赦されたことを通知する。

これらすべては、コンストラクタで1つのパラメータのみを受け取ります。フォームのターゲットです。例えば、自宅に植木を植えたい場合は「home」となります。
次に、baseフォームに execute(Bureaucrat const & executor) const メンバ関数を追加し、コンクリートクラスのフォームのアクションを実行する関数を実装します。フォームが署名済みであること、およびフォームの実行を試みる官僚の等級が十分高いことを確認する必要があります。そうでない場合は、適切な例外をスローします。
要件をチェックする対象を各具象クラスにするか、基底クラスにするか（その場合はフォームを実行する別の関数を呼び出す）は、あなた次第です。しかし、一方の方法のほうがもう一方よりも見栄えがよいでしょう。
最後に、Bureau-cratにexecuteForm(AForm const & form)メンバ関数を追加します。この関数はフォームの実行を試みます。成功した場合は、以下のようなメッセージを表示します。
  <bureaucrat> executed <form>

そうでなければ、明確なエラーメッセージを表示します。
期待通りに動作することを確認するために、いくつかのテストを実装して実行します。
*/

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void exe(const Bureaucrat& bureaucrat, AForm& form) {
	std::cout << form;
	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
}

int	main() {
	Bureaucrat taro("taro", 1);
	Bureaucrat hanako("hanako", 42);
	std::cout << taro << hanako;

	try {
		{
			std::cout << std::endl << "< shrubbery >"  << std::endl << std::endl;
			ShrubberyCreationForm form("sample1");
			exe(taro, form);
		}
		{
			std::cout << std::endl << "< robotomy >"  << std::endl << std::endl;
			RobotomyRequestForm form("sample2");
			exe(taro, form);
		}
		{
			std::cout << std::endl << "< presidential >"  << std::endl << std::endl;
			PresidentialPardonForm form("sample3");
			exe(taro, form);
		}
		PresidentialPardonForm form("sample4");
		{
			std::cout << std::endl << "< execute unsigned form >"  << std::endl << std::endl;
			std::cout << form;
			taro.executeForm(form);
		}
		{
			std::cout << std::endl << "< too low >"  << std::endl << std::endl;
			taro.signForm(form);
			hanako.executeForm(form);
		}
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
