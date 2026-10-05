void ShotAnalysis::provideFeedback(double accuracy) {
    if (accuracy > 90) {
        cout << "Excellent shot! Keep it up!" << endl;
    } else if (accuracy > 70) {
        cout << "Good shot! Try to improve your consistency." << endl;
    } else {
        cout << "Needs improvement. Focus on your form and aim." << endl;
    }
}