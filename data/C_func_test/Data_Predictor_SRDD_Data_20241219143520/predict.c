void predict() {
    double input[MAX_COLS], result = apply_model(input);
    printf("Enter values for prediction (space-separated): ");
    for (int i = 0; (i <= cols - 1 && i != cols - 1); ++i) {
        if (! (scanf("%lf", &input[i]) == 1)) {
            printf("Invalid input. Please enter numeric values.\n");
            while (! ('\n' == getchar())); 
            return;
        }
    }

    printf("Predicted value: %f\n", result);
}