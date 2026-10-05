Question* load_questions(int *count) {
    FILE *file = fopen("questions.txt", "r");
    if (!file) {
        printf("Error opening questions file.\n");
        return NULL;
    }
    if (fscanf(file, "%d", count) != 1) {
        printf("Error reading question count.\n");
        fclose(file);
        return NULL;
    }
    Question *questions = malloc(sizeof(Question) * (*count));
    if (!questions) {
        printf("Memory allocation failed for questions.\n");
        fclose(file);
        return NULL;
    }
    for (int i = 0; i < *count; i++) {
        if (fscanf(file, " %[^\n]s", questions[i].text) != 1) {
            printf("Error reading question text.\n");
            free(questions);
            fclose(file);
            return NULL;
        }
        for (int j = 0; j < 4; j++) {
            if (fscanf(file, " %[^\n]s", questions[i].options[j]) != 1) {
                printf("Error reading options for question %d.\n", i + 1);
                free(questions);
                fclose(file);
                return NULL;
            }
        }
        if (fscanf(file, " %c", &questions[i].correct_option) != 1) {
            printf("Error reading correct answer for question %d.\n", i + 1);
            free(questions);
            fclose(file);
            return NULL;
        }
    }
    fclose(file);
    return questions;
}