void display_explanation(double source_score, double bias_score, double factual_score, double language_score) {
    printf("\nExplanation of Scores:\n");
    printf("Source Credibility: %.2f - Based on the reliability of the source.\n", source_score);
    printf("Bias Analysis: %.2f - Based on the detected bias in the content.\n", bias_score);
    printf("Factual Accuracy: %.2f - Based on the accuracy of the facts presented.\n", factual_score);
    printf("Language Analysis: %.2f - Based on the complexity and neutrality of the language used.\n", language_score);
}