void DataAnalyzer::displayAnalysis() {
    cout << "Your calculated wellness score is: " << wellnessScore << "/10" << endl;
    if (wellnessScore >= 8.0f) {
        cout << "You are in excellent wellness condition!" << endl;
    } else if (wellnessScore >= 5.0f) {
        cout << "You are doing well, but there is room for improvement." << endl;
    } else {
        cout << "Your wellness needs significant improvement. Consider making changes." << endl;
    }
}