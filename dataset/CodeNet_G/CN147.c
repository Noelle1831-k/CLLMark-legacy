#define GROUP_SIZE 100
#define SEAT_COUNT 17
int arrival_time(int i) {
    return 5 * i;
}
int group_size(int i) {
    return (i % 5 == 1) ? 5 : 2;
}
int eating_time(int i) {
    return 17 * (i % 2) + 3 * (i % 3) + 19;
}
int waiting_time(int target_group) {
    int seat[SEAT_COUNT] = {0};
    int queue[GROUP_SIZE];
    int front = 0, rear = 0;
    int time = 0;
    int wait_time[GROUP_SIZE] = {0};
    for (int i = 0; i < GROUP_SIZE; ++i) {
        queue[rear++] = i;
    }
    for (int group = 0; group < GROUP_SIZE; ++group) {
        int arrival = arrival_time(group);
        while (time < arrival && front < rear) {
            for (int s = 0; s < SEAT_COUNT; ++s) {
                if (seat[s] > 0 && seat[s] <= time) {
                    seat[s] = 0;
                }
            }
            int can_seat = 1;
            for (int q = front; q < rear; ++q) {
                int current_group = queue[q];
                int group_members = group_size(current_group);
                int seated = 0;
                for (int s = 0; s <= SEAT_COUNT - group_members; ++s) {
                    int can_sit = 1;
                    for (int g = 0; g < group_members; ++g) {
                        if (seat[s + g] != 0) {
                            can_sit = 0;
                            break;
                        }
                    }
                    if (can_sit) {
                        wait_time[current_group] = time - arrival_time(current_group);
                        seated = 1;
                        for (int g = 0; g < group_members; ++g) {
                            seat[s + g] = time + eating_time(current_group);
                        }
                        if (q == front) {
                            for (int p = front; p < rear - 1; ++p) {
                                queue[p] = queue[p + 1];
                            }
                            rear--;
                            break;
                        }
                    }
                    if (seated) {
                        break;
                    }
                }
                if (!seated) {
                    can_seat = 0;
                    break;
                }
            }
            if (can_seat) {
                time++;
            } else {
                break;
            }
        }
        if (group == target_group) {
            return wait_time[target_group];
        }
    }
    return 0;
}
int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        printf("%d\n", waiting_time(n));
    }
    return 0;
}
