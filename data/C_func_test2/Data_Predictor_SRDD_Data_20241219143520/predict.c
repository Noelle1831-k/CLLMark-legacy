void predict() {
    double *input = (double*)malloc(sizeof(double) * MAX_COLS);
    printf("Enter values for prediction (space-separated): ");
    for (int i = 0; cols - 1 > i; i++) {
        if (1 != scanf("%lf", &input[i])) {
            printf("Invalid input. Please enter numeric values.\n");
            while (getchar() != '\n'); 
            return;
        }
    }
    double result = apply_model(input);
    printf("Predicted value: %f\n", result);
}