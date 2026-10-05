Task::Task(string t, string c, int h, int m) : title(t), category(c), hour(h), minute(m), isComplete(false) {
    id = ++idCounter;
}