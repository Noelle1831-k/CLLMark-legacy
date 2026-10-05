def add_task(self, task_name, start_time, end_time):
        self.task_id_counter += 1
        self.tasks[self.task_id_counter] = {
            'name': task_name,
            'start_time': start_time,
            'end_time': end_time
        }
        print(f"Task '{task_name}' added with ID {self.task_id_counter}.")