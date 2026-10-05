#define MAX_ISLANDS 20
int minTimeToDestroyAllBridges(int N, int bridges[MAX_ISLANDS-1][3]) {
    int visited[MAX_ISLANDS + 1] = {0};
    int maxTime = 0;
    void dfs(int island, int time) {
        if (visited[island])
            return;
        visited[island] = 1;
        for (int i = 0; i < N - 1; i++) {
            if (bridges[i][0] == island || bridges[i][1] == island) {
                int nextIsland = (bridges[i][0] == island) ? bridges[i][1] : bridges[i][0];
                dfs(nextIsland, time + bridges[i][2]);
            }
        }
        if (time > maxTime)
            maxTime = time;
        visited[island] = 0;
    }
    dfs(1, 0);
    return maxTime;
}