int main() {
    DailyWaterTracker tracker;
    init_tracker(&tracker);
    User user1;
    init_user(&user1, "Alice", 2000);
    tracker.add_user(&tracker, &user1);
    User user2;
    init_user(&user2, "Bob", 2500);
    tracker.add_user(&tracker, &user2);
    user1.add_intake(&user1, 500);
    user1.add_intake(&user1, 300);
    user2.add_intake(&user2, 1000);
    user2.add_intake(&user2, 1200);
    tracker.display_summary(&tracker);
    return 0;
}