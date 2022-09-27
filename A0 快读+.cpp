namespace io {
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
using namespace io;
