char chairs[105];
int n, m;
void sit_A() {
    for (int i = 0; i < n; i++) {
        if (chairs[i] == '#') {
            chairs[i] = 'A';
            break;
        }
    }
}
void sit_B() {
    for (int i = n - 1; i >= 0; i--) {
        if (chairs[i] == '#') {
            if (i > 0 && chairs[i - 1] == 'A') continue;
            if (i < n - 1 && chairs[i + 1] == 'A') continue;
            chairs[i] = 'B';
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (chairs[i] == '#') {
            chairs[i] = 'B';
            break;
        }
    }
}
void sit_C() {
    for (int i = 0; i < n; i++) {
        if (chairs[i] != '#') {
            if (i < n - 1 && chairs[i + 1] == '#') {
                chairs[i + 1] = 'C';
                return;
            }
            if (i > 0 && chairs[i - 1] == '#') {
                chairs[i - 1] = 'C';
                return;
            }
        }
    }
    int mid = n / 2;
    if (n % 2 == 0) mid++;
    if (chairs[mid - 1] == '#') {
        chairs[mid - 1] = 'C';
    } else {
        chairs[mid] = 'C';
    }
}
void sit_D() {
    int best_index = -1;
    int best_distance = -1;
    for (int i = 0; i < n; i++) {
        if (chairs[i] == '#') {
            int left_dist = n, right_dist = n;
            for (int j = i - 1; j >= 0; j--) {
                if (chairs[j] != '#') {
                    left_dist = i - j;
                    break;
                }
            }
            for (int j = i + 1; j < n; j++) {
                if (chairs[j] != '#') {
                    right_dist = j - i;
                    break;
                }
            }
            int min_dist = (left_dist < right_dist) ? left_dist : right_dist;
            if (min_dist > best_distance) {
                best_distance = min_dist;
                best_index = i;
            }
        }
    }
    if (best_index != -1) {
        chairs[best_index] = 'D';
    } else {
        chairs[0] = 'D';
    }
}
int main() {
    while (scanf("%d %d", &n, &m) && (n || m)) {
        memset(chairs, '#', sizeof(chairs));
        chairs[n] = '\0';
        for (int i = 0; i < m; i++) {
            char passenger;
            scanf(" %c", &passenger);
            if (passenger == 'A') {
                sit_A();
            } else if (passenger == 'B') {
                sit_B();
            } else if (passenger == 'C') {
                sit_C();
            } else if (passenger == 'D') {
                sit_D();
            }
        }
        printf("%s\n", chairs);
    }
    return 0;
}