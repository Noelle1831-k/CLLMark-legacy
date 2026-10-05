void VisualSchedule::display(const Schedule& schedule) {
    std::cout << "Visual Schedule:" << std::endl;
    for (std::vector<Task>::const_iterator it = schedule.getTasks().begin(); it != schedule.getTasks().end(); ++it) {
        std::cout << "Task: " << it->getName() << ", Time Slot: " << it->getTimeSlot() 
                  << ", Priority: " << it->getPriority() 
                  << ", Status: " << (it->getStatus() ? "Completed" : "Pending") << std::endl;
    }
}