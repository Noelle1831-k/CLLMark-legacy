typedef struct {
	int id, score;
} team_t;
int cmp(const team_t *x, const team_t *y) {
	return y->score - x->score;
}
int main() {
	team_t team[9999];
	int n, id, i, rank, prevscore;
	for(n=0; scanf("%d,%d", &team[n].id, &team[n].score),team[n].id; n++);
	qsort(team, n, sizeof(team_t), cmp);
	while(~scanf("%d",&id)) {
		rank=0;
		prevscore=-1;
		for(i=0;i<n;i++) {
			if(team[i].score != prevscore)
				rank++;
			prevscore = team[i].score;
			if(team[i].id == id) {
				printf("%d\n", rank);
				break;
			}
		}
	}
	return 0;
}