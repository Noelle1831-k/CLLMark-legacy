Task* Schedule::findTask(string name) {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].getName() == name) {
            return &tasks[i];
        }
    }
    return nullptr;
}