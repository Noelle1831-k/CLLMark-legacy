int head[26], tail[26], visit[26];
int graph[26][26];
int sameNumber(void)
{
    int i;
    for (i = 0; i < 26; i++){
        if (head[i] != tail[i]){
            return (0);
        }
    }
    return (1);
}
void travelGraph(int node)
{
    int i;
    for (i = 0; i < 26; i++){
        if (graph[node][i] == 1){
            graph[node][i] = 0;
            visit[i] = 1;
            travelGraph(i);
        }
    }
}
int graphNumber(void)
{
    int i;
    int num;
    num = 0;
    for (i = 0; i < 26; i++){
        if (head[i] == 0 && tail[i] == 0){
            continue;
        }
        if (visit[i] == 0){
            num++;
            travelGraph(i);
        }
    }
    return (num);
}
int main(void)
{
    int i;
    int n;
    char str[256];
    while (1){
        scanf("%d", &n);
        if (n == 0){
            break;
        }
        memset(graph, 0, sizeof(graph));
        memset(tail, 0, sizeof(tail));
        memset(head, 0, sizeof(head));
        memset(visit, 0, sizeof(visit));
        for (i = 0; i < n; i++){
            scanf("%s", str);
            head[str[0] - 'a']++;
            tail[str[strlen(str) - 1] - 'a']++;
            graph[str[0] - 'a'][str[strlen(str) - 1] - 'a'] = 1;
            graph[str[strlen(str) - 1] - 'a'][str[0] - 'a'] = 1;
        }
        if (sameNumber() && graphNumber() == 1){
            printf("OK\n");
        }
        else {
            printf("NG\n");
        }
    }
    return (0);
}