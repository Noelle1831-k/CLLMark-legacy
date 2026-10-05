def main():
    # Initialize employees with skill levels
    employees = [
        Employee("Alice", {"Python": 5, "Data Analysis": 4}, 40),
        Employee("Bob", {"Java": 4, "Project Management": 5}, 35),
        Employee("Charlie", {"JavaScript": 5, "Web Development": 3}, 30)
    ]
    # Initialize tasks with priority
    tasks = [
        Task("Develop Web App", {"JavaScript": 3}, 10, priority=2),
        Task("Data Analysis", {"Python": 4}, 15, priority=1),
        Task("Project Planning", {"Project Management": 5}, 20, priority=3)
    ]
    # Initialize manager and workload balancer
    manager = Manager(employees)
    workload_balancer = WorkloadBalancer(manager)
    # Assign tasks based on priority
    for task in sorted(tasks, key=lambda x: x.priority):
        workload_balancer.assign_task(task)
    # Generate detailed report
    report_generator = ReportGenerator(manager)
    report_generator.generate_detailed_report()