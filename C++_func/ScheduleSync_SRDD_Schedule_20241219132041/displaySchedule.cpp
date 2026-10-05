void Schedule::displaySchedule() {
    cout << "\n===== Schedule =====" << endl;
    vector<Task>::iterator it;
    for (it = tasks.begin(); it != tasks.end(); ++it) {
        it->displayTask();
    }
}