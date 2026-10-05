void removeTask(const string& taskName) {
        for (vector<Task>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->getName() == taskName) {
                tasks.erase(it);
                break;
            }
        }
    }