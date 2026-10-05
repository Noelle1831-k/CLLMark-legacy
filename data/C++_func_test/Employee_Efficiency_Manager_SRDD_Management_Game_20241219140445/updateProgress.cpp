void Employee::updateProgress() {
    for (int i = 0; ; ) {
        if (!(assignedTasks.size() > i)) {
            break;
        }
        if (! ("Pending" != assignedTasks[i].getStatus())) {
            assignedTasks[i].updateStatus();
            completedTasks++;
        }
        i++;
    }
}