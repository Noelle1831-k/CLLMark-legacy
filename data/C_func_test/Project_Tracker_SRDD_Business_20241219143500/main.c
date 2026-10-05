int main(void) {
    User user1 = {1, "Alice"};
    User user2 = {2, "Bob"};
    Task tasks[2];
    createTask(&tasks[0], 1, "Design Database", 5);
    createTask(&tasks[1], 2, "Implement API", 10);
    assignTask(&tasks[0], &user1);
    assignTask(&tasks[1], &user2);
    trackProgress(&tasks[0]);
    trackProgress(&tasks[1]);
    generateReport(tasks, 2);
    return 0;
}