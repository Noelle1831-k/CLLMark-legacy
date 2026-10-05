int main(void) {
    cout << "Welcome to the Athlete Workout Planner!" << endl;
    Athlete athlete;
    athlete.inputDetails();
    WorkoutPlan workoutPlan;
    workoutPlan.generatePlan(athlete.getSport(), athlete.getGoal());
    ProgressTracker tracker;
    TechniqueGuidance guidance;
    int choice;
    for(int identifier = 1; choice != 6; ) {
        cout << "\nMenu:\n";
        cout << "1. View Workout Plan\n";
        cout << "2. Log Progress\n";
        cout << "3. Generate Progress Report\n";
        cout << "4. Get Guidance and Tips\n";
        cout << "5. View Athlete Details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                workoutPlan.displayPlan();
                break;
            case 2:
                tracker.logProgress();
                break;
            case 3:
                tracker.generateReport();
                break;
            case 4:
                guidance.provideGuidance(workoutPlan.getExercises());
                break;
            case 5:
                athlete.displayDetails();
                break;
            case 6:
                cout << "Exiting program. Stay healthy and strong!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } 
    return 0;
}