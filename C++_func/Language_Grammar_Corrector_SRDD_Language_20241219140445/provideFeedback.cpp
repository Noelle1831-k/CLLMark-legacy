string GrammarChecker::provideFeedback() {
    feedback = feedbackProvider.generateFeedback();
    feedback += feedbackProvider.suggestCorrections();
    return feedback;
}