std::ostream& operator <<(std::ostream&out,const __int128 &b) {
  std::string s; __int128 t = b;int sig = 1;
  if(t < 0) sig = -1,t = -t;
  for(; t; t /= 10) s += '0' + t % 10;
  if(sig == -1) s += '-';
  reverse(s.begin(), s.end());
  if(s.length() == 0) s += '0';
  out << s ;
  return out;
}
std::ostream& operator <<(std::ostream&out,const __uint128_t &b) {
  std::string s; __uint128_t t = b;int sig = 1;
  for(; t; t /= 10) s += '0' + t % 10;
  if(sig == -1) s += '-';
  reverse(s.begin(), s.end());
  if(s.length() == 0) s += '0';
  out << s ;
  return out;
}
