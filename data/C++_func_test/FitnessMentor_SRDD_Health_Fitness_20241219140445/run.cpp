void FitnessMentorApp::run() {
    displayWelcomeMessage();
    string name, goal, level;
    vector<string> equipment = {"Dumbbells"};
    int duration = 30, age;
    double weight, height;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your fitness goal: ";
    cin >> goal;
    cout << "Enter your fitness level (Beginner/Intermediate/Advanced): ";
    cin >> level;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your weight (kg): ";
    cin >> weight;
    cout << "Enter your height (cm): ";
    cin >> height;
    User user(name, goal, level, equipment, duration, age, weight, height);
    addUser(user);
    generateWorkoutPlan(user);
}