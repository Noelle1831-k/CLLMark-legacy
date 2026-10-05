def display_schedule(self, schedule):
        # Display the schedule in a user-friendly format
        print("Displaying schedule:")
        for task_name, task_details in schedule.items():
            print(f"Task: {task_name}, Time Slot: {task_details['time_slot']}, Priority: {task_details['priority']}")