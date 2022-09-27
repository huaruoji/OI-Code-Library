int _(int x) { return x + (x >> 31 & D); } // doesn't work when x = 0
void add(int &a, ll b) { a = (a + b) % D; }
void sub(int &a, ll b) { a = (a - b) % D; }
void mul(int &a, int b) { a = (ll)a * b % D; }
//test