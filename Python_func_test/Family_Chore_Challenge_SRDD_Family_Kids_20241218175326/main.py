def main():
    # Initialize components
    chore_manager = ChoreManager()
    leaderboard = Leaderboard(chore_manager)
    achievement_system = AchievementSystem()
    # Create users
    parent = User("Parent", "parent")
    child1 = User("Child1", "child")
    child2 = User("Child2", "child")
    # Add chores
    chore_manager.add_chore("Wash Dishes", 10, "2023-11-01")
    chore_manager.add_chore("Clean Room", 15, "2023-11-02")
    # Assign chores to children
    chore_manager.assign_chore("Wash Dishes", child1)
    chore_manager.assign_chore("Clean Room", child2)
    # Simulate chore completion
    chore_manager.complete_chore("Wash Dishes", child1)
    chore_manager.complete_chore("Clean Room", child2)
    # Update leaderboard
    leaderboard.update_leaderboard(chore_manager.get_completed_chores())
    # Display leaderboard
    leaderboard.display()
    # Check achievements
    achievement_system.check_achievements(child1)
    achievement_system.check_achievements(child2)