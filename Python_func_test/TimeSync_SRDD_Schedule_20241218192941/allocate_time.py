def allocate_time(self, task_id, time_slot):
        self.schedule.append({'task_id': task_id, 'time_slot': time_slot})
        print(f"Time slot '{time_slot}' allocated to task ID {task_id}.")