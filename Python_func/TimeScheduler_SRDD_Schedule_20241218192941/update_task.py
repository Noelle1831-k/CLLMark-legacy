def update_task(self, name, start_date=None, end_date=None):
        if name in self.tasks:
            if start_date:
                self.tasks[name]['start_date'] = start_date
            if end_date:
                self.tasks[name]['end_date'] = end_date
            print(f"Task '{name}' updated.")
        else:
            print(f"Task '{name}' not found.")