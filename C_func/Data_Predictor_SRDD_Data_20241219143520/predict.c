void predict() {
    double input[MAX_COLS];
    printf("Enter values for prediction (space-separated): ");
    for (int i = 0; i < cols - 1; i++) {
        if (scanf("%lf", &input[i]) != 1) {
            printf("Invalid input. Please enter numeric values.\n");
            while (getchar() != '\n'); 
            return;
        }
    }
    double result = apply_model(input);
    printf("Predicted value: %f\n", result);
}