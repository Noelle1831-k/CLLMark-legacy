void User::setUserData() {
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your weight (kg): ";
    cin >> weight;
    cout << "Enter your height (m): ";
    cin >> height;
    cout << "Enter your activity level (1-10): ";
    cin >> activityLevel;
    cout << "Enter your daily calorie intake: ";
    cin >> calorieIntake;
}