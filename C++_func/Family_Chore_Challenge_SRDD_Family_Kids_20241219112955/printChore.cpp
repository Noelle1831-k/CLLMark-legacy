void printChore() {
        cout << "Chore: " << name << ", Points: " << points << ", Deadline: ";
        taskTimer->printDeadlineStatus();
    }