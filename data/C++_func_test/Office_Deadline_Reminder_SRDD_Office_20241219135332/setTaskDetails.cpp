void Task::setTaskDetails(int id, string name, string desc, time_t dl) {
    taskID = id;
    taskName = name;
    description = desc;
    deadline = dl;
}