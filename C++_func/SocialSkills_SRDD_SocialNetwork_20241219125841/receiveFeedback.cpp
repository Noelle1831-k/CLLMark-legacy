void User::receiveFeedback() {
    cout << "Receiving feedback based on progress..." << endl;
    if (progress.empty()) {
        cout << "You have not completed any exercises. Start with the basics!" << endl;
    } else {
        cout << "Great job, " << username << "! Keep working on your goals!" << endl;
    }
}