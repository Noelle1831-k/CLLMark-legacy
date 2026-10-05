void WorkoutPlan::displayPlan() const {
    for (int i = 0; i < exercises.size(); ++i) {
        cout << exercises[i].getName() << ": " << exercises[i].getInstructions() << endl;
    }
}