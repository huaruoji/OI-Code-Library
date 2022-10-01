#include <bits/stdc++.h>
#define compile
typedef long long ll;

using namespace std;

int main() {
	#ifdef compile
	system("g++ make.cpp -o make.exe -std=c++14 -Wall -Wextra");
	system("g++ good.cpp -o good.exe -std=c++14 -Wall -Wextra");
	system("g++ force.cpp -o force.exe -std=c++14 -Wall -Wextra");
	#endif
	for(int T=1;T<=10000;T++) {
		system("make.exe > data.in");
		double st=clock();
		system("good.exe < data.in > good.out");
		double ed=clock();
		system("force.exe < data.in > force.out");
		if(system("fc good.out force.out")) {
			puts("Wrong Answer");
			return 0;
		} else {
			printf("Accepeted, #%d : %.0lfms\n",T,ed-st);
		}
	}
	
	return 0;
} 
