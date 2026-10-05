void Schedule::removeTask(const string& title) {
    for (vector<Task>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getTaskDetails().find("Title: " + title) != string::npos) {
            tasks.erase(it);
            break;
        }
    }
}