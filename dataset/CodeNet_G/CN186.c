void calculateChickenAmounts(int q1, int b, int c1, int c2, int q2) {
    int aizuchidori = 0, normalchicken = 0;
    int found = 0;
    for (aizuchidori = q2; aizuchidori >= 0; --aizuchidori) {
        int remaining_budget = b - (aizuchidori * c1);
        if (remaining_budget < 0) continue; 
        normalchicken = remaining_budget / c2; 
        if (aizuchidori * 100 + normalchicken * 100 >= q1 * 100) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("%d %d\n", aizuchidori, normalchicken);
    } else {
        printf("NA\n");
    }
}