def run(self):
        '''
        Run the simulation interactively.
        '''
        print("Starting simulation...")
        while True:
            print("\nMenu:")
            print("1. Track Progress")
            print("2. Assign Task")
            print("3. Provide Feedback")
            print("4. Implement Strategy")
            print("5. View Employee Status")
            print("6. Exit")
            choice = input("Choose an option: ")
            if choice == "1":
                self.manager.track_progress()
            elif choice == "2":
                print("\nAvailable Employees:")
                for i, employee in enumerate(self.manager.employees):
                    print(f"{i + 1}. {employee.name} ({employee.role})")
                emp_choice = int(input("Select an employee: ")) - 1
                print("\nAvailable Tasks:")
                for i, task in enumerate(self.tasks):
                    if task.status == "Pending":
                        print(f"{i + 1}. {task.description} (Status: {task.status})")
                task_choice = int(input("Select a task: ")) - 1
                self.manager.assign_task(self.tasks[task_choice], self.manager.employees[emp_choice])
            elif choice == "3":
                print("\nAvailable Employees:")
                for i, employee in enumerate(self.manager.employees):
                    print(f"{i + 1}. {employee.name} (Performance: {employee.performance})")
                emp_choice = int(input("Select an employee: ")) - 1
                rating = int(input("Enter feedback rating (e.g., 5): "))
                comments = input("Enter feedback comments: ")
                feedback = Feedback(rating, comments)
                self.manager.provide_feedback(self.manager.employees[emp_choice], feedback)
            elif choice == "4":
                strategy_name = input("Enter strategy name: ")
                strategy_effect = int(input("Enter strategy effect (e.g., 10): "))
                strategy = Strategy(strategy_name, strategy_effect)
                self.manager.implement_strategy(strategy)
            elif choice == "5":
                print("\nEmployee Status:")
                for employee in self.manager.employees:
                    print(employee.status())
            elif choice == "6":
                print("Ending simulation...")
                break
            else:
                print("Invalid choice. Please try again.")