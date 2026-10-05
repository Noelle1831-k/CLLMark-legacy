def main():
    tracker = WaterTracker()
    # Adding multiple users
    user1 = User("John Doe", 30, 70)
    user2 = User("Jane Smith", 25, 60)
    tracker.add_user(user1)
    tracker.add_user(user2)
    # Logging water intake for users
    tracker.log_water_intake(user1, 250)
    tracker.log_water_intake(user1, 500)
    tracker.log_water_intake(user2, 300)
    # Retrieving and displaying daily intake
    intake_user1 = tracker.get_user_intake(user1)
    intake_user2 = tracker.get_user_intake(user2)
    print(f"Total water intake for {user1.name}: {intake_user1} ml")
    print(f"Total water intake for {user2.name}: {intake_user2} ml")