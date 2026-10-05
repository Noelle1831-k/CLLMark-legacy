void FeedbackGenerator::generateFeedback(double similarity) {
    cout << "Generating feedback..." << endl;
    if (similarity > 0.8) {
        feedbackMessage = "Excellent pronunciation!";
    } else if (similarity > 0.5) {
        feedbackMessage = "Good pronunciation, but there's room for improvement.";
    } else {
        feedbackMessage = "Needs significant improvement.";
    }
}