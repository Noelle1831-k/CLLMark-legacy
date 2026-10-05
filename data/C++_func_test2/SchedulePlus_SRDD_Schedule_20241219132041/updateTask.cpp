void Schedule::updateTask(int id, const Task& task) {
    for (auto& t : tasks) {
        if (t.getId() == id) {
            t = task;
            break;
        }
    }
}