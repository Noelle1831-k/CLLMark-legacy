def main():
    '''
    Main function to run the Healthy Habits Tracker application.
    '''
    tracker = HabitTracker()
    tips = Tips()
    # Add users
    user1 = User("Alice", 30)
    user2 = User("Bob", 10)
    tracker.add_user(user1)
    tracker.add_user(user2)
    # Set goals
    user1.set_goal("nutrition", "Eat 5 servings of vegetables")
    user1.set_goal("physical_activity", "30 minutes of exercise")
    user2.set_goal("sleep", "8 hours of sleep")
    # Input progress
    user1.input_progress("nutrition", 4)
    user1.input_progress("physical_activity", 30)
    user2.input_progress("sleep", 7)
    # Visualize progress
    viz = Visualization()
    viz.plot_progress(user1.get_progress("nutrition"), "nutrition")
    viz.plot_progress(user1.get_progress("physical_activity"), "physical_activity")
    viz.plot_progress(user2.get_progress("sleep"), "sleep")
    # Get tips
    print(tips.get_random_tip())