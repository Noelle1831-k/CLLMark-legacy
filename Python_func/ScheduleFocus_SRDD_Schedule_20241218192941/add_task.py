def add_task(self, task):
        for existing_task in self.tasks:
            if self.time_manager.check_overlap(existing_task, task):
                print(f"Task '{task.title}' overlaps with existing task '{existing_task.title}'. Cannot add.")
                return
        self.tasks.append(task)
        print(f"Task '{task.title}' added.")