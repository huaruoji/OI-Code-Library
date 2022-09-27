const int N = 1e6 + 5;
char s[N], t[N];
int fail[N];

int main() {
	#ifndef HRJ
	ios::sync_with_stdio(false); cin.tie(0);
	#endif
	scanf("%s%s", s + 1, t + 1);
	int j = 0, lenS = strlen(s + 1), lenT = strlen(t + 1);
	for(int i = 2; i <= lenT; i++) {
		while(j && t[i] != t[j + 1]) j = fail[j];
		if(t[i] == t[j + 1]) ++j;
		fail[i] = j;
	}
	j = 0;
	for(int i = 1; i <= lenS; i++) {
		while(j && s[i] != t[j + 1]) j = fail[j];
		if(s[i] == t[j + 1]) ++j;
		if(j == lenT) {
			cout << i - lenT + 1 << '\n';
			j = fail[j];
		}
	}
	for(int i = 1; i <= lenT; i++) cout << fail[i] << ' ';

    return 0;
}
