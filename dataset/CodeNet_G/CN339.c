#define MAX_N 3000
#define MAX_M 1000
#define INF 1000000000
typedef struct {
    int price;
    int strength;
} Item;
typedef struct {
    int time;
    int strength;
} Event;
int N, M;
Item items[MAX_N];
Event events[MAX_M];
int dp[MAX_N + 1];
int max_money = -1;
int compare_items(const void *a, const void *b) {
    return ((Item *)a)->price - ((Item *)b)->price;
}
int compare_events(const void *a, const void *b) {
    return ((Event *)a)->time - ((Event *)b)->time;
}
void calculate_max_money() {
    qsort(items, N, sizeof(Item), compare_items);
    qsort(events, M, sizeof(Event), compare_events);
    int current_strength = 0;
    int current_money = 0;
    int item_index = 0;
    for (int i = 0; i <= N; ++i) {
        dp[i] = -1;
    }
    dp[0] = 0;
    for (int i = 0; i < M; ++i) {
        int required_strength = events[i].strength;
        int time_available = events[i].time;
        if (current_money + (time_available - current_money) < required_strength) {
            max_money = -1;
            return;
        }
        current_money = time_available;
        while (item_index < N && current_money >= items[item_index].price) {
            for (int j = N; j >= 0; --j) {
                if (dp[j] != -1) {
                    int new_strength = dp[j] + items[item_index].strength;
                    if (new_strength > dp[j + 1]) {
                        dp[j + 1] = new_strength;
                    }
                }
            }
            ++item_index;
        }
        for (int j = 0; j <= N; ++j) {
            if (dp[j] != -1 && dp[j] >= required_strength) {
                current_strength = dp[j];
                break;
            }
        }
        if (current_strength < required_strength) {
            max_money = -1;
            return;
        }
    }
    max_money = current_money;
}
int main() {
    calculate_max_money();
    printf("%d\n", max_money);
    return 0;
}
