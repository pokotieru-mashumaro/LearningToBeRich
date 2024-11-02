/*
官僚が揃ったので、彼らに何か仕事をさせましょう。
書類の山に記入する以上の活動があるでしょうか？
それでは、Formクラスを作成しましょう。
Formクラスには、以下のものがあります。
• 定数名。
• 署名済みかどうかを示すブール値（構築時には未署名）。
• 署名に必要な定数評価。
そして、実行に必要なグレード。

これらの属性はすべてプライベートで、プロテクトされていません。
フォームのグレードは、官僚に適用されるのと同じルールに従います。したがって、フォームのグレードが範囲外の場合、次の例外がスローされます。Form::GradeTooHighExceptionおよびForm::GradeTooLowException。
これまでと同様に、すべての属性のゲッターと、フォームのすべての情報を表示する挿入演算子（<<）のオーバーロードを記述します。

また、パラメータとして官僚を受け取るフォームのメンバー関数beSigned()も追加します。
官僚の評価が十分高い（必須の評価と同じかそれ以上）場合、フォームの状態を「署名済み」に変更します。評価1は評価2よりも高いことを覚えておいてください。
評価が低すぎる場合は、Form::GradeTooLowException をスローします。

最後に、官僚に signForm() というメンバ関数を追加します。フォームに署名された場合は、次のような内容が出力されます。
<bureaucrat> signed <form>
それ以外の場合には、次のような内容が出力されます。
<bureaucrat> couldn’t sign <form> because <reason>.
期待通りに動作することを確認するために、いくつかのテストを実装して実行してみましょう。
*/

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	printError(std::exception& e)
{
	std::cout << "Error: " << e.what() << std::endl;
}

int	main()
{
	Bureaucrat	taro("taro", 42);
	std::cout << taro;

	try
	{
		Form	sample("sample", 1000, 1);
	}
	catch (std::exception& e)
	{
		printError(e);
	}

	try
	{
		Form	sample("sample", 42, 0);
	}
	catch (std::exception& e)
	{
		printError(e);
	}

	try
	{
		Form	sample1("sample1", 42, 42);
		Form	sample2("sample2", 1, 1);

		std::cout << std::endl << sample1 << sample2;

		taro.signForm(sample1);
		std::cout << sample1;
		taro.signForm(sample1);

		taro.signForm(sample2);
	}
	catch (std::exception& e)
	{
		printError(e);
	}
}
