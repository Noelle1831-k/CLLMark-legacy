#define MAX 5
typedef struct {
    int x, y;
} Point;
char grid[9][MAX + 1];
const Point directions[] = {
    {0, 1},  
    {1, 0},  
    {0, -1}, 
    {-1, 0}  
};
const char moves[] = {'R', 'D', 'L', 'U'};
Point next_position(Point pos, int dir) {
    Point new_pos;
    new_pos.x = pos.x + directions[dir].x;
    new_pos.y = pos.y + directions[dir].y;
    return new_pos;
}
int is_valid(Point pos, int dir) {
    if (dir == 0 && grid[pos.x * 2][pos.y + 1] == '1') return 0;
    if (dir == 1 && grid[pos.x * 2 + 2][pos.y] == '1') return 0;
    if (dir == 2 && grid[pos.x * 2][pos.y] == '1') return 0;
    if (dir == 3 && grid[pos.x * 2][pos.y + 1] == '1') return 0;
    return 1;
}
void maze_traverse() {
    Point pos = {0, 0};
    int dir = 0;
    do {
        printf("%c", moves[dir]);
        dir = (dir + 1) % 4;
        while (!is_valid(pos, dir)) {
            dir = (dir + 3) % 4;
        }
        pos = next_position(pos, dir);
    } while (pos.x != 0 || pos.y != 0 || dir != 0);
}
int main() {
    for (int i = 0; i < 9; i++) {
        scanf("%s", grid[i]);
    }
    maze_traverse();
    return 0;
}