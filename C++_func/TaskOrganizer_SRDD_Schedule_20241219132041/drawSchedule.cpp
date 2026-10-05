void Visualizer::drawSchedule(vector<Task> tasks) {
    cout << "----------------------------------" << endl;
    cout << "       Task Schedule View         " << endl;
    cout << "----------------------------------" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "[" << i << "] ";
        tasks[i].printTask();
        cout << "----------------------------------" << endl;
    }
}