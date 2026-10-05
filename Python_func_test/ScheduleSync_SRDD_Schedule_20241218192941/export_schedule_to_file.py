def export_schedule_to_file(self, user, filename="schedule.txt"):
        '''
        Exports the user's schedule to a text file.
        Parameters:
            user (User): The user whose schedule is to be exported.
            filename (str): The name of the file to export the schedule to.
        '''
        print(f"Exporting schedule for {user.name} to {filename}...")
        with open(filename, "w") as file:
            file.write(f"Schedule for {user.name}\n")
            file.write("=" * 30 + "\n")
            for task in user.tasks:
                file.write(f"Task: {task.description}\n")
                file.write(f"Priority: {task.priority}\n")
                file.write(f"Time: {task.start_time} - {task.end_time}\n")
                file.write(f"Progress: {task.progress}%\n")
                file.write("-" * 30 + "\n")
        print("Schedule export completed.")