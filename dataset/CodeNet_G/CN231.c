#define MAX_PEOPLE 100
typedef struct {
    int weight;
    int start_time;
    int end_time;
} Person;
int check_bridge(Person people[], int n) {
    int current_weight = 0;
    int max_time = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (people[i].end_time > max_time) 
            max_time = people[i].end_time;
    }
    for (int time = 0; time <= max_time; time++) {
        current_weight = 0;
        for (int i = 0; i < n; i++) {
            if (people[i].start_time <= time && time < people[i].end_time) {
                current_weight += people[i].weight;
            }
        }
        if (current_weight > 150) {
            return 0;
        }
    }
    return 1;
}
