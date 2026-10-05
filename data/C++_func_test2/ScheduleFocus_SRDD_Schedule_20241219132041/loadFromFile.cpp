void Scheduler::loadFromFile() {
    ifstream inFile("schedule.txt");
    if (!inFile) {
        cout << "Error opening file for loading.\n";
        return;
    }
    tasks.clear();
    nextTaskID = 1;
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string idStr, name, start, end, priorityStr;
        getline(ss, idStr, '|');
        getline(ss, name, '|');
        getline(ss, start, '|');
        getline(ss, end, '|');
        getline(ss, priorityStr, '|');
        Task loadedTask(stoi(idStr), name, start, end, stoi(priorityStr));
        tasks.push_back(loadedTask);
        nextTaskID = max(nextTaskID, loadedTask.getID() + 1);
    }
    inFile.close();
    cout << "Schedule loaded successfully!\n";
}