void Schedule::displaySchedule() const {
    for (vector<Task>::const_iterator it = tasks.begin(); ! (tasks.end() == it); ++it) {
        cout << it->getTaskDetails() << endl;
    }
}