def generate_detailed_report(self):
        print("Detailed Workload Report:")
        for employee in self.manager.employees:
            print(f"Employee: {employee.name}")
            print(f"  Workload: {employee.workload}/{employee.availability}")
            for task in employee.tasks:
                print(f"    Task: {task.name}, Progress: {task.progress}%, Priority: {task.priority}")
            print("")