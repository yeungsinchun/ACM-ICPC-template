#include <bits/stdc++.h>

// May not work for C++ version older than C++11, since modulo with negative
// numbers are implementation-defined prior to C++11
template <const int MOD>
class ModNum {
   private:
    int m_value{};

   public:
    int normalize(int64_t num) {
        if (num < 0) {
            num += ((-num + MOD - 1) / MOD) * MOD;
        }
        return static_cast<int>(num % MOD);
    }
    int normalize(int num) {
        while (num < 0) {
            num += MOD;
        }
        while (num >= MOD) {
            num -= MOD;
        }
        return num;
    }
    ModNum(int val = 0) { m_value = normalize(val); }
    ModNum(int64_t val) { m_value = normalize(val); }
    int val() const { return m_value; }
    ModNum<MOD> inv() const {
        int64_t a = this->val(), b = MOD, x = 1, y = 0;
        int64_t x1 = 0, y1 = 1;
        while (b != 0) {
            int64_t q = a / b;
            int temp = x1;
            x1 = x - q * x1;
            x = temp;
            temp = y1;
            y1 = y - q * y1;
            y = temp;
            temp = b;
            b = a - b * q;
            a = temp;
        }
        assert(a == 1 && "sorwy, can't find the inverse, you retard");
        return x;
    }

    ModNum<MOD>& operator+=(const int num);
    ModNum<MOD>& operator+=(const ModNum<MOD>& num);
    ModNum<MOD>& operator-=(const int num);
    ModNum<MOD>& operator-=(const ModNum<MOD>& num);
    ModNum<MOD>& operator*=(const int num);
    ModNum<MOD>& operator*=(const ModNum<MOD>& num);
    ModNum<MOD>& operator/=(const int num);
    ModNum<MOD>& operator/=(const ModNum<MOD>& num);

    template <const int _MOD>
    friend std::ostream& operator<<(std::ostream& out, const ModNum<_MOD>& num);
    template <const int _MOD>
    friend std::istream& operator>>(std::istream& out, ModNum<_MOD>& num);

    template <const int _MOD>
    friend ModNum<_MOD> operator+(const ModNum<_MOD>& num1,
                                  const ModNum<_MOD>& num2);
    template <const int _MOD>
    friend ModNum<_MOD> operator+(const int num1, const ModNum<_MOD>& num2);
    template <const int _MOD>
    friend ModNum<_MOD> operator+(const ModNum<_MOD>& num1, const int num2);

    template <const int _MOD>
    friend ModNum<_MOD> operator-(const ModNum<_MOD>& num1,
                                  const ModNum<_MOD>& num2);
    template <const int _MOD>
    friend ModNum<_MOD> operator-(const int num1, const ModNum<_MOD>& num2);
    template <const int _MOD>
    friend ModNum<_MOD> operator-(const ModNum<_MOD>& num1, const int num2);

    template <const int _MOD>
    friend ModNum<_MOD> operator*(const ModNum<_MOD>& num1,
                                  const ModNum<_MOD>& num2);
    template <const int _MOD>
    friend ModNum<_MOD> operator*(const int num1, const ModNum<_MOD>& num2);
    template <const int _MOD>
    friend ModNum<_MOD> operator*(const ModNum<_MOD>& num1, const int num2);

    template <const int _MOD>
    friend ModNum<_MOD> operator/(const ModNum<_MOD>& num1,
                                  const ModNum<_MOD>& num2);
    template <const int _MOD>
    friend ModNum<_MOD> operator/(const int num1, const ModNum<_MOD>& num2);
    template <const int _MOD>
    friend ModNum<_MOD> operator/(const ModNum<_MOD>& num1, const int num2);

    explicit operator int() const { return this->val(); }
};

template <const int _MOD>
std::ostream& operator<<(std::ostream& out, const ModNum<_MOD>& num) {
    out << num.val();
    return out;
}
template <const int _MOD>
std::istream& operator>>(std::istream& in, ModNum<_MOD>& num) {
    int64_t inp;
    in >> inp;
    num = ModNum<_MOD>{inp};
    return in;
}
template <const int _MOD>
ModNum<_MOD> operator+(const ModNum<_MOD>& num1, const ModNum<_MOD>& num2) {
    return ModNum<_MOD>{num1.val() + num2.val()};
};
template <const int _MOD>
ModNum<_MOD> operator+(const int num1, const ModNum<_MOD>& num2) {
    return ModNum<_MOD>{num1} + num2;
};
template <const int _MOD>
ModNum<_MOD> operator+(const ModNum<_MOD>& num1, const int num2) {
    return num1 + ModNum<_MOD>{num2};
};

template <const int _MOD>
ModNum<_MOD> operator-(const ModNum<_MOD>& num1, const ModNum<_MOD>& num2) {
    return ModNum<_MOD>{num1.val() - num2.val()};
};
template <const int _MOD>
ModNum<_MOD> operator-(const int num1, const ModNum<_MOD>& num2) {
    return ModNum<_MOD>{num1} - num2;
};
template <const int _MOD>
ModNum<_MOD> operator-(const ModNum<_MOD>& num1, const int num2) {
    return num1 - ModNum<_MOD>{num2};
};

template <const int _MOD>
ModNum<_MOD> operator*(const ModNum<_MOD>& num1, const ModNum<_MOD>& num2) {
    return ModNum<_MOD>{static_cast<int64_t>(num1.val()) * num2.val()};
};
template <const int _MOD>
ModNum<_MOD> operator*(const int num1, const ModNum<_MOD>& num2) {
    return ModNum<_MOD>{num1} * num2;
};
template <const int _MOD>
ModNum<_MOD> operator*(const ModNum<_MOD>& num1, const int num2) {
    return num1 * ModNum<_MOD>{num2};
};

template <const int _MOD>
ModNum<_MOD> operator/(const ModNum<_MOD>& num1, const ModNum<_MOD>& num2) {
    return ModNum<_MOD>{static_cast<int64_t>(num1.val()) * num2.inv().val()};
};
template <const int _MOD>
ModNum<_MOD> operator/(const int num1, const ModNum<_MOD>& num2) {
    return ModNum<_MOD>{num1} / num2;
};
template <const int _MOD>
ModNum<_MOD> operator/(const ModNum<_MOD>& num1, const int num2) {
    return num1 / ModNum<_MOD>{num2};
};

template <const int _MOD>
ModNum<_MOD>& ModNum<_MOD>::operator+=(const int num) {
    *this = *this + num;
    return *this;
};
template <const int _MOD>
ModNum<_MOD>& ModNum<_MOD>::operator+=(const ModNum<_MOD>& num) {
    *this = *this + num;
    return *this;
};
template <const int _MOD>
ModNum<_MOD>& ModNum<_MOD>::operator-=(const int num) {
    *this = *this - num;
    return *this;
};
template <const int _MOD>
ModNum<_MOD>& ModNum<_MOD>::operator-=(const ModNum<_MOD>& num) {
    *this = *this - num;
    return *this;
};
template <const int _MOD>
ModNum<_MOD>& ModNum<_MOD>::operator*=(const int num) {
    *this = *this * num;
    return *this;
};
template <const int _MOD>
ModNum<_MOD>& ModNum<_MOD>::operator*=(const ModNum<_MOD>& num) {
    *this = *this * num;
    return *this;
};
template <const int _MOD>
ModNum<_MOD>& ModNum<_MOD>::operator/=(const int num) {
    *this = *this / num;
    return *this;
};
template <const int _MOD>
ModNum<_MOD>& ModNum<_MOD>::operator/=(const ModNum<_MOD>& num) {
    *this = *this / num;
    return *this;
};

constexpr int MOD = 1e9 + 7;
std::vector<ModNum<MOD>> fac(1, 1);
std::vector<ModNum<MOD>> ifac(1, 1);

ModNum<MOD> nCr(const int n, const int r) {
    if (r > n || r < 0) {
        return 0;
    }
    while (int(fac.size()) <= n) {
        fac.push_back(fac.back() * int(fac.size()));
        ifac.push_back(ifac.back() / int(ifac.size()));
    }
    return fac[n] * ifac[n - r] * ifac[r];
}

using namespace std;
using Mint = ModNum<MOD>;
int main() {
    ModNum<10> a = -3;
    cout << a << '\n';
    return 0;
}