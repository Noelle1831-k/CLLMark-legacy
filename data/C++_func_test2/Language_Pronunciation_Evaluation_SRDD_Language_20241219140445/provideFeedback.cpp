string PronunciationAnalyzer::provideFeedback(double score) {
    if (score > 75.0) {
        return "Excellent pronunciation!";
    } else if (score > 50.0) {
        return "Good pronunciation, but there's room for improvement.";
    } else {
        return "Needs improvement. Keep practicing!";
    }
}