def add_task(self, schedule, task_name, deadline, assigned_to):
        task = schedule.Task(task_name, deadline, assigned_to)
        schedule.tasks.append(task)