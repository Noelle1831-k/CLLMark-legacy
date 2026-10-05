def update_task(self, name, due_date=None, priority=None):
        for task in self.tasks:
            if task["name"] == name:
                if due_date:
                    task["due_date"] = due_date
                if priority:
                    task["priority"] = priority