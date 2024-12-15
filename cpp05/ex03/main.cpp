#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

/*
フォームの記入は十分に厄介な作業であるため、官僚たちにこれを一日中やれというのは酷な話です。
幸い、インターンが存在します。この演習では、インターンクラスを実装する必要があります。インターンには名前も成績も、独自の特性もありません。
官僚たちが気にかけるのは、彼らが仕事をこなしているかどうかだけです。

しかし、インターンには重要な機能が1つあります。makeForm()関数です。
この関数は2つの文字列を受け取ります。最初の引数はフォームの名前、2番目の引数はフォームのターゲットです。
これは、ターゲットが2番目のパラメータに初期化されるFormオブジェクト（パラメータとして渡された名前のもの）へのポインタを返します。

以下のような内容が出力されます。
Intern creates <form>
パラメータとして渡されたフォーム名が存在しない場合は、明確なエラーメッセージを出力します。

if/elseif/elseの森のような、読みづらく醜いソリューションは避けなければなりません。
このようなものは評価プロセスでは受け入れられません。あなたはもうプール（Piscine）にはいません。
いつも通り、すべてが期待通りに動作するかどうかをテストしなければなりません。
*/

void exe(const Bureaucrat& bureaucrat, AForm& form) {
	std::cout << form;
	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
}

int main() {
	Bureaucrat taro("taro", 1);
	Bureaucrat hanako("hanako", 42);
	std::cout << taro << hanako;

	Intern intern;

	try {
		{
			std::cout << std::endl << "< shrubbery >"  << std::endl << std::endl;
			AForm* form = intern.makeForm("shrubbery creation", "sample1");
			if (form) {
				exe(taro, *form);
				delete form;
			}
		}
		{
			std::cout << std::endl << "< robotomy >"  << std::endl << std::endl;
			AForm* form = intern.makeForm("robotomy request", "sample2");
			if (form) {
				exe(taro, *form);
				delete form;
			}
		}
		{
			std::cout << std::endl << "< presidential >"  << std::endl << std::endl;
			AForm* form = intern.makeForm("presidential pardon", "sample3");
			if (form) {
				exe(taro, *form);
				delete form;
			}
		}
		AForm* form = intern.makeForm("presidential pardon", "sample4");
		if (form) {
			std::cout << std::endl << "< execute unsigned form >"  << std::endl << std::endl;
			std::cout << *form;
			taro.executeForm(*form);
			delete form;
		}
		{
			std::cout << std::endl << "< too low >"  << std::endl << std::endl;
			AForm* form = intern.makeForm("presidential pardon", "sample5");
			if (form) {
				taro.signForm(*form);
				hanako.executeForm(*form);
				delete form;
			}
		}
        {
			std::cout << std::endl << "< not exist form >"  << std::endl << std::endl;
			AForm* form = intern.makeForm("hello", "sample5");
			if (form) {
				taro.signForm(*form);
				hanako.executeForm(*form);
				delete form;
			}
		}
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}