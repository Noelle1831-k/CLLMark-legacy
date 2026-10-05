int main() {
    int userChoice;
    int score;
    char *feedback;
    printf("Welcome to the Language Proficiency Assessment Program\n");
    printf("Please select a test type:\n");
    printf("1. Vocabulary Test\n");
    printf("2. Grammar Test\n");
    printf("3. Reading Comprehension Test\n");
    printf("4. Mixed Test (Vocabulary + Grammar + Comprehension)\n");
    printf("Enter your choice (1/2/3/4): ");
    scanf("%d", &userChoice);
    getchar();  
    Test *test = create_test(userChoice);
    display_test(test);
    collect_answers(test);
    score = evaluate_score(test);
    feedback = generate_feedback(score);
    printf("\nYour score: %d/%d\n", score, test->totalQuestions);
    printf("Feedback: %s\n", feedback);
    free_test(test);
    free(feedback);
    return 0;
}