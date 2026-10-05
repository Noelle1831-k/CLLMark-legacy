def manage_project(project):
    while True:
        print(f"\nManaging Project: {project.name}")
        print("1. Add Task")
        print("2. Remove Task")
        print("3. List Tasks")
        print("4. Add Resource")
        print("5. Remove Resource")
        print("6. List Resources")
        print("7. Set Task Deadline")
        print("8. Set Task Priority")
        print("9. Assign Resource to Task")
        print("10. Back to Main Menu")
        choice = input("Enter your choice: ")
        if choice == '1':
            task_name = input("Enter task name: ")
            project.add_task(task_name)
        elif choice == '2':
            task_name = input("Enter task name to remove: ")
            project.remove_task(task_name)
        elif choice == '3':
            project.list_tasks()
        elif choice == '4':
            resource_name = input("Enter resource name: ")
            project.add_resource(resource_name)
        elif choice == '5':
            resource_name = input("Enter resource name to remove: ")
            project.remove_resource(resource_name)
        elif choice == '6':
            project.list_resources()
        elif choice == '7':
            task_name = input("Enter task name to set deadline: ")
            if task_name in project.tasks:
                deadline = input("Enter deadline (YYYY-MM-DD): ")
                project.tasks[task_name].set_deadline(deadline)
            else:
                print(f"Task '{task_name}' not found.")
        elif choice == '8':
            task_name = input("Enter task name to set priority: ")
            if task_name in project.tasks:
                priority = input("Enter priority (low, medium, high): ")
                project.tasks[task_name].set_priority(priority)
            else:
                print(f"Task '{task_name}' not found.")
        elif choice == '9':
            task_name = input("Enter task name to assign resource: ")
            if task_name in project.tasks:
                resource_name = input("Enter resource name to assign: ")
                if resource_name in project.resources:
                    project.tasks[task_name].assign_to(resource_name)
                    project.resources[resource_name].assign_to_task(task_name)
                else:
                    print(f"Resource '{resource_name}' not found.")
            else:
                print(f"Task '{task_name}' not found.")
        elif choice == '10':
            break
        else:
            print("Invalid choice. Please try again.")