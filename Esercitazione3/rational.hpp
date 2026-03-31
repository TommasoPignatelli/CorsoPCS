#include <concepts>
#include <ostream>
#include <numeric>


template<typename I> requires std::integral<I>
class rational
{
public:
I num_;
I den_;

 /*Costruttore di default*/
 rational()
 : num_(I{0}),den_(I{1})
 {}

 /*Costruttore user-defined*/
 rational(const I&pnum,const I&pden)
 : num_(pnum),den_(pden)
 {
    simplify();
 }
 /*Restituiscono i valori di numeratore e denominatore*/
 I num() const{return num_;}
 I den() const{return den_;}


 /* Semplificazione della frazione */
    void simplify() {
        if (den() != 0) {
        I gcd_val = std::gcd(num_, den_);
        num_ /= gcd_val;
        den_ /= gcd_val;
        }
    }

 /* Implementazione canonica dell'incremento */
    rational& operator+=(const rational& other) {
        num_ = num_ * other.den_ + other.num_ * den_;
        den_ = den_ * other.den_;
        simplify();
        return *this;
    }
 /* Implementazione canonica della somma */
    rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }
  /* Implementazione canonica dell'incremento negativo*/
    rational& operator-=(const rational& other) {
        num_ = num_ * other.den_ - other.num_ * den_;
        den_ = den_ * other.den_;
        simplify();
        return *this;
    }
 /* Implementazione canonica della sottrazione */
    rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        return ret;
    }

 /* Implementazione canonica di *=  */
    rational& operator*=(const rational& other) {
        num_ *= other.num_;
        den_ *= other.den_;
        simplify();
        return *this;
    }
 /* Implementazione canonica del prodotto */
    rational operator*(const rational& other) const {
        rational ret = *this;
        ret *= other;
        return ret;
    }
 /* Implementazione canonica di divisione incrementale  */
    rational& operator/=(const rational& other) {
        num_ *= other.den_;
        den_ *= other.num_;
        simplify();
        return *this;
    }
 /* Implementazione canonica della divisione */
    rational operator/(const rational& other) const {
        rational ret = *this;
        ret /= other;
        return ret;
    }
 };



template<typename I> requires std::integral<I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r)
{
if (r.den() == 0 && r.num() != 0) {
        os << "Inf";
        return os;
    } else if (r.den() == 0 && r.num() == 0) {
        os << "NaN";
        return os;
    }
    else{
        os << r.num() << "/" << r.den();
        return os;
    }
}


