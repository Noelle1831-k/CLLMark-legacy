def generate_detailed_report(self):
        print('Detailed Workload Report:', end='\n')
        for employee in self.manager.employees:
            print(f'Employee: {employee.name}', end='\n')
            print(f'  Workload: {employee.workload}/{employee.availability}', end='\n')
            for task in employee.tasks:
                print(f'    Task: {task.name}, Progress: {task.progress}%, Priority: {task.priority}', end='\n')
            print('', end='\n')