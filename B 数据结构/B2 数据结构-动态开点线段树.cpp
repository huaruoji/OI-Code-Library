namespace st {
    int cnt, rt[N << 2], sum[N * 60], lc[N * 60], rc[N * 60];
    void update(int &o, int l, int r, int x, int k) {
        if(!o) o = ++cnt;
        sum[o] += k;
        if(l == r) return;
        int mid = (l + r) >> 1;
        if(x <= mid) update(lc[o], l, mid, x, k);
        else update(rc[o], mid + 1, r, x, k);
    }
}
