int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter the URL or text of the news article: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitize_input(input);
    Article article = parse_article(input);
    if (article.valid == 0) {
        printf("Error: Unable to parse the article.\n");
        return 1;
    }
    double source_score = evaluate_source(article.source);
    double bias_score = analyze_bias(article.content);
    double factual_score = analyze_factual_accuracy(article.content);
    double language_score = analyze_language(article.content);
    double final_score = aggregate_scores(source_score, bias_score, factual_score, language_score);
    printf("Trustworthiness Score: %.2f\n", final_score);
    display_explanation(source_score, bias_score, factual_score, language_score);
    return 0;
}