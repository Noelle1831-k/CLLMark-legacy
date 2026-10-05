int main() {
    User user("John Doe", 25);
    ProgressTracker tracker;
    FileManager fileManager;
    cout << "Welcome to FitnessProgress!" << endl;
    int choice;
    do {
        cout << "1. Add Workout\n2. View Progress\n3. Save Data\n4. Load Data\n5. Display User Info\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                Workout workout;
                workout.setWorkoutDetails();
                user.addWorkout(workout);
                tracker.updateProgress(user);
                break;
            }
            case 2:
                tracker.calculateProgress(user);
                break;
            case 3:
                fileManager.saveToFile(user);
                break;
            case 4:
                fileManager.loadFromFile(user);
                break;
            case 5:
                user.displayUserInfo();
                break;
            case 6:
                cout << "Exiting the application. Stay fit!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}