namespace FI {
#define getchar() (S == T && (T = (S = B) + fread(B, 1, 1 << 16, stdin), S == T) ? EOF : *S++)
char B[1 << 16], *S = B, *T = B;
template<typename Tp> void read(Tp &o) {
	o = 0; bool s = 0; char c = getchar();
	while(c > '9' || c < '0') s |= c == '-', c = getchar();
	while(c <= '9' && c >= '0') o = o * 10 + c - '0', c = getchar();
	if(s) o = -o;
}
} using FI::read;