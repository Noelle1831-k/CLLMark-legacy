double Quest::getProgress() {
    int completed = 0;
    for (size_t i = 0; i < completedObjectives.size(); i++) {
        if (completedObjectives[i]) {
            completed++;
        }
    }
    return (completedObjectives.empty()) ? 0.0 : (static_cast<double>(completed) / objectives.size()) * 100.0;
}