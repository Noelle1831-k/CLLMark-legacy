void ExerciseManager::loadExercise(int index) {
    if (index < exercises.size()) {
        cout << "Loading exercise: " << exercises[index] << endl;
        currentExerciseIndex = index;
    } else {
        cout << "Invalid exercise index!" << endl;
    }
}