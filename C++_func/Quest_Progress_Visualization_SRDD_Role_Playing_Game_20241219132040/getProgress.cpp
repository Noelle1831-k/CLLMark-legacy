float Quest::getProgress() {
    int completed = 0;
    for (int i = 0; i < objectivesStatus.size(); i++) {
        if (objectivesStatus[i]) {
            completed++;
        }
    }
    return (float)completed / objectivesStatus.size() * 100;
}