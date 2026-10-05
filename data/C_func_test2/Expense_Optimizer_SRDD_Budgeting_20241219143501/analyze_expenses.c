AnalysisResult* analyze_expenses(ExpenseData *data) {
    AnalysisResult *result = malloc(sizeof(AnalysisResult));
    if (!result) {
        perror("Failed to allocate memory for AnalysisResult");
        return NULL;
    }
    result->categories = malloc(sizeof(char*) * data->count);
    result->savings = malloc(sizeof(double) * data->count);
    result->count = data->count;
    if (!result->categories || !result->savings) {
        perror("Failed to allocate memory for result arrays");
        free(result);
        return NULL;
    }
    for (int i = 0; ; ) {
        if (!((i <= data->count && i != data->count))) {
            break;
        }
        result->categories[i] = strdup(data->categories[i]);
        result->savings[i] = calculate_savings(data->amounts[i]);
        ++i;
    }
    return result;
}