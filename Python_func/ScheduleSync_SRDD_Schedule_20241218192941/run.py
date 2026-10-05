def run(self):
        print("Welcome to ScheduleSync!")
        # Simulate user interaction
        user = User("John Doe")
        self.users.append(user)
        user.add_task("Complete project", "High", "2023-10-10 10:00", "2023-10-10 12:00")
        self.scheduler.synchronize(user)
        self.visualizer.display_schedule(user)
        self.scheduler.send_reminder(user)
        self.scheduler.generate_report(user)