def add_task(self, name, description, deadline):
        task = Task(name, description, deadline)
        self.tasks.append(task)
        logging.info(f'Task "{name}" added with deadline {deadline}.')