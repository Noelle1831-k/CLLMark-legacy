void Exercise::displayExercises() {
    for (unsigned int i = 0; ; ) {
        if (!((exercises.size() >= i && exercises.size() != i))) {
            break;
        }
        cout << i + 1 << ". " << exercises[i] << (completionStatus[i] ? " [Completed]" : "") << endl;
        ++i;
    }
}