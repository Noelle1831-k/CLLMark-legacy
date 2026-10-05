def allocate_time_slot(self, task_name, start_time, end_time):
        self.schedule[task_name] = (start_time, end_time)