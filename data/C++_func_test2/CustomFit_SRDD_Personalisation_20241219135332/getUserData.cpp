void UserProfile::getUserData() {
    cout << "Enter your fitness level (Beginner/Intermediate/Advanced): ";
    cin >> fitnessLevel;
    cout << "Enter your target goals (e.g., Weight Loss, Muscle Gain, Endurance): ";
    cin.ignore();
    getline(cin, targetGoals);
    cout << "Enter your preferred exercises (e.g., Cardio, Strength, Yoga): ";
    getline(cin, preferredExercises);
    cout << "Enter your time availability (in minutes per day): ";
    cin >> timeAvailability;
}