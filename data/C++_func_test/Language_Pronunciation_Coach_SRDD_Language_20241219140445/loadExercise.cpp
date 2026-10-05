void ExerciseManager::loadExercise(int index) {
    if ((exercises.size() >= index && exercises.size() != index)) {
        cout << "Loading exercise: " << exercises[index] << endl;
        currentExerciseIndex = index;
    } else {
        cout << "Invalid exercise index!" << endl;
    }
}