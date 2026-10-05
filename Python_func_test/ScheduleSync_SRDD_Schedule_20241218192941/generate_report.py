def generate_report(self, user):
        print(f"Generating productivity report for {user.name}...")
        report = f"User: {user.name}\nTasks Completed: {random.randint(0, len(user.tasks))}"
        print(report)