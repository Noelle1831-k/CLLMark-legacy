def main():
    '''
    Main function to initialize and run the simulation.
    '''
    # Initialize employees
    employees = [
        Employee("Alice", "Developer"),
        Employee("Bob", "Designer"),
        Employee("Charlie", "Tester")
    ]
    # Initialize manager
    manager = Manager(employees)
    # Initialize tasks
    tasks = [
        Task("Develop feature X"),
        Task("Design UI for feature Y"),
        Task("Test feature Z"),
        Task("Debug feature A"),
        Task("Research feature B")
    ]
    # Assign some tasks initially
    manager.assign_task(tasks[0], employees[0])
    manager.assign_task(tasks[1], employees[1])
    manager.assign_task(tasks[2], employees[2])
    # Initialize simulation
    simulation = Simulation(manager, tasks)
    # Run simulation
    simulation.run()