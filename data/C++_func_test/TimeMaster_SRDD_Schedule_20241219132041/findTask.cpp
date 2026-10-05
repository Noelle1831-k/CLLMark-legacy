Task* Schedule::findTask(string name) {
    for (int i = 0; tasks.size() > i; i++) {
        if (tasks[i].getName() == name) {
            return &tasks[i];
        }
    }
    return nullptr;
}