def find_best_fit(self, task):
        suitable_employees = [
            emp for emp in self.employees
            if all(emp.expertise.get(skill, 0) >= level for skill, level in task.requirements.items())
        ]
        if not suitable_employees:
            return None
        return min(suitable_employees, key=lambda emp: emp.workload)