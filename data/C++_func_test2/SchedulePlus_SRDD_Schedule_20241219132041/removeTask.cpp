void Schedule::removeTask(int id) {
    tasks.erase(remove_if(tasks.begin(), tasks.end(), [id](const Task& t) { return t.getId() == id; }), tasks.end());
}