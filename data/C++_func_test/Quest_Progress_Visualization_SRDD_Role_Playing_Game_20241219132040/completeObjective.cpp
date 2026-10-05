void Quest::completeObjective(int index) {
    if (index >= 0 && index < objectivesStatus.size()) {
        objectivesStatus[index] = true;
    } else {
        cout << "Error: Objective index out of range." << endl;
    }
}