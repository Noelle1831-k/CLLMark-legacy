def add_task_for_visualization(self, task_name, start_time, end_time):
        """
        Adds a task to the visualization queue.
        :param task_name: Name of the task.
        :param start_time: Start time of the task in HH:MM format.
        :param end_time: End time of the task in HH:MM format.
        """
        start_time_dt = datetime.datetime.strptime(start_time, "%H:%M")
        end_time_dt = datetime.datetime.strptime(end_time, "%H:%M")
        if end_time_dt <= start_time_dt:
            print(f"Invalid time range for task '{task_name}'.")
            return
        self.tasks.append({
            'name': task_name,
            'start_time': start_time_dt,
            'end_time': end_time_dt
        })
        print(f"Task '{task_name}' added to visualization.")