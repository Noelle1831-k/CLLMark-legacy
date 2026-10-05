void generateBarChart(float savings, float target) {
    int savingsBars = (savings / target) * 50; 
    if (savingsBars > 50) savingsBars = 50;
    printf("[");
    for (int i = 0; i < savingsBars; i++) {
        printf("#");
    }
    for (int i = savingsBars; i < 50; i++) {
        printf(" ");
    }
    printf("] %.2f/%.2f\n", savings, target);
}