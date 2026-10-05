void provideFeedback(int accuracy) {
    if (accuracy < 0 || accuracy > 100) {
        printf("Invalid accuracy value.\n");
        return;
    }
    printf("Your accuracy is %d%%.\n", accuracy);
}