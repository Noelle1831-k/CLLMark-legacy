def main():
    manager = AchievementManager()
    reminders = ReminderSystem()
    while True:
        print("\nOptions: add, update, complete, view_progress, view_rewards, add_reminder, notify, exit")
        action = input("Choose an action: ").strip().lower()
        if action == "add":
            name = input("Enter achievement name: ")
            description = input("Enter description: ")
            category = input("Enter category: ")
            tags = input("Enter tags (comma-separated): ").split(',')
            deadline = input("Enter deadline (YYYY-MM-DD): ")
            manager.add_achievement(name, description, category, tags, deadline)
        elif action == "update":
            name = input("Enter achievement name to update: ")
            description = input("Enter new description (leave blank to skip): ")
            category = input("Enter new category (leave blank to skip): ")
            tags = input("Enter new tags (comma-separated, leave blank to skip): ").split(',')
            deadline = input("Enter new deadline (YYYY-MM-DD, leave blank to skip): ")
            manager.update_achievement(name, description=description or None, category=category or None, tags=tags or None, deadline=deadline or None)
        elif action == "complete":
            name = input("Enter achievement name to complete: ")
            manager.complete_achievement(name)
        elif action == "view_progress":
            manager.view_progress()
        elif action == "view_rewards":
            manager.view_rewards()
        elif action == "add_reminder":
            name = input("Enter achievement name for reminder: ")
            date = input("Enter reminder date (YYYY-MM-DD): ")
            reminders.add_reminder(name, date)
        elif action == "notify":
            reminders.notify_user()
        elif action == "exit":
            break
        else:
            print("Invalid action. Please try again.")