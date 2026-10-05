def display_dashboard(self):
        # Display the main dashboard
        print("Welcome to FitnessProgress Dashboard")
        report = self.progress_tracker_manager.generate_report("JohnDoe")
        print(report)