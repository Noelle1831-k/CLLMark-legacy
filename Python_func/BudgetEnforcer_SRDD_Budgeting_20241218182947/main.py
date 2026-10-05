def main():
    # Initialize user with a name and a budget
    user = User("John Doe", 5000)
    # Initialize the budget tracker with the user
    tracker = BudgetTracker(user)
    # Load existing data
    tracker.load_data()
    # Track expenses and update gamification status
    tracker.track_expenses()
    # Generate and display a comprehensive financial report
    tracker.generate_report()
    # Save the updated data
    tracker.save_data()