int main() {
    WellnessTracker tracker;
    cout << "Welcome to WellnessTracker!" << endl;
    cout << "This application helps you track and improve your overall wellness." << endl;
    cout << "Please follow the instructions to input your wellness data." << endl;
    tracker.collectInput();
    tracker.analyzeData();
    tracker.generateRecommendations();
    tracker.displayResults();
    cout << "Thank you for using WellnessTracker. Stay healthy and take care!" << endl;
    return 0;
}