double calculate_cost() {
    double cost = 0.0;
    for (int i = 0; i < rows; i++) {
        double prediction = 0.0;
        for (int j = 0; j < cols - 1; j++) {
            prediction += theta[j] * data[i][j];
        }
        double error = prediction - data[i][cols - 1];
        cost += error * error;
    }
    return cost / (2 * rows);
}