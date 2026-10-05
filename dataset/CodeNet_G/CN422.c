#define MAX_N 100000
int larvae[MAX_N];
void addLarvae(int a, int b, int d) {
    for (int i = a - 1; i < b; i++) {
        larvae[i] += d;
    }
}
int hatchLarvae(int a, int b, int d) {
    int totalHatched = 0;
    for (int i = a - 1; i < b; i++) {
        if (larvae[i] < d) {
            totalHatched += larvae[i];
            larvae[i] = 0;
        } else {
            totalHatched += d;
            larvae[i] -= d;
        }
    }
    return totalHatched;
}