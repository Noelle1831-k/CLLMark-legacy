#define MAX_ROOMS 15
#define MAX_DOORS 30
#define MAX_SWITCHES 12
#define INF INT_MAX
typedef struct {
    int room1;
    int room2;
} Door;
typedef struct {
    int room;
    int light_status;
    int switch_count;
    int switch_rooms[MAX_SWITCHES];
} Room;
typedef struct {
    int steps;
    char actions[100][50];
} Path;
Door doors[MAX_DOORS];
Room rooms[MAX_ROOMS];
int door_count, room_count;
int initial_light_status[MAX_ROOMS];
int adj_matrix[MAX_ROOMS][MAX_ROOMS];
int dist[MAX_ROOMS][1 << MAX_ROOMS];
char actions[MAX_ROOMS][1 << MAX_ROOMS][50];
void init() {
    memset(adj_matrix, 0, sizeof(adj_matrix));
    for (int i = 0; i < MAX_ROOMS; i++) {
        initial_light_status[i] = 0;
        for (int j = 0; j < (1 << MAX_ROOMS); j++) {
            dist[i][j] = INF;
        }
    }
}
int bfs() {
    int queue[MAX_ROOMS * (1 << MAX_ROOMS)][2];
    int front = 0, back = 0;
    queue[back][0] = 0; 
    queue[back][1] = initial_light_status[0];
    dist[0][initial_light_status[0]] = 0;
    back++;
    while (front < back) {
        int current_room = queue[front][0];
        int current_state = queue[front][1];
        front++;
        if (current_room == room_count - 1) return dist[current_room][current_state];
        for (int next_room = 0; next_room < room_count; next_room++) {
            if (adj_matrix[current_room][next_room] && (current_state & (1 << next_room))) {
                if (dist[current_room][current_state] + 1 < dist[next_room][current_state]) {
                    dist[next_room][current_state] = dist[current_room][current_state] + 1;
                    sprintf(actions[next_room][current_state], "Move to room %d", next_room + 1);
                    queue[back][0] = next_room;
                    queue[back][1] = current_state;
                    back++;
                }
            }
        }
        for (int i = 0; i < rooms[current_room].switch_count; i++) {
            int controlled_room = rooms[current_room].switch_rooms[i] - 1;
            int new_state = current_state ^ (1 << controlled_room);
            if (dist[current_room][current_state] + 1 < dist[current_room][new_state]) {
                dist[current_room][new_state] = dist[current_room][current_state] + 1;
                sprintf(actions[current_room][new_state], "Switch %s room %d", (current_state & (1 << controlled_room)) ? "off" : "on", controlled_room + 1);
                queue[back][0] = current_room;
                queue[back][1] = new_state;
                back++;
            }
        }
    }
    return INF;
}
void output_path(int exit_steps, int final_room, int final_state) {
    if (exit_steps == INF) {
        printf("Help me!\n");
    } else {
        int switch_offs = __builtin_popcountll(final_state) - 1;
        if (switch_offs > 0) {
            printf("You can not switch off all lights.\n");
            return;
        }
        printf("You can go home in %d steps.\n", exit_steps);
        int cur_steps = exit_steps;
        while (cur_steps > 0) {
            printf("%s\n", actions[final_room][final_state]);
            for (int prev_room = 0; prev_room < room_count; prev_room++) {
                if (adj_matrix[prev_room][final_room]) {
                    if (dist[prev_room][final_state] + 1 == dist[final_room][final_state]) {
                        final_room = prev_room;
                        break;
                    }
                }
            }
            cur_steps--;
        }
    }
}
void solve() {
    init();
    for (int i = 0; i < door_count; i++) {
        int r1 = doors[i].room1 - 1;
        int r2 = doors[i].room2 - 1;
        adj_matrix[r1][r2] = adj_matrix[r2][r1] = 1;
    }
    for (int i = 0; i < room_count; i++) {
        initial_light_status[i] = rooms[i].light_status ? (1 << i) : 0;
    }
    int steps_to_exit = bfs();
    int final_room = room_count - 1;
    int found = 0, final_state;
    for (int state = 0; state < (1 << room_count); state++) {
        if (dist[final_room][state] != INF) {
            found = 1;
            final_state = state;
            break;
        }
    }
    if (!found) {
        printf("Help me!\n");
    } else {
        output_path(steps_to_exit, final_room, final_state);
    }
}