Task::Task(string title, string category, int priority)
    : title(title), category(category), priority(priority), completed(false) {
    id = ++idCounter;
}