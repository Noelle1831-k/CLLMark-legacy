#define Q_MAX (400000)
typedef struct {
	char block[10][11];
    int num[3];
	int time;
} COLOR;
int head, tail;
COLOR queue[Q_MAX];
void enq(COLOR t)
{
	queue[tail++ % Q_MAX] = t;
}
void deq(COLOR *t)
{
	*t = queue[head++ % Q_MAX];
}
int conv(char c)
{
    return ((c > 'B') + (c > 'G'));
}
int x, y;
void dfs(COLOR *exm, char c, char change, int p, int q)
{
	int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
	int i;
    exm->num[conv(exm->block[q][p])]--;
    exm->num[conv(c)]++;
	exm->block[q][p] = c;
	for (i = 0; i < 4; i++){
		if (0 <= p + dx[i] && p + dx[i] < x && 0 <= q + dy[i] && q + dy[i] < y && exm->block[q + dy[i]][p + dx[i]] == change){
			dfs(exm, c, change, p + dx[i], q + dy[i]);
		}
	}
}
int main(void)
{
	COLOR puzzle, temp;
	int i, j;
	char c;
	while (1){
		scanf("%d%d", &x, &y);
		if (x + y == 0){
			break;
		}
        memset(puzzle.num, 0, sizeof(puzzle.num));
		for (i = 0; i < y; i++){
			for (j = 0; j < x; j++){
				do {
					c = getchar();
				} while (c != 'R' && c != 'G' && c != 'B');
				if (c != 'R' && c != 'G' && c != 'B'){
					return (1);
				}
				puzzle.block[i][j] = c;
                puzzle.num[conv(puzzle.block[i][j])]++;
			}
		}
		memset(queue, 0, sizeof(queue));
		head = tail = 0;
		puzzle.time = 0;
		enq(puzzle);
		while (1){
			deq(&temp);
			if (temp.num[0] == x * y || temp.num[1] == x * y || temp.num[2] == x * y){
				break;
			}
			if (temp.block[0][0] != 'R'){
				puzzle = temp;
				puzzle.time = temp.time + 1;
				dfs(&puzzle, 'R', temp.block[0][0], 0, 0);
				enq(puzzle);
			}
			if (temp.block[0][0] != 'G'){
				puzzle = temp;
				puzzle.time = temp.time + 1;
				dfs(&puzzle, 'G', temp.block[0][0], 0, 0);
				enq(puzzle);
			}
			if (temp.block[0][0] != 'B'){
				puzzle = temp;
				puzzle.time = temp.time + 1;
				dfs(&puzzle, 'B', temp.block[0][0], 0, 0);
				enq(puzzle);
			}
		}
		printf("%d\n", temp.time);
	}
	return (0);
}