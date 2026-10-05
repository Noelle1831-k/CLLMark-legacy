def add_task(self, name, due_date, priority):
        task = {
            "name": name,
            "due_date": due_date,
            "priority": priority
        }
        self.tasks.append(task)