def display_calendar_view(self, user):
        '''
        Displays the schedule in a calendar-style view.
        Parameters:
            user (User): The user whose calendar is to be displayed.
        '''
        print(f"Generating calendar view for {user.name}...")
        calendar = {}
        for task in user.tasks:
            date = task.start_time.split(" ")[0]  # Extract the date portion
            if date not in calendar:
                calendar[date] = []
            calendar[date].append(task)
        for date, tasks in sorted(calendar.items()):
            print(f"\nDate: {date}")
            for task in tasks:
                print(f"  Task: {task.description}, Time: {task.start_time} - {task.end_time}, Priority: {task.priority}")