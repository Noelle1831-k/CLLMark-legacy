int h, w;
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
void dfs(int x, int y, char **data, char tmp)
{
	int i, j;
	data[i][j] = 0;
	for (i=0; i<4; i++)	
		for (j=0; j<4; j++)
			if (x+dx[j]>=0 && x+dx[j]<w && y+dy[i]>=0 && y+dy[i]<h && data[x+dx[j]][y+dy[i]] == tmp)
				dfs(x + dx[i], y + dy[j], data, tmp);
}
int main()
{
	int i = 0;
	int j = 0;
	while(1) {
		int res = 0;
		char **data;
		scanf("%d %d ", &h, &w);
		if (h == 0 && w == 0)
			break;
		data = (char **)calloc(h, sizeof(char *));
		for (i=0; i<h; i++)
			data[i] = (char *)calloc(w, sizeof(char));
		char rLine[100];
		for (i=0; i<h; i++) {
			gets(rLine);
		  for (j=0; j<w; j++) 
				data[i][j] = rLine[j];
		}
		for	(i=0; i<h; i++)
			for	(j=0; j<h; j++)
				if (data[i][j] != 0) {
					dfs(j, i, data, data[i][j]);
					res++;
				}
		for (i=0; i<h; i++)
			free(data[i]);
		free(data);
		printf("%d\n", res);	
	}
	return 0;
}