void Schedule::removeTask(string name) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getName() == name) {
            tasks.erase(it);
            cout << "Task \"" << name << "\" removed." << endl;
            return;
        }
    }
    cout << "Task \"" << name << "\" not found." << endl;
}