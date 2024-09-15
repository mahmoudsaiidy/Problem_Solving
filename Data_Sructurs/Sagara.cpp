const int mod = 1e9 + 7;
 
int add(int a, int b) {
    int res = a + b;
    if (res >= mod) res -= mod;
    if (res < 0) res += mod;
    return res;
}
 
struct Node {
    array<int, 3> s;
    int ign = 0, lazy = 0;
    bool isLazy = 0;
 
    Node() { s.fill(0); }
 
    Node(ll x) {
        s[0] = x;
        s[1] = s[0] * x % mod;
        s[2] = s[1] * x % mod;
    }
 
    void push(int x, int lx, int rx) {
        s[2] = add(s[2], x * s[1] * 3 % mod);
        s[2] = add(s[2], s[0] * x * 3 % mod * x % mod);
        s[2] = add(s[2], x * x % mod * x % mod * (rx - lx) % mod);
 
        s[1] = add(s[1], x * s[0] * 2 % mod);
        s[1] = add(s[1], x * x % mod * (rx - lx) % mod);
 
        s[0] = add(s[0], x * (rx - lx) % mod);
        lazy = add(lazy, x);
        isLazy = 1;
    }
};
 
#define lNode (x * 2 + 1)
#define rNode (x * 2 + 2)
#define md (lx + (rx - lx) / 2)
 
struct Sagara {
    int n;
    vector<Node> node;
 
    Sagara(int sz) {
        n = 1;
        while (n < sz) n *= 2;
        node.assign(n * 2, Node());
    }
 
    Node merge(Node &l, Node &r) {
        Node res = Node();
        for (int i = 0; i < 3; ++i) {
            res.s[i] = l.s[i] + r.s[i];
            if (res.s[i] >= mod) res.s[i] -= mod;
        }
        return res;
    }
 
    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1 || !node[x].isLazy) return;
 
        node[lNode].push(node[x].lazy, lx, md);
        node[rNode].push(node[x].lazy, md, rx);
 
        node[x].isLazy = node[x].lazy = 0;
    }
 
    void update(int l, int r, ll val, int x, int lx, int rx) {
        propagate(x, lx, rx);
 
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r)
            return node[x].push(val, lx, rx);
 
        update(l, r, val, lNode, lx, md);
        update(l, r, val, rNode, md, rx);
 
        node[x] = merge(node[lNode], node[rNode]);
    }
 
    void update(int l, int r, ll val) { update(l, r, val, 0, 0, n); }
 
    Node query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
 
        if (lx >= l && rx <= r) return node[x];
        if (lx >= r || rx <= l) return Node();
 
        Node L = query(l, r, lNode, lx, md);
        Node R = query(l, r, rNode, md, rx);
 
        return merge(L, R);
    }
 
    Node query(int l, int r) {
        return query(l, r, 0, 0, n);
    }
};
 
