#define MAX_W 10
#define MAX_H 10
typedef struct {
    int cost;
    int oxygen;
} Cell;
typedef struct {
    int x, y, oxygen, cost;
} State;
int W, H, excavation_cost, max_oxygen, initial_oxygen;
Cell grid[MAX_W + 1][MAX_H + 1];
int min_cost;
void dfs(State state) {
    if (state.y == H) {
        if (state.cost < min_cost) {
            min_cost = state.cost;
        }
        return;
    }
    if (state.oxygen <= 0 || state.cost >= min_cost) {
        return;
    }
    State new_state;
    new_state.y = state.y + 1;
    new_state.oxygen = state.oxygen - 1;
    new_state.cost = state.cost;
    if (state.x > 1) {
        new_state.x = state.x - 1;
        if (grid[new_state.x][new_state.y].cost < 0) {
            new_state.cost -= grid[new_state.x][new_state.y].cost;
            dfs(new_state);
            new_state.cost += grid[new_state.x][new_state.y].cost;
        } else {
            new_state.oxygen += grid[new_state.x][new_state.y].oxygen;
            if (new_state.oxygen > max_oxygen) new_state.oxygen = max_oxygen;
            dfs(new_state);
            new_state.oxygen -= grid[new_state.x][new_state.y].oxygen;
        }
    }
    new_state.x = state.x;
    if (grid[new_state.x][new_state.y].cost < 0) {
        new_state.cost -= grid[new_state.x][new_state.y].cost;
        dfs(new_state);
        new_state.cost += grid[new_state.x][new_state.y].cost;
    } else {
        new_state.oxygen += grid[new_state.x][new_state.y].oxygen;
        if (new_state.oxygen > max_oxygen) new_state.oxygen = max_oxygen;
        dfs(new_state);
        new_state.oxygen -= grid[new_state.x][new_state.y].oxygen;
    }
    if (state.x < W) {
        new_state.x = state.x + 1;
        if (grid[new_state.x][new_state.y].cost < 0) {
            new_state.cost -= grid[new_state.x][new_state.y].cost;
            dfs(new_state);
            new_state.cost += grid[new_state.x][new_state.y].cost;
        } else {
            new_state.oxygen += grid[new_state.x][new_state.y].oxygen;
            if (new_state.oxygen > max_oxygen) new_state.oxygen = max_oxygen;
            dfs(new_state);
            new_state.oxygen -= grid[new_state.x][new_state.y].oxygen;
        }
    }
}
int find_min_cost() {
    min_cost = INT_MAX;
    for (int x = 1; x <= W; x++) {
        State initial_state = {x, 1, initial_oxygen, 0};
        dfs(initial_state);
    }
    return min_cost;
}