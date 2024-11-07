#include "ScavTrap.hpp"

/*
ClapTrapsはいくらあっても十分ということはありません。そこで、派生ロボットを作成します。
このロボットはScavTrapと名付けられ、ClapTrapのコンストラクタとデストラクタを継承します。
ただし、そのコンストラクタ、デストラクタ、およびattack()は異なるメッセージを表示します。
結局のところ、ClapTrapsは個性を認識しているのです。適切な構築/破壊の連鎖がテストで示されていることを確認してください。
ScavTrapが作成されると、プログラムはClapTrapを構築することから開始します。破壊は逆の順序で行われます。
なぜでしょうか？ScavTrapはClapTrapの属性を使用します（結果としてClapTrapを更新します）。また、以下の属性を初期化する必要があります。
• 名前（コンストラクタのパラメータとして渡される）
• ヒットポイント（100）はClapTrapの健康状態を表します
• エネルギーポイント（50） 
攻撃力（20）
ScavTrap にも独自の特殊能力があります。
void guardGate();
このメンバー関数は、ScavTrap が現在ゲートキーパーモードであることを知らせるメッセージを表示します。プログラムにさらにテストを追加することを忘れないでください。
*/

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
    std::cout << "ScavTrap Default constructor called (name=default)" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
    std::cout <<  "ScavTrap Custom Constructor called (name=" << _name << ")" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
    std::cout << "ScavTrap Copy constructor called" << " (name=" << _name << ")" << std::endl;
    *this = copy;
}

ScavTrap::~ScavTrap()
{
    std::cout << _name << " ScavTrap Destructor called " << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hit_points = copy._hit_points;
        this->_energy_points = copy._energy_points;
        this->_attack_damage = copy._attack_damage;
    }
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_energy_points > 0 && this->_hit_points > 0)
    {
        std::cout << "ScavTrap: " << this->_name << " が " << target << " に " << this->_attack_damage << " points 攻撃した!" << std::endl;
        this->_energy_points--;
    }
    else if (this->_energy_points <= 0)
        std::cout << "ScavTrap: " << this->_name << " はもう攻撃できない..（エネルギー切れ）" << std::endl;
    else if (this->_hit_points <= 0)
        std::cout << "ScavTrap: " << this->_name << " の体力が0です.." << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}
