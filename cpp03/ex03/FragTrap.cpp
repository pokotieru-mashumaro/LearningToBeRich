#include "FragTrap.hpp"

/*
ClapTrapsの作成は、おそらく皆さんの神経を逆なでし始めているでしょう。
次に、ClapTrapを継承するFragTrapクラスを実装します。これはScavTrapと非常に似ています。
ただし、その構築と破壊のメッセージは異なる必要があります。適切な構築/破壊の連鎖は、テストで示さなければなりません。FragTrapが作成されると、プログラムはClapTrapの構築から開始します。破壊は逆の順序で行われます。
属性も同様ですが、今回は異なる値を使用します。
• 名前（コンストラクタのパラメータとして渡される） 
• ヒットポイント（100）はClapTrapの健康状態を表します。 
• エネルギーポイント（100） 
• 攻撃ダメージ（30） 
FragTrapには特別な機能もあります。
void highFivesGuys(void); 
このメンバー関数は、正のハイタッチリクエストを標準出力に表示します。 ここでも、プログラムにさらにテストを追加します。
*/

FragTrap::FragTrap(): ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
    std::cout << "FragTrap Default constructor called (name=default)" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
    std::cout <<  "FragTrap Custom Constructor called (name=" << _name << ")" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
    std::cout << "FragTrap Copy constructor called" << " (name=" << _name << ")" << std::endl;
    *this = copy;
}

FragTrap::~FragTrap()
{
    std::cout << _name << " FragTrap Destructor called " << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hit_points = copy._hit_points;
        this->_energy_points = copy._energy_points;
        this->_attack_damage = copy._attack_damage;
    }
    return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << "high fives guys. Yeah!!" << std::endl;
}