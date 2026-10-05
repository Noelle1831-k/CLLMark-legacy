def assign_task(self, task, employee):
        '''
        Assign a task to an employee.
        '''
        task.assign_to(employee)
        self.tasks.append(task)