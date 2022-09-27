string times(int n, int base) {
	if(n < base) return string(1, str[n]); // 利用 string 类的构造函数 
	else return times(n / base, base) + string(1, str[n % base]);
}
