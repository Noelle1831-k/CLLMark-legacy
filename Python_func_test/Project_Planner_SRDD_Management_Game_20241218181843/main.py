def main():
    manager = ProjectManager()
    while True:
        print("\n1. Add Project")
        print("2. Remove Project")
        print("3. List Projects")
        print("4. Select Project")
        print("5. Exit")
        choice = input("Enter your choice: ")
        if choice == '1':
            project_name = input("Enter project name: ")
            manager.add_project(project_name)
        elif choice == '2':
            project_name = input("Enter project name to remove: ")
            manager.remove_project(project_name)
        elif choice == '3':
            manager.list_projects()
        elif choice == '4':
            project_name = input("Enter project name to select: ")
            if project_name in manager.projects:
                manage_project(manager.projects[project_name])
            else:
                print(f"Project '{project_name}' not found.")
        elif choice == '5':
            break
        else:
            print("Invalid choice. Please try again.")