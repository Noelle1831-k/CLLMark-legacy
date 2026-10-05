typedef struct {
    int number;
    double time;
} Athlete;
int compareAthletes(const void *a, const void *b) {
    Athlete *athleteA = (Athlete *)a;
    Athlete *athleteB = (Athlete *)b;
    if (athleteA->time < athleteB->time) return -1;
    if (athleteA->time > athleteB->time) return 1;
    return 0;
}
void findFinalists(Athlete *athletes) {
    Athlete topTwoEachHeat[6];
    Athlete thirdPlaces[18];
    int thirdIndex = 0;
    for (int i = 0; i < 3; i++) {
        qsort(&athletes[i * 8], 8, sizeof(Athlete), compareAthletes);
        topTwoEachHeat[i * 2] = athletes[i * 8];
        topTwoEachHeat[i * 2 + 1] = athletes[i * 8 + 1];
        for (int j = 2; j < 8; j++) {
            thirdPlaces[thirdIndex++] = athletes[i * 8 + j];
        }
    }
    qsort(thirdPlaces, 18, sizeof(Athlete), compareAthletes);
    for (int i = 0; i < 6; i++) {
        printf("%d %.2f\n", topTwoEachHeat[i].number, topTwoEachHeat[i].time);
    }
    for (int i = 0; i < 2; i++) {
        printf("%d %.2f\n", thirdPlaces[i].number, thirdPlaces[i].time);
    }
}
int main() {
    Athlete athletes[24];
    for (int i = 0; i < 24; i++) {
        scanf("%d %lf", &athletes[i].number, &athletes[i].time);
    }
    findFinalists(athletes);
    return 0;
}