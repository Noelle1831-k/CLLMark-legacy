typedef struct {
    int state[30];
    int steps;
} Cube;
int is_solved(int *state) {
    for (int i = 0; i < 30; i += 3) {
        if (state[i] != state[i+1] || state[i] != state[i+2]) return 0;
    }
    return 1;
}
void rotate(int *state, int type) {
    int tmp;
    switch(type) {
        case 1: 
            tmp = state[0];
            state[0] = state[6];
            state[6] = state[24];
            state[24] = state[18];
            state[18] = tmp;
            tmp = state[1];
            state[1] = state[7];
            state[7] = state[25];
            state[25] = state[19];
            state[19] = tmp;
            tmp = state[2];
            state[2] = state[8];
            state[8] = state[26];
            state[26] = state[20];
            state[20] = tmp;
            break;
        case 2: 
            tmp = state[0];
            state[0] = state[12];
            state[12] = state[21];
            state[21] = state[9];
            state[9] = tmp;
            tmp = state[3];
            state[3] = state[15];
            state[15] = state[22];
            state[22] = state[10];
            state[10] = tmp;
            tmp = state[6];
            state[6] = state[18];
            state[18] = state[24];
            state[24] = state[0];
            break;
        case 3: 
            tmp = state[2];
            state[2] = state[11];
            state[11] = state[23];
            state[23] = state[14];
            state[14] = tmp;
            tmp = state[5];
            state[5] = state[17];
            state[17] = state[26];
            state[26] = state[8];
            state[8] = tmp;
            tmp = state[8];
            state[8] = state[26];
            state[26] = state[20];
            state[20] = state[2];
            break;
        case 4: 
            tmp = state[9];
            state[9] = state[21];
            state[21] = state[27];
            state[27] = state[15];
            state[15] = tmp;
            tmp = state[10];
            state[10] = state[22];
            state[22] = state[28];
            state[28] = state[16];
            state[16] = tmp;
            tmp = state[11];
            state[11] = state[23];
            state[23] = state[29];
            state[29] = state[17];
            state[17] = tmp;
            break;
    }
}
int solve_floppy_cube(int *initial) {
    std::queue<Cube> q;
    Cube start;
    memcpy(start.state, initial, sizeof(start.state));
    start.steps = 0;
    q.push(start);
    while (!q.empty()) {
        Cube curr = q.front();
        q.pop();
        if (is_solved(curr.state)) return curr.steps;
        for (int type = 1; type <= 4; type++) {
            Cube next;
            memcpy(next.state, curr.state, sizeof(curr.state));
            rotate(next.state, type);
            next.steps = curr.steps + 1;
            q.push(next);
        }
    }
    return -1;
}
