#include <bits/stdc++.h>

using namespace std;
namespace ExAlgo {
	template <typename T>
	inline T max(const T &a) {
		return a;
	}
	template <typename Head, typename... Tail>
	Head max(const Head &H, const Tail&... T) {
		return std::max(H, max(T...));
	}
	template <typename T>
	inline T min(const T &a) {
		return a;
	}
	template <typename Head, typename... Tail>
	Head min(const Head &H, const Tail&... T) {
		return std::min(H, min(T...));
	}
}
//using namespace ExAlgo;
namespace FastIO {
	#define gc() (iS == iT ? (iT = (iS = ibuff) + fread(ibuff, 1, SIZ, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
    const int SIZ = 1 << 21 | 1;
    char* iS, * iT, ibuff[SIZ], obuff[SIZ], * oS = obuff, * oT = oS + SIZ - 1, fu[110], c;
    int fr;
    inline void out() {
        fwrite(obuff, 1, oS - obuff, stdout);
        oS = obuff;
    }
    template<class Type>
    inline void read(Type& x) {
        x = 0;
        Type y = 1;
        for (c = gc(); (c > '9' || c < '0') && c != '-'; c = gc());
        c == '-' ? y = -1 : x = (c & 15);
        for (c = gc(); c >= '0' && c <= '9'; c = gc())
            x = x * 10 + (c & 15);
        x *= y;
    }
    template<class Type>
    inline void print(Type x, char text = '\n') {
        if (x < 0)
            * oS++ = '-', x *= -1;
        if (x == 0)
            * oS++ = '0';
        while (x)
            fu[++fr] = x % 10 + '0', x /= 10;
        while (fr)
            * oS++ = fu[fr--];
        * oS++ = text;
        out();
    }
    inline void prints(char x[], char text = '\n') {
        for (register int i = 0; x[i]; ++i)
            * oS++ = x[i];
        * oS++ = text;
        out();
    }
}
//using namespace FastIO;
namespace ExDebug {
	#ifdef HRJ
	void debug_out() { std::cerr << '\n'; }
	template <typename Head, typename... Tail>
	void debug_out(Head H, Tail... T) {
		std::cerr << ' ' << to_string(H);
		debug_out(T...);
	}
	#define debugif(con, ...) if(con) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
	#else
	#define debugif(...)
	#define debug(...)
	#endif
} 
//using namespace ExDebug;

int main() {
	
	return 0;
}
