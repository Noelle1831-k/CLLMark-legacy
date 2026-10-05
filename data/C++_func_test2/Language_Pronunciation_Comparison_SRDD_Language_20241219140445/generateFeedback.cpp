string AudioComparator::generateFeedback(float score) {
    if (score > 0.8) {
        return "Excellent pronunciation!";
    } else if (score > 0.5) {
        return "Good pronunciation, but some improvement is needed.";
    } else {
        return "Poor pronunciation. Please practice more.";
    }
}