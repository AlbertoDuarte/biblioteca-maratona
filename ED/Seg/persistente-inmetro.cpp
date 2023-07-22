// botar aquele bagulho de botar tipo T?
struct ST {    
    int left[120*N], right[120*N];
    int v[120*N];
    int idx = 1;
    int id = INF;

    int f(int a, int b) {
        return min(a, b);
    }

    // Testar esse build!!!
    int build(vector<int>& vec, int lx = 0, int rx = N-1) {
        int y = idx++;
        if(rx == lx) {
            if(lx < (int)vec.size())
                v[y] = vec[lx];
            else
                v[y] = id;
            return y;
        }

        int mid = (lx+rx)/2;
        int yl = build(vec, lx, mid);
        int yr = build(vec, mid+1, rx);

        left[y] = yl;
        right[y] = yr;
        v[y] = f(v[left[y]], v[right[y]]);

        return y;
    }

    int query(int l, int r, int x, int lx = 0, int rx = N-1) {
        if(l <= lx and rx <= r) return v[x];
        if(r < lx or rx < l) return id;

        int mid = (lx+rx)/2;
        auto s1 = query(l, r, left[x], lx, mid);
        auto s2 = query(l, r, right[x], mid+1, rx);
        return f(s1, s2);
    }

    int update(int i, int val, int x, int lx = 0, int rx = N-1) {
        int y = idx++;
        if(lx == rx) {
            v[y] = val;
            return y;
        }

        int mid = (lx+rx)/2;
        if(lx <= i and i <= mid) {
            int k = update(i, val, left[x], lx, mid);
            left[y] = k;
            right[y] = right[x];
        }
        else {
            int k = update(i, val, right[x], mid+1, rx);
            left[y] = left[x];
            right[y] = k;
        }

        v[y] = f(v[left[y]], v[right[y]]);
        return y;
    }
};
