int find_meeting_segment(int lengths[], int num_segments, int speed1, int speed2) {
    double total_distance = 0;
    for (int i = 0; i < num_segments; i++) {
        total_distance += lengths[i];
    }
    double time1 = 0, time2 = 0;
    for (int i = 0; i < num_segments; i++) {
        time1 += (double)lengths[i] / speed1;
        time2 = (total_distance - (time1 * (speed1 + speed2) * speed1 / (speed1 * speed2))) / speed2;
        if (time1 >= time2) {
            return i + 1;
        }
    }
    return -1;
}
int main() {
    int lengths[10];
    int v1, v2;
    while (scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &lengths[0], &lengths[1], &lengths[2], &lengths[3],
                   &lengths[4], &lengths[5], &lengths[6], &lengths[7], &lengths[8], &lengths[9], &v1, &v2) == 12) {
        printf("%d\n", find_meeting_segment(lengths, 10, v1, v2));
    }
    return 0;
}