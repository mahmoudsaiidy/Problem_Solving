struct segTree{
private:

    struct Node{
        int x;
        Node(){};
        Node(int a): x(a){};
    };

    Node merge(Node &l, Node &r){
        Node res;
        res.x = l.x + r.x;
        return res;
    }
    int sz;
    Node skip = Node(0);
    vector<Node>seg;

    void build(int l, int r, int node, vector<int> &arr){
        if(l == r){
            if(l < arr.size()){
                seg[node].x = arr[l];
            } else {
                seg[node] = skip;
            }
            return;
        }
        int mid = l + (r - l) / 2;
        int left = 2 * node + 1;
        build(l, mid, left, arr);
        build(mid + 1, r, left + 1, arr);
        seg[node] = merge(seg[left], seg[left + 1]);
    }

    void update(int l, int r, int node, int i, int val){
        if(l == r){
            seg[node].x = val;
            return;
        }
        int mid = l + (r - l) / 2;
        int left = 2 * node + 1;
        if(i <= mid) update(l, mid, left, i, val);
        else update(mid + 1, r, left + 1, i, val);
        seg[node] = merge(seg[left], seg[left + 1]);
    }

    Node query(int l, int r, int node, int left, int right){
        if(l > right || r < left)return skip.x;
        if(l >= left && r <= right)return seg[node].x;

        int mid = l + (r - l) / 2;
        Node lf = query(l, mid, 2 * node + 1, left, right);
        Node rt = query(mid + 1, r, 2 * node + 2, left, right);
        return merge(lf, rt);
    }
public:
    segTree(vector<int>&arr){
        sz = 1;
        int n = arr.size();
        while (sz < n) sz *= 2;
        seg = vector<Node>(sz * 2, skip);
        build(0, sz - 1, 0, arr);
    }

    void update(int i, int val){
        update(0, sz - 1, 0, i, val);
    }
    Node query(int l, int r){
        return query(0, sz - 1, 0, l, r);
    }
};
