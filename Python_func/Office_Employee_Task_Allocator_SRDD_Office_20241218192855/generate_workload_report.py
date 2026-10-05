def generate_workload_report(self):
        '''
        Prints a report of employee workloads.
        '''
        employees = self.employee_manager.get_employees()
        print("\nWorkload Report:")
        print("-" * 50)
        for employee in employees:
            print(f"Employee ID: {employee.id}, Name: {employee.name}, Workload: {employee.workload}")
        print("-" * 50)