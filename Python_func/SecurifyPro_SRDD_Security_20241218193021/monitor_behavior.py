def monitor_behavior(self):
        print("Monitoring user behavior...")
        # Simulate behavior monitoring
        user_actions = [random.choice(["login", "logout", "file_access"]) for _ in range(300)]
        unusual_activities = [action for action in user_actions if action == "file_access"]
        print(f"Unusual activities detected: {len(unusual_activities)}")