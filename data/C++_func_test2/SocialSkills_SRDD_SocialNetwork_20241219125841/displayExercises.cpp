void Exercise::displayExercises() {
    for (unsigned int i = 0; i < exercises.size(); i++) {
        cout << i + 1 << ". " << exercises[i] << (completionStatus[i] ? " [Completed]" : "") << endl;
    }
}