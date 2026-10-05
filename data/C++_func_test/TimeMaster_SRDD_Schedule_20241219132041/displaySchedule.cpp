void Schedule::displaySchedule() {
    if (tasks.empty()) {
        cout << "The schedule is empty." << endl;
    } else {
        for (int i = 0; i < tasks.size(); i++) {
            cout << "Task " << (i + 1) << ":" << endl;
            tasks[i].displayTask();
            cout << "-----------------" << endl;
        }
    }
}