#include "DiamondTrap.hpp"

/*
この演習では、モンスターを作成します。
FragTrapとScavTrapのハーフであるClapTrapです。DiamondTrapと名付け、FragTrapとScavTrapの両方から継承します。これは非常に危険です！
DiamondTrapクラスには、名前のプライベート属性があります。
この属性には、ClapTrap ベースクラスと同じ変数名（ここではロボットの名前について言及しているわけではありません）を正確に指定します。より明確にするために、2つの例を挙げます。
ClapTrapの変数がnameである場合、DiamondTrapの変数名はnameとします。
ClapTrapの変数が_nameである場合、DiamondTrapの変数名は_nameとします。
その属性とメンバ関数は、親クラスのいずれかから取得されます。
• 名前：コンストラクタのパラメータとして渡される
• ClapTrap::name (コンストラクタのパラメータ + 「_clap_name」接尾辞)
• ヒットポイント (FragTrap)
• エネルギーポイント (ScavTrap)
• 攻撃ダメージ (FragTrap)
• attack() (Scavtrap)

親クラスの特殊関数に加えて、DiamondTrapは独自の特殊能力を持ちます。
void whoAmI();
このメンバ関数は、自身の名前とClapTrapの名前の両方を表示します。もちろん、DiamondTrapのClapTrapサブオブジェクトは一度だけ作成されます。
はい、トリックがあります。もう一度言いますが、プログラムにさらにテストを追加してください。
*/

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_trap")
{
    this->_name = "default";
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;
    std::cout << "DiamondTrap Default constructor called (name=default)" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap")
{
    this->_name = name;
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;
    std::cout << "DiamondTrap Custom Constructor called (name=" << _name << ")" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    *this = copy;
    std::cout << "DiamondTrap Copy constructor called" << " (name=" << _name << ")" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << _name << " DiamondTrap Destructor called " << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;

    if (this != &copy)
    {
        this->_name = copy._name + "_clap_trap";
        this->_hit_points = copy._hit_points;
        this->_energy_points = copy._energy_points;
        this->_attack_damage = copy._attack_damage;
    }
    return *this;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "こんにちはDiamondTrapでの自分の名前は" << this->_name << "。ClapTrapでの自分の名前は" << ClapTrap::_name << std::endl;
}