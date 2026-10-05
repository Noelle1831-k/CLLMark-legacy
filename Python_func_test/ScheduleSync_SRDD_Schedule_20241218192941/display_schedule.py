def display_schedule(self, user):
        '''
        Displays the schedule of a user in a formatted list view.
        Parameters:
            user (User): The user whose schedule is to be displayed.
        '''
        print(f"Displaying schedule for {user.name}:")
        if not user.tasks:
            print("No tasks available to display.")
            return
        for idx, task in enumerate(user.tasks, start=1):
            print(f"{idx}. Task: {task.description}, Priority: {task.priority}, "
                  f"Time: {task.start_time} - {task.end_time}, Progress: {task.progress}%")