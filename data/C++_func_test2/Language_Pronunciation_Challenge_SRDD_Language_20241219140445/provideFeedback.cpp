void FeedbackSystem::provideFeedback(double accuracy) {
    cout << "Your pronunciation accuracy is: " << accuracy << "%" << endl;
    if (accuracy >= 90) {
        cout << "Excellent! Keep up the great work!" << endl;
    } else if (accuracy >= 70) {
        cout << "Good job! You're making progress, but there's room for improvement." << endl;
        cout << "Focus on pronunciation of specific sounds and intonation." << endl;
    } else if (accuracy >= 50) {
        cout << "You're doing okay, but there's quite a bit of room for improvement." << endl;
        cout << "Try to focus on common mistakes in this language." << endl;
    } else {
        cout << "Your pronunciation needs work. Keep practicing!" << endl;
        cout << "Consider listening to the native audio more closely and imitating the sounds." << endl;
    }
}