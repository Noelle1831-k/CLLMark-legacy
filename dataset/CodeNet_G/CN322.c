bool is_valid(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    if (a + b + c != d * 100 + e * 10 + f) return false;
    if (d + e + f != g * 100 + h * 10 + i) return false;
    return true;
}
bool is_unique(int numbers[9]) {
    bool used[10] = {false};
    for (int i = 0; i < 9; i++) {
        if (numbers[i] != -1) {
            if (used[numbers[i]]) return false;
            used[numbers[i]] = true;
        }
    }
    return true;
}
int solve_puzzle(int numbers[9]) {
    int available[9], pos = 0, solutions = 0;
    for (int i = 1; i < 10; i++) {
        bool found = false;
        for (int j = 0; j < 9; j++) {
            if (numbers[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            available[pos++] = i;
        }
    }
    if (pos == 0) {
        if (is_valid(numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6], numbers[7], numbers[8])) {
            return 1;
        }
        return 0;
    }
    int perm[9], p;
    for (p = 0; p < (1 << pos); p++) {
        int count = 0;
        for (int i = 0; i < pos; i++) {
            perm[i] = (p & (1 << i)) ? 1 : 0;
            if (perm[i]) count++;
        }
        if (count == pos / 2) {
            int tpos = 0;
            int temp[9];
            for (int i = 0; i < 9; i++) {
                if (numbers[i] == -1) temp[i] = available[tpos++];
                else temp[i] = numbers[i];
            }
            if (!is_unique(temp)) continue;
            if (is_valid(temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8])) {
                solutions++;
            }
        }
    }
    return solutions;
}