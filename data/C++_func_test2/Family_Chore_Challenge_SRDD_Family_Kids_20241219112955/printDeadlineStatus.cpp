void printDeadlineStatus() {
        if (isDeadlinePassed()) {
            cout << "This task's deadline has passed!" << endl;
        } else {
            cout << "Deadline: " << deadline << endl;
        }
    }