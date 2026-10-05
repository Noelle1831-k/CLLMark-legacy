def allocate_time(self):
        # Allocate time slots based on priority and due date
        for task_name, task in self.schedule.items():
            if task['priority'] == "High":
                task['time_slot'] = "09:00-10:00"
            elif task['priority'] == "Medium":
                task['time_slot'] = "10:00-11:00"
            else:
                task['time_slot'] = "11:00-12:00"