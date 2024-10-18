#include "Fixed.hpp"

/*
前回の演習は良いスタートでしたが、私たちのクラスはほとんど役に立ちません。このクラスは値 0.0 しか表現できません。
以下のパブリックコンストラクタとパブリックメンバー関数をクラスに追加します。
• パラメータとして定数の整数を指定するコンストラクタ。整数を対応する固定小数点値に変換します。小数部のビット値は、演習 00 のように 8 に初期化されます。
• 浮動小数点定数をパラメータとして受け取るコンストラクタ。対応する固定小数点値に変換します。小数部のビット値は、演習00と同様に8に初期化されます。
• 固定小数点値を浮動小数点値に変換するメンバー関数 float toFloat( void ) const;
• 固定小数点値を整数に変換するメンバー関数 int toInt( void ) const;
そして、Fixed クラスファイルに以下の関数を追加します。
浮動小数点表現の固定小数点数をパラメータとして渡された出力ストリームオブジェクトに挿入する挿入（«）演算子のオーバーロード。
*/

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point_number = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	_fixed_point_number = num << _fractional_bits; // ビットシフトを使って固定小数点表現に変換
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	_fixed_point_number = roundf(num * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_fixed_point_number = copy.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getWawBits member function called" << std::endl;
	return (this->_fixed_point_number);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed_point_number = raw;
}

int Fixed::toInt(void) const
{
	return _fixed_point_number >> _fractional_bits;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_fixed_point_number) / (1 << _fractional_bits);
}

std::ostream& operator<<(std::ostream& o, Fixed const& f) 
{
	o << f.toFloat();
	return o;
}