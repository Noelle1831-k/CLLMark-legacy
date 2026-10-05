def create_task(self, name, deadline):
        self.tasks[name] = {'deadline': deadline, 'progress': 0}
        print(f"Task '{name}' created with deadline {deadline}.")