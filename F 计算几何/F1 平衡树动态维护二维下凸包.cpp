struct node {
	int id, flag; // flag ��¼�Ƿ��� k ���Ƚ� 
	double x, y, k;
	bool operator<(const node &b) const {
		if(flag || b.flag) { return k < b.k; }
		else return x < b.x || (x == b.x && y < b.y);
	}
};
inline double K(node &a, node &b) { return (a.y - b.y) / (a.x - b.x); }
struct hull : public multiset<node> { // �� multiset ����һģһ���ĵ�Ż���ȷ���� set �Ļ�ɾ���ʱ����������ɾ��
	double K(const iterator &a, const iterator &b) { return (a->y - b->y) / (a->x - b->x); } 
	bool inside(iterator p) {
		if(p == begin()) return false;
		auto t1 = prev(p), t2 = next(p);
		if(t1->x == p->x) return true;
		if(t2 == end()) return false;
		return K(t1, p) > K(p, t2);
	}
	iterator cge(iterator p, double k) {
		auto t = insert(node{p->id, p->flag, p->x, p->y, k});
		erase(p);
		return t;
	}
	void ins(const node &p) { // ����һ����
		auto t = insert(p);
		if(inside(t)) { erase(t); return; }
		while(t != begin() && inside(prev(t))) erase(prev(t));
		while(next(t) != end() && inside(next(t))) erase(next(t));
		
		if(t != begin()) {
			if(prev(t) == begin()) cge(prev(t), numeric_limits<double>::min());
			t = cge(t, K(prev(t), t));
		} else t = cge(t, numeric_limits<double>::min());
		if(next(t) != end()) cge(next(t), K(t, next(t)));
	}
	int find(double k) { // ��һ��б�ʿ���͹�������ر���ס�ĵ�� id
		if(empty()) return 0; // ע������ط�����������Ҫʲô�������Ū�� 0 û���� 
		else return (--lower_bound(node{0, 1, 0, 0, k}))->id;
	}
} s;
