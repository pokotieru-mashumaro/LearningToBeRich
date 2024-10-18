#include "ClapTrap.hpp"

/*
まず、クラスを実装しなければなりません！なんと独創的なのでしょう！
ClapTrap と名付けられたこのクラスには、以下のプライベート属性が括弧内に指定された値に初期化されます。
• Name（名前）はコンストラクタのパラメータとして渡されます。
• Hit points（ヒットポイント）（10）は、ClapTrap の健康状態を表します。
• Energy points（エネルギーポイント）（10）
• Attack damage（攻撃ダメージ）（0）
ClapTrapをよりリアルに見せるために、以下のパブリックメンバ関数を追加します。
void attack(const std::string& target);
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);

ClapTrackが攻撃すると、対象の<ダメージ>ヒットポイントが失われる。
ClapTrapが自己修復すると、<量>ヒットポイントが回復する。攻撃と修復にはそれぞれ1エネルギーポイントを消費する。もちろん、ヒットポイントもエネルギーポイントも残っていない場合は、ClapTrapは何もできない。

これらのすべてのメンバ関数において、何が起こっているかを説明するメッセージを表示する必要があります。
例えば、
attack()関数では、次のような内容を表示します（もちろん、角カッコは使用しません）。

ClapTrap <name> attacks <target>, causing <damage> points of damage!

コンストラクタとデストラクタでもメッセージを表示する必要があります。そうすることで、ピア評価者が簡単に呼び出されたことが確認できます。期待通りに動作することを確認するために、独自のテストを実装し、提出してください。
*/

ClapTrap::ClapTrap() : _name("default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "Default constructor called (name=default)" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout <<  "Custom Constructor called (name=" << _name << ")" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "Copy constructor called" << " (name=" << _name << ")" << std::endl;
    *this = copy;
}

ClapTrap::~ClapTrap()
{
    std::cout << _name << "Destructor called " << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hit_points = copy._hit_points;
        this->_energy_points = copy._energy_points;
        this->_attack_damage = copy._attack_damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->_energy_points > 0 && this->_hit_points > 0)
    {
        std::cout << this->_name << " が " << target << " に " << this->_attack_damage << " points 攻撃した!" << std::endl;
        this->_energy_points--;
    }
    else if (this->_energy_points <= 0)
        std::cout << this->_name << " はもう攻撃できない..（エネルギー切れ）" << std::endl;
    else if (this->_hit_points <= 0)
        std::cout << this->_name << " の体力が0です.." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hit_points > amount)
        this->_hit_points -= amount;
    else if (this->_hit_points > 0)
        this->_hit_points = 0;
    else 
    {
        std::cout << this->_name << " はすでに体力が0です..." << std::endl;
        return ;
    }
    std::cout << this->_name << " は " << amount << " points 攻撃された. " << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energy_points > 0)
    { 
        std::cout << this->_name << " は " << amount << " points 回復した. " << std::endl;
        this->_hit_points += amount;
        this->_energy_points--;
    }
    else
        std::cout << this->_name << " はもう回復できない..（エネルギー切れ）" << std::endl;
}
