def collect_data(self):
        # Collect real user data through user input
        data = {}
        data['daily_tasks'] = input("Enter your daily tasks separated by commas: ").split(',')
        data['work_hours'] = input("Enter your typical work hours (e.g., 9-5): ")
        data['preferred_breaks'] = input("Enter your preferred break times (e.g., 10:30, 15:00): ").split(',')
        return data