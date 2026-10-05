def main():
    db = Database()
    # Create a user
    user1 = User("john_doe", "john@example.com")
    db.save_user(user1)
    # Create exercises
    exercises = [
        Exercise("Push-ups", "Do push-ups for 30 seconds", 30, "Medium"),
        Exercise("Running", "Run for 5 minutes", 300, "High"),
        Exercise("Squats", "Do squats for 1 minute", 60, "Medium"),
        Exercise("Plank", "Hold a plank for 2 minutes", 120, "High")
    ]
    # Create a challenge
    challenge1 = Challenge("Weight Loss", "Lose 5 kg", 30, "High", exercises)
    user1.create_challenge(challenge1)
    db.save_challenge(challenge1)
    # Track progress and send notifications
    user1.track_progress(challenge1.id)
    user1.receive_notifications()