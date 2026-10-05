#define MAX_W 30
#define MAX_H 30
#define MAX_TIME 180
typedef struct {
    int x, y, dir;
    int isActive;
} Person;
const int DIR_X[4] = {1, 0, -1, 0};
const int DIR_Y[4] = {0, -1, 0, 1};
const int DIR_R[4] = {0, 1, 2, 3};
const int DIR_L[4] = {2, 3, 0, 1};
const int DIR_B[4] = {3, 2, 1, 0};
int W, H;
char maze[MAX_H][MAX_W + 1];
Person people[MAX_W * MAX_H];
int numPeople;
void initialize() {
    numPeople = 0;
}
void adjustDirection(Person *p) {
    int options[4] = { DIR_R[p->dir], p->dir, DIR_L[p->dir], DIR_B[p->dir] };
    for (int i = 0; i < 4; i++) {
        int newDir = options[i];
        int nx = p->x + DIR_X[newDir];
        int ny = p->y + DIR_Y[newDir];
        if (maze[ny][nx] == '.' || maze[ny][nx] == 'X') {
            p->dir = newDir;
            return;
        }
    }
}
int isOccupied(int nx, int ny, int cur) {
    for (int i = 0; i < numPeople; i++) {
        if (i != cur && people[i].isActive) {
            int px = people[i].x + DIR_X[people[i].dir];
            int py = people[i].y + DIR_Y[people[i].dir];
            if (px == nx && py == ny)
                return 1;
        }
    }
    return 0;
}
int simulateEvacuation() {
    for (int time = 0; time <= MAX_TIME; time++) {
        int escaped = 0;
        for (int i = 0; i < numPeople; i++) {
            if (!people[i].isActive) continue;
            adjustDirection(&people[i]);
            int nx = people[i].x + DIR_X[people[i].dir];
            int ny = people[i].y + DIR_Y[people[i].dir];
            if (maze[ny][nx] == 'X') {
                people[i].isActive = 0;
                escaped++;
            } else if (maze[ny][nx] == '.' && !isOccupied(nx, ny, i)) {
                people[i].x = nx;
                people[i].y = ny;
                if (maze[ny][nx] == 'X') {
                    people[i].isActive = 0;
                    escaped++;
                }
            }
        }
        if (escaped == numPeople)
            return time + 1;
    }
    return -1;
}
void solve() {
    initialize();
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            switch (maze[y][x]) {
                case 'E': people[numPeople++] = (Person){x, y, 0, 1}; maze[y][x] = '.'; break;
                case 'N': people[numPeople++] = (Person){x, y, 1, 1}; maze[y][x] = '.'; break;
                case 'W': people[numPeople++] = (Person){x, y, 2, 1}; maze[y][x] = '.'; break;
                case 'S': people[numPeople++] = (Person){x, y, 3, 1}; maze[y][x] = '.'; break;
            }
        }
    }
    int result = simulateEvacuation();
    printf("%s\n", result == -1 ? "NA" : "%d", result);
}
