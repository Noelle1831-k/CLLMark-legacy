def allocate_time_slot(self, task_name, start_time, end_time):
        '''
        Allocates a time slot for a task.
        '''
        for task in self.tasks:
            if task["name"] == task_name:
                task["time_slot"] = (start_time, end_time)
                break