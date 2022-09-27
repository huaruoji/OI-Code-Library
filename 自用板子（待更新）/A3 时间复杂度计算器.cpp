#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	double n;
	cin>>n;
	double lg=log2(n);
	printf("O(log n) = %.2f\n",lg); 
	printf("O(n) = %.2f\n",n); 
	printf("O(n log log n) = %.2f\n",n*log2(lg));
	printf("O(n log n) = %.2f\n",n*lg); 
	printf("O(n log^2 n) = %.2f\n",n*lg*lg); 
	printf("O(n^2) = %.2f\n",n*n);
	printf("O(n^3) = %.2f\n",n*n*n);
	printf("O(n^4) = %.2f\n",n*n*n*n);
	double fac=1;
	for(int i=1;i<=int(n);i++) fac*=2;
	printf("O(2^n) = %.2f\n",fac);
	fac=1;
	for(int i=(int)n;i>=1;i--) fac*=i;
	printf("O(n!) = %.2f\n",fac);
	
	return 0;
}
