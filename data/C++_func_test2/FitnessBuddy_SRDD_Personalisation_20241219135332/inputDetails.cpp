void User::inputDetails() {
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your weight (in kg): ";
    cin >> weight;
    cout << "Enter your height (in cm): ";
    cin >> height;
    cout << "Enter your fitness goal (e.g., lose weight, gain muscle): ";
    cin.ignore(); 
    getline(cin, fitnessGoal);
}