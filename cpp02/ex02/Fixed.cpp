#include "Fixed.hpp"

/*
以下の演算子をオーバーロードするために、パブリックメンバ関数をクラスに追加します。
6つの比較演算子：>、<、>=、<=、==、!=。4つの算術演算子：+、-、*、/。
• 4つのインクリメント/デクリメント（プリインクリメントおよびポストインクリメント、プリデクリメントおよびポストデクリメント）演算子。1 + ϵ > 1 のような最小の表現可能な ϵ から固定小数点値を増減さ
せます。これらの4つのパブリックオーバーロードメンバー関数をクラスに追加します。
固定小数点数の参照を2つパラメータとして受け取り、最小の参照を返す静的メンバー関数 min。
固定小数点数の定数への参照を2つパラメータとして受け取り、最小の参照を返す静的メンバー関数 min。
固定小数点数の参照を2つパラメータとして受け取り、最大の参照を返す静的メンバー関数 max。
 • 2つの定数固定小数点数の参照をパラメータとして受け取り、最も大きいものへの参照を返す静的メンバ関数max。
 */

Fixed::Fixed(void)
{
	this->_fixed_point_number = 0;
}

Fixed::Fixed(const int num)
{
	_fixed_point_number = num << _fractional_bits; // ビットシフトを使って固定小数点表現に変換
}

Fixed::Fixed(const float num)
{
	_fixed_point_number = roundf(num * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
		this->_fixed_point_number = copy.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
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

std::ostream &operator<<(std::ostream &o, Fixed const &f)
{
	o << f.toFloat();
	return o;
}

bool Fixed::operator>(const Fixed &right) const
{
	return _fixed_point_number > right._fixed_point_number;
}
bool Fixed::operator<(const Fixed &right) const
{
	return _fixed_point_number < right._fixed_point_number;
}
bool Fixed::operator>=(const Fixed &right) const
{
	return _fixed_point_number >= right._fixed_point_number;
}
bool Fixed::operator<=(const Fixed &right) const
{
	return _fixed_point_number <= right._fixed_point_number;
}
bool Fixed::operator==(const Fixed &right) const
{
	return _fixed_point_number == right._fixed_point_number;
}
bool Fixed::operator!=(const Fixed &right) const
{
	return _fixed_point_number != right._fixed_point_number;
}

Fixed Fixed::operator+(const Fixed &right) const
{
	Fixed res;
	res._fixed_point_number = _fixed_point_number + right._fixed_point_number;
	return res;
}

Fixed Fixed::operator-(const Fixed &right) const
{
	Fixed res;
	res._fixed_point_number = _fixed_point_number - right._fixed_point_number;
	return res;
}

Fixed Fixed::operator*(const Fixed &right) const
{
	Fixed res;
	res._fixed_point_number = (_fixed_point_number * right._fixed_point_number) >> _fractional_bits;
	return res;
}

Fixed Fixed::operator/(const Fixed &right) const
{
	Fixed res;
	res._fixed_point_number = (_fixed_point_number << _fractional_bits) / right._fixed_point_number;
	return res;
}

Fixed &Fixed::operator++()
{
	_fixed_point_number++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed res = *this;
	res._fixed_point_number = this->_fixed_point_number++;
	return res;
}

Fixed &Fixed::operator--()
{
	_fixed_point_number--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed res = *this;
	res._fixed_point_number = this->_fixed_point_number--;
	return res;
}

Fixed &Fixed::min(Fixed &left, Fixed &right)
{
	return (left < right) ? left : right;
}

const Fixed &Fixed::min(const Fixed &left, const Fixed &right)
{
	return (left < right) ? left : right;
}

Fixed &Fixed::max(Fixed &left, Fixed &right)
{
	return (left > right) ? left : right;
}

const Fixed &Fixed::max(const Fixed &left, const Fixed &right)
{
	return (left > right) ? left : right;
}