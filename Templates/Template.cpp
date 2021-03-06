// Credit: https://github.com/AkiLotus/AkikazeCP/blob/master/Vault/Template/OriginalCheatsheet.cpp
/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
	
	H△G x Mili - November 27th, 2013
	Mag Mell (Mili) - Sep 17th, 2014
	H△G x Mili Vol.2 - May 9th, 2015
	Miracle Milk (Mili) - Oct 12th, 2016
	青色フィルム (H△G) - February 14th, 2018
	Millennium Mother (Mili) - April 25th, 2018
	
	Terminal command for compilation: g++ -o fileName -p -std=c++17 fileName.cpp
**/

/** -----PRAGMA----- **/
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

/** -----GNU OMISSIONS----- **/
#define y0 withindarkness
#define y1 apinklotusbloomed
#define yn carryingapurplesoul
#define j1 togetherformingtheTeam

/** -----BASIC MACROS----- **/
#define endl '\n'
#define i64 long long
#define ld long double
#define rsz resize
#define pub push_back
#define mp make_pair
#define fi first
#define se second
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vl;
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<i64, i64> pll;
typedef pair<i64, pll> plp;
typedef pair<pll, i64> ppl;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef pair<pii, int> ppi;
i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
i64 keyCount = sizeof(keymod) / sizeof(i64);
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcountll(s); }

/** -----MATRICES----- **/
struct matrix {
	vector<vector<i64>> A;

	matrix() {}

	matrix(i64 n, i64 m) {
		A.resize(n, vector<i64>(m, 0));
	}

	matrix(i64 n, i64 m, vector<i64> input) {
		A.resize(n, vector<i64>(m, 0));
		for (i64 i=0; i<input.size(); i++) {
			A[i/m][i%m] = input[i];
		}
	}

	matrix(i64 n, i64 m, vector<vector<i64>> input) {
		A.resize(n, vector<i64>(m, 0));
		for (i64 i=0; i<input.size(); i++) {
			if (i >= n) break;
			for (i64 j=0; j<input[0].size(); j++) {
				if (j >= m) break;
				A[i][j] = input[i][j];
			}
		}
	}

	matrix(vector<vector<i64>> input) {
		for (i64 i=0; i<input.size(); i++) {
			vector<i64> tmp;
			for (i64 j=0; j<input[0].size(); j++) {
				tmp.pub(input[i][j]);
			}
			A.pub(tmp);
		}
	}

	matrix operator* (matrix b) {
		if (this->A[0].size() != b.A.size()) return matrix(0, 0);
		i64 n = this->A.size(), m = b.A[0].size();
		matrix result(n, m);
		for (i64 i=0; i<n; i++) {
			for (i64 j=0; j<m; j++) {
				result.A[i][j] = 0;
				for (i64 k=0; k<b.A.size(); k++) result.A[i][j] += this->A[i][k] * b.A[k][j];
			}
		}
		return result;
	}

	ostream& operator<< (ostream& os) {
		for (i64 i=0; i<this->A.size(); i++) {
			for (i64 j=0; j<this->A[0].size(); j++) {
				os << this->A[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}
};

matrix unitmat(matrix z) {
	matrix res = matrix(z.A.size(), z.A[0].size());
	for (i64 i=0; i<z.A.size(); i++) {
		res.A[i][i] = 1;
	}
	return res;
}

matrix modMul(matrix a, matrix b) {
	if (a.A[0].size() != b.A.size()) return matrix(0, 0);
	i64 n = a.A.size(), m = b.A[0].size();
	matrix result(n, m);
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			result.A[i][j] = 0;
			for (i64 k=0; k<b.A.size(); k++) {
				result.A[i][j] += (a.A[i][k] * b.A[k][j]) % MOD;
				result.A[i][j] %= MOD;
			}
		}
	}
	return result;
}

matrix matPow(matrix a, i64 b) {
	if (b == 0) return unitmat(a);
	if (b == 1) return a;
	matrix tmp = matPow(a, b/2);
	if (b % 2 == 0) return modMul(tmp, tmp);
	return modMul(modMul(tmp, tmp), a);
}

/** -----MATH/STRING FUNCTIONS----- **/
i64 modPow(i64 a, i64 b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	i64 tmp = modPow(a, b/2);
	if (b % 2 == 0) return ((tmp * tmp) % MOD);
	return ((((tmp * tmp) % MOD) * a) % MOD);
}

i64 divPow(i64 a, i64 b) {
	return ((a * modPow(b, MOD-2)) % MOD);
}

i64 Str2I64(string z) {
	bool negative = false;
	if (z[0] == '-') {
		negative = true; z.erase(0, 1);
	}
	i64 res = 0;
	for (i64 i=0; i<z.size(); i++) res = res * 10 + (z[i] - '0');
	if (negative) return -res;
	return res;
}

string toStr(i64 z) {
	if (z == 0) return "0";
	bool negative = false;
	if (z < 0) negative = true;
	string res = "";
	while (z > 0) {
		i64 tmp = z % 10; z /= 10;
		res.insert(0, 1, char(48+tmp));
	}
	if (negative) res.insert(0, 1, '-');
	while (res.size() > 1 && res[0] == '0') res.erase(0, 1);
	return res;
}

/** -----BIGINTS----- **/
struct bigint {
	string digit = "";
	bool negative = false;

	bigint() {}
	bigint(string vs, bool sign) {
		digit = vs; negative = sign;
	}
	bigint(i64 inputs) {
		digit = toStr(abs(inputs)); negative = (inputs < 0);
	}
	bigint(int inputs) {
		digit = toStr(abs(inputs)); negative = (inputs < 0);
	}

	bool operator<(bigint p2) {
		if (this->negative && !p2.negative) return true;
		if (this->negative && !p2.negative) return false;
		string s1 = this->digit, s2 = p2.digit;
		i64 len = max(s1.size(), s2.size());
		s1.insert(0, len-s1.size(), '0');
		s2.insert(0, len-s2.size(), '0');
		if (this->negative) return(s1 > s2);
		return (s1 < s2);
	}

	bool operator>(bigint p2) {
		if (this->negative && !p2.negative) return false;
		if (this->negative && !p2.negative) return true;
		string s1 = this->digit, s2 = p2.digit;
		i64 len = max(s1.size(), s2.size());
		s1.insert(0, len-s1.size(), '0');
		s2.insert(0, len-s2.size(), '0');
		if (this->negative) return(s1 < s2);
		return (s1 > s2);
	}

	bool operator==(bigint p2) {
		if (this->negative && !p2.negative) return false;
		if (this->negative && !p2.negative) return false;
		string s1 = this->digit, s2 = p2.digit;
		return (s1 == s2);
	}

	bool operator!=(bigint p2) {
		return (!(*this == p2));
	}

	bool operator<=(bigint p2) {
		return (*this < p2 || *this == p2);
	}

	bool operator>=(bigint p2) {
		return (*this > p2 || *this == p2);
	}

	bigint biabs(bigint z) {
		z.negative = false;
		return z;
	}

	bigint& operator=(bigint input) {
		this->digit = input.digit;
		this->negative = input.negative;
	}

	bigint operator+(bigint p2) {
		string s1 = this->digit, s2 = p2.digit;
		bool n1 = this->negative, n2 = p2.negative;
		i64 len = max(s1.size(), s2.size()) + 2;
		s1.insert(0, len-s1.size(), '0');
		s2.insert(0, len-s2.size(), '0');
		i64 carry = 0;
		string ans = ""; ans.insert(0, len, '0');
		if (n1 == n2) {
			for (i64 i=len-1; i>0; i--) {
				i64 tmp = (s1[i] - '0') + (s2[i] - '0') + carry;
				carry = tmp / 10; ans[i] = char(48+tmp%10);
			}
			while (ans.size() > 1 && ans[0] == '0') ans.erase(0, 1);
			return bigint(ans, n1);
		}
		bool anssign = false;
		if ((s2 > s1 && n2) || (s1 > s2 && n1)) anssign = true;
		if (s2 > s1) {
			string tmp = s1; s1 = s2; s2 = tmp;
		}
		for (i64 i=len-1; i>0; i--) {
			i64 tmp = (s1[i] - '0') - (s2[i] - '0') + carry;
			carry = 0;
			while (tmp < 0) {
				tmp += 10; carry--;
			}
			ans[i] = char(48+tmp);
		}
		while (ans.size() > 1 && ans[0] == '0') ans.erase(0, 1);
		return bigint(ans, anssign);
	}

	bigint& operator+=(bigint p2) {
		*this = *this + p2;
		return *this;
	}

	bigint operator-(bigint p2) {
		bigint tmp = bigint(p2.digit, !p2.negative);
		return (*this + tmp);
	}

	bigint& operator-=(bigint p2) {
		*this = *this - p2;
		return *this;
	}

	bigint operator*(bigint p2) {
		bigint ans = bigint(0);
		if ((this->negative && !p2.negative) || (!this->negative && p2.negative)) ans.negative = true;
		string working = this->digit;
		for (i64 i=p2.digit.size()-1; i>=0; i--) {
			if (i != p2.digit.size()-1) working.insert(working.size(), 1, '0');
			string tmp = working; tmp.insert(0, 2, '0');
			i64 mul = p2.digit[i] - '0', carry = 0;
			for (i64 j=tmp.size()-1; j>0; j--) {
				i64 tmptmp = (tmp[j] - '0') * mul + carry;
				tmp[j] = ('0' + tmptmp % 10); carry = tmptmp / 10;
			}
			while (tmp.size() > 1 && tmp[0] == '0') tmp.erase(0, 1);
			ans += bigint(tmp, ans.negative);
		}
		return ans;
	}

	bigint& operator*=(bigint p2) {
		*this = *this * p2;
		return *this;
	}

	bigint pow(bigint z, i64 p2) {
		if (p2 == 0) return bigint(0);
		if (p2 == 1) return z;
		bigint tmp = pow(z, p2/2);
		if (p2 % 2 == 0) return (tmp * tmp);
		return (tmp * tmp * z);
	}

	bigint operator/(bigint p2) {
		if (biabs(*this) < biabs(p2)) return bigint(0);
		if (biabs(*this) == biabs(p2)) {
			if (*this == p2) return bigint(1);
			else return bigint(-1);
		}
		bool negative = false;
		if ((this->negative && !p2.negative) || (!this->negative && p2.negative)) negative = true;
		if (this->negative) cout << "Negative1!\n";
		if (p2.negative) cout << "Negative2!\n";
		string working = this->digit;
		string divisor = p2.digit;
		string vs = "";
		string strtmp = working.substr(0, divisor.size());
		i64 pointer = divisor.size() - 1;
		if (strtmp < divisor) {
			pointer++; strtmp += working[pointer];
		}
		bigint tmp1 = bigint(strtmp, false);
		bigint tmp2 = biabs(p2);
		while (pointer < working.size()) {
			for (i64 i=9; i>=0; i--) {
				if (tmp2 * bigint(i) <= tmp1) {
					vs += char(48+i);
					tmp1 -= tmp2 * bigint(i);
					break;
				}
			}
			pointer++;
			if (pointer < working.size()) {
				tmp1 *= bigint(10);
				tmp1 += bigint(working[pointer]-'0');
			}
		}
		return bigint(vs, negative);
	}

	bigint& operator/=(bigint p2) {
		*this = *this / p2;
		return *this;
	}

	bigint operator%(bigint p2) {
		bigint quotient = bigint(*this.digit, *this.negative);
		quotient /= p2;
		return (*this - quotient * p2);
	}

	bigint& operator%=(bigint p2) {
		*this = *this % p2;
		return *this;
	}


	bigint operator++() {
		*this += bigint(1);
		return *this;
	}

	bigint operator--() {
		*this -= bigint(1);
		return *this;
	}

	const bigint operator++(int) {
		bigint temp = *this;
		++(*this);
		return bigint(temp);
	}

	const bigint operator--(int) {
		bigint temp = *this;
		--(*this);
		return bigint(temp);
	}

	bigint operator+() {
		return *this;
	}

	bigint operator-() {
		bigint tmp = *this;
		tmp.negative = !(tmp.negative);
		return tmp;
	}
};

ostream& operator<< (ostream& oss, bigint z) {
	if (z.digit == "0") z.negative = false;
	if (z.negative) oss << "-";
	for (i64 i=0; i<z.digit.size(); i++) oss << z.digit[i];
	return oss;
}

bigint biParse(i64 input) {
	string vs = ""; bool sign = false;
	if (input < 0) {
		sign = true; input = -input;
	}
	if (input == 0) vs = "0";
	while (input > 0) {
		i64 tmp = input % 10; input /= 10;
		vs.insert(0, 1, char(48+tmp));
	}
	return bigint(vs, sign);
}

bigint biParse(string input) {
	string vs = input; bool sign = false;
	if (vs[0] == '-') {
		sign = true; vs.erase(0, 1);
	}
	return bigint(vs, sign);
}

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/


/** -----GLOBAL VARIABLES----- **/


/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	
}

void ProSolve() {
	
}

/** -----MAIN FUNCTION----- **/
int main() {
			#ifdef Akikaze
			//freopen("FILE.INP", "r", stdin);
			//freopen("FILE.OUT", "w", stdout);
			#endif
	VarInput();
			#ifdef Akikaze
			auto TIME1 = chrono::steady_clock::now();
			#endif
	ProSolve();
			#ifdef Akikaze
			auto TIME2 = chrono::steady_clock::now();
			auto DIFF = TIME2 - TIME1;
			cout << "\n\nTime elapsed: " << chrono::duration<double>(DIFF).count() << " seconds.\n";
			#endif
	return 0;
}