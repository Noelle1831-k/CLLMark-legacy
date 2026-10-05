void gradient_descent() {
    for (int iter = 0; iter < MAX_ITERATIONS; iter++) {
        double gradients[MAX_COLS] = {0};
        for (int i = 0; i < rows; i++) {
            double prediction = 0.0;
            for (int j = 0; j < cols - 1; j++) {
                prediction += theta[j] * data[i][j];
            }
            double error = prediction - data[i][cols - 1];
            for (int j = 0; j < cols - 1; j++) {
                gradients[j] += error * data[i][j];
            }
        }
        for (int j = 0; j < cols - 1; j++) {
            theta[j] -= LEARNING_RATE * gradients[j] / rows;
        }
        if (iter % 100 == 0) {
            printf("Iteration %d, Cost: %f\n", iter, calculate_cost());
        }
    }
}