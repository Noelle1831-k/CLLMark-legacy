def add_task(self, name, start_date, end_date):
        self.tasks[name] = {'start_date': start_date, 'end_date': end_date, 'progress': 0}
        print(f"Task '{name}' added.")