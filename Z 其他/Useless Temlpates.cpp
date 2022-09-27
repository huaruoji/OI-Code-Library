namespace uselessTemplates {
	#define eb emplace_back
	#define fi first
	#define se second
	#define mp make_pair
	typedef __int128 i128;
	typedef __uint128_t u128;
	typedef long long ll;
	ostream& operator<<(ostream& out, const i128 &t) {
		string s; i128 r = t; int sign = 0;
		if(t < 0) sign = 1, t = -t;
		while(r) s += '0' + r % 10, r /= 10;
		if(sign) s += '-';
		reverse(s.begin(), s.end());
		if(!s.length()) s += "0";
		out << (!s.length() ? "0" : s);
		return out;
	}
	ostream& operator<<(ostream& out, const u128 &t) {
		string s; u128 r = t; int sign = 0;
		while(r) s += '0' + r % 10, r /= 10;
		reverse(s.begin(), s.end());
		if(!s.length()) s += "0";
		out << (!s.length() ? "0" : s);
		return out;
	}
	namespace DEBUG {
    void debug_out() { cerr << '\n'; }
    template <typename Head, typename... Tail>
    void debug_out(Head H, Tail... T) { cerr << ' ' << H, debug_out(T...); }
    #define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
	} using namespace DEBUG;
	namespace fastIO {
		#define getchar() (S == T && (T = (S = B) + fread(B, 1, 1 << 16, stdin), S == T) ? EOF : *S++)
		char B[1 << 16], *S = B, *T = B;
		template<typename Tp> inline void read(Tp &o) {
			o = 0; bool s = 0; char c = getchar();
			while(c > '9' || c < '0') s |= c == '-', c = getchar();
			while(c >= '0' && c <= '9') o = o * 10 + c - '0', c = getchar();
			if(s) o = -o;
		}
	} using fastIO::read;
} using namespace uselessTemplates;
