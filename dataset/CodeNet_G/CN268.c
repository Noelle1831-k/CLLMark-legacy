#define MAX_C 100
#define MAX_W 300
typedef struct {
    int x, y;
} Point;
typedef struct {
    int s, t;
} Wall;
typedef struct {
    int n;             
    int distance;      
    int visited;       
    int adj[MAX_W];    
    int adjCount;      
} Room;
Point columns[MAX_C];
Wall walls[MAX_W];
Room rooms[MAX_W];
int C, W;
int manhattanDist(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}
void initGraph() {
    for (int i = 0; i < W; ++i) {
        rooms[i].n = i;
        rooms[i].distance = INT_MAX;
        rooms[i].visited = 0;
        rooms[i].adjCount = 0;
    }
}
void addEdge(int from, int to) {
    rooms[from].adj[rooms[from].adjCount++] = to;
    rooms[to].adj[rooms[to].adjCount++] = from;
}
void buildGraph() {
    for (int i = 0; i < W; ++i) {
        addEdge(walls[i].s - 1, walls[i].t - 1);
    }
}
int maxHolePasses() {
    int maxHoles = 0;
    for (int i = 0; i < W; ++i) {
        if (rooms[i].visited) continue;
        int count = 0;
        Room queue[MAX_W];
        int front = 0, back = 0;
        rooms[i].visited = 1;
        rooms[i].distance = 0;
        queue[back++] = rooms[i];
        while (front < back) {
            Room current = queue[front++];
            int dist = current.distance + 1;
            for (int j = 0; j < current.adjCount; ++j) {
                int adjRoomNum = current.adj[j];
                if (!rooms[adjRoomNum].visited) {
                    rooms[adjRoomNum].visited = 1;
                    rooms[adjRoomNum].distance = dist;
                    queue[back++] = rooms[adjRoomNum];
                }
                if (manhattanDist(columns[current.n], columns[adjRoomNum]) == 0) {
                    count++;
                }
            }
        }
        if (count > maxHoles) {
            maxHoles = count;
        }
    }
    return maxHoles;
}