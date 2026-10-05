void Exercise::completeExercise() {
    int choice;
    cout << "Select an exercise to complete (1-" << exercises.size() << "): ";
    cin >> choice;
    if (choice > 0 && choice <= exercises.size()) {
        completionStatus[choice - 1] = true;
        cout << "Exercise '" << exercises[choice - 1] << "' marked as completed!" << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}