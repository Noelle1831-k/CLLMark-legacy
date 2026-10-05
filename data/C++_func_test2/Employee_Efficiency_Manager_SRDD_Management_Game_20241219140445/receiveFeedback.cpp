void Employee::receiveFeedback(string feedback) {
    cout << "Feedback for " << name << ": " << feedback << endl;
    if (feedback.find("excellent") != string::npos) {
        productivityLevel += 10;
    } else if (feedback.find("needs improvement") != string::npos) {
        productivityLevel -= 5;
    }
}