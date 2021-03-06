struct UnionFind {
    vector<int> data;

    UnionFind(int sz) { data.assign(sz, -1); }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y)
            return (false);
        if(data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    int find(int k) {
        if(data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }
    bool isSame(int x, int y) { return find(x) == find(y); }
    ll size(int k) { return (-data[find(k)]); }
};
// ref::https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
