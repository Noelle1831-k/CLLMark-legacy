#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
#define MAX_N (100000)
typedef long long ll;
typedef struct {
    ll val;
    int pos;
} SEG;
SEG seg[1 << 18];
ll data[1 << 18], datb[1 << 18];
SEG dummy;
int seg_size;
void init(int N)
{
    seg_size = 1;
    while (seg_size < N){
        seg_size *= 2;
    }
    memset(seg, -1, sizeof(seg));
}
void update(int k, int x)
{
    k += seg_size - 1;
    seg[k].val = x;
    seg[k].pos = k - (seg_size - 1);
    while (k != 0){
        k = (k - 1) / 2;
        if (seg[k * 2 + 2].val > seg[k * 2 + 1].val){
            seg[k] = seg[k * 2 + 2];
        }
        else if (seg[k * 2 + 1].val > seg[k * 2 + 2].val){
            seg[k] = seg[k * 2 + 1];
        }
        else {
            seg[k] = (seg[k * 2 + 1].pos < seg[k * 2 + 2].pos) ? seg[k * 2 + 2] : seg[k * 2 + 1];
        }
    }
}
SEG query(int a, int b, int k, int l, int r)
{
    SEG vl, vr;
    if (r <= a || b <= l){
        return (dummy);
    }
    if (a <= l && r <= b){
        return (seg[k]);
    }
    else {
        vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    }
    if (vl.val > vr.val || (vl.val == vr.val && vl.pos > vr.pos)){
        return (vl);
    }
    else {
        return (vr);
    }
}
void add(int a, int b, ll x, int k, int l, int r)
{
    if (a <= l && r <= b){ 
        data[k] += x; 
    }
    else if (l < b && a < r){ 
        datb[k] += (min(b, r) - max(a, l)) * x;  
        add(a, b, x, k * 2 + 1, l, (l + r) / 2); 
        add(a, b, x, k * 2 + 2, (l + r) / 2, r); 
    }
}
ll sum(int a, int b, int k, int l, int r)
{
    if (b <= l || r <= a){ 
        return (0);
    }
    else if (a <= l && r <= b){ 
        return (data[k] * (r - l) + datb[k]);
    }
    else { 
        ll res;
        res = (min(b, r) - max(a, l)) * data[k];
        res += sum(a, b, k * 2 + 1, l, (l + r) / 2);
        res += sum(a, b, k * 2 + 2, (l + r) / 2, r);
        return (res);
    }
}
int main(void)
{
    int i, j;
    int N, H;
    int dmg, life;
    int tail;
    ll ans;
    ll sumLife;
    scanf("%d%d", &N, &H);
    init(N);
    sumLife = H;
    for (i = 0; i < N - 1; i++){
        scanf("%d%d", &dmg, &life);
        update(i, min(life, H - sumLife));
        add(i, i + 1, sumLife, 0, 0, seg_size);
        sumLife -= dmg;
    }
    add(i, i + 1, sumLife, 0, 0, seg_size);
    update(i, 0);
    dummy.val = -100000, dummy.pos = -1;
    life = H;
    ans = 0;
    tail = 0;
    for (i = 0; i < N; i++){
        while (sum(i, i + 1, 0, 0, seg_size) <= 0){
            SEG temp;
            temp = query(tail, i, 0, 0, seg_size);
            ans++;
            tail = temp.pos;
            add(temp.pos, N, temp.val, 0, 0, seg_size);
            for (j = temp.pos; j < N; j++){
                ll t = sum(j, j + 1, 0, 0, seg_size);
                if (H - t > seg[j + seg_size - 1].val){
                    continue;
                }
                update(j, min(seg[j + seg_size - 1].val, H - t));
            }
        }
    }
    printf("%d\n", ans);
    return (0);
}