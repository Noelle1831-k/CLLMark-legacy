void User::inputDetails() {
    printf("Enter your name: ");
    getline(cin, name);
    printf("Enter your age: ");
    cin >> age;
    printf("Enter your weight (in kg): ");
    cin >> weight;
    printf("Enter your height (in cm): ");
    cin >> height;
    printf("Enter your fitness goal (e.g., lose weight, gain muscle): ");
    cin.ignore(); 
    getline(cin, fitnessGoal);
}