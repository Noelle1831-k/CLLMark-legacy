def allocate_time(self, task_name, start_time, end_time):
        self.schedule[task_name] = {
            "start_time": start_time,
            "end_time": end_time
        }