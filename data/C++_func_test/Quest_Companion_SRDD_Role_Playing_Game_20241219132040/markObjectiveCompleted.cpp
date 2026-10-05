void Quest::markObjectiveCompleted(int index) {
    if (index >= 0 && index < completedObjectives.size()) {
        completedObjectives[index] = true;
    }
}