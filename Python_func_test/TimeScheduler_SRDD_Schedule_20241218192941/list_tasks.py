def list_tasks(self):
        for name, details in self.tasks.items():
            print(f"Task: {name}, Start: {details['start_date']}, End: {details['end_date']}, Progress: {details['progress']}%")