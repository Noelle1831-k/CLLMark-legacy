void Schedule::displaySchedule() const {
    for (vector<Task>::const_iterator it = tasks.begin(); it != tasks.end(); ++it) {
        cout << it->getTaskDetails() << endl;
    }
}