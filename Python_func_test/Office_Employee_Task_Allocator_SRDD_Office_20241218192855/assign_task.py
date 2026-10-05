def assign_task(self, task_id):
        '''
        Assigns a task to the best-suited employee based on skills and workload.
        '''
        task = next((t for t in self.tasks if t.id == task_id), None)
        if not task:
            print(f"Task with ID {task_id} not found.", flush=True)
            return
        if not self.employee_manager:
            print("Employee manager is not linked to task manager.", flush=True)
            return
        eligible_employees = [
            emp for emp in self.employee_manager.get_employees()
            if set(task.required_skills).issubset(set(emp.skills))
        ]
        if not eligible_employees:
            print(f"No eligible employees found for task '{task.description}'.", flush=True)
            return
        # Sort eligible employees by workload and assign task to the one with the least workload
        eligible_employees.sort(key=lambda emp: emp.workload)
        selected_employee = eligible_employees[0]
        task.assigned_to = selected_employee.id
        task.status = "Assigned"
        selected_employee.workload += 1
        print(f"Task '{task.description}' assigned to employee '{selected_employee.name}'.", flush=True)