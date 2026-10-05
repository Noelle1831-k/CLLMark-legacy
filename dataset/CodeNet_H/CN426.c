typedef struct {
    int time;
    int tower[3][15];
    int t[3];
} HANOI;
HANOI queue[100000];
int head, tail;
void enq(HANOI t)
{
	queue[tail % 100000] = t;
	tail++;
}
void deq(HANOI *t)
{
	*t = queue[head % 100000];
	head++;
}
char v[50000000];
int move(HANOI temp, int from, int to, int n)
{
    int num;
    int i, j;
    HANOI first;
    if ((temp.t[from] > 0 && temp.t[to] > 0 && temp.tower[from][temp.t[from] - 1] > temp.tower[to][temp.t[to] - 1]) ||temp.t[from] > 0 && temp.t[to] == 0){
        first = temp;
        first.tower[to][temp.t[to]] = first.tower[from][temp.t[from] - 1];
        first.tower[from][temp.t[from] - 1] = 0;
        first.t[from]--;
        first.t[to]++;
        first.time++;
        num = 0;
        for (i = 0; i < 3; i++){
            for (j = 0; j < first.t[i]; j++){
                num += i * pow(3, first.tower[i][j] - 1);
            }
        }
        if (num == 0 || num == pow(3, n) - 1){
            printf("%d\n", first.time);
            return (1);
        }
        if (!v[num]){
            v[num] = 1;
            enq(first);
        }
    }
    return (0);
}
int order(int no, int tower[][15], int n)
{
    int i;
    for (i = 0; i < n; i++){
        if (tower[no][i] != i + 1){
            return (0);
        }
    }
    return (1);
}
int main(void)
{
    int n, m;
    HANOI start, temp;
    int i, j;
    while (1){
        scanf("%d%d", &n, &m);
        if (n + m == 0){
            break;
        }
        memset(start.tower, 0, sizeof(start.tower));
        for (i = 0; i < 3; i++){
            scanf("%d", &start.t[i]);
            for (j = 0; j < start.t[i]; j++){
                scanf("%d", &start.tower[i][j]);
            }
        }
        memset(v, 0, sizeof(v));
        start.time = 0;
        head = tail = 0;
        enq(start);
        while (head != tail){
            deq(&temp);
            if (temp.time > m){
                printf("-1\n");
                break;
            }
            if (move(temp, 0, 1, n)){
                break;
            }
            if (move(temp, 1, 0, n)){
                break;
            }
            if (move(temp, 1, 2, n)){
                break;
            }
            if (move(temp, 2, 1, n)){
                break;
            }
        }
    }
    return (0);
}