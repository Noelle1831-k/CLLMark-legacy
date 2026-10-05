void UserInput::collectData() {
    cout << "Enter your wellness data on a scale of 1 to 10:" << endl;
    cout << "Physical activity level: ";
    cin >> physicalActivity;
    cout << "Sleep quality: ";
    cin >> sleepQuality;
    cout << "Nutrition level: ";
    cin >> nutrition;
    cout << "Stress level: ";
    cin >> stressLevel;
    cout << "Mental health level: ";
    cin >> mentalHealth;
    cout << "Thank you for providing your data!" << endl;
}