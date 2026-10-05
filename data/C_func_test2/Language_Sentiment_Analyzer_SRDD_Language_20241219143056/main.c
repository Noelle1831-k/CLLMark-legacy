int main(int argc, char *argv[]) {
    char input_text[1024];
    char *processed_text;
    int sentiment_result;
    display_ui();
    printf("Enter text to analyze sentiment: ");
    fgets(input_text, sizeof(input_text), stdin);
    input_text[strcspn(input_text, "\n")] = 0; 
    processed_text = process_text(input_text);
    sentiment_result = analyze_sentiment(processed_text);
    display_result(sentiment_result);
    return 0;
}