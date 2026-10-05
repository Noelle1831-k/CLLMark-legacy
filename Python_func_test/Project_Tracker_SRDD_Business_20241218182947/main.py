def main():
    project_manager = ProjectManager()
    communication = Communication()
    # Simulate user interaction
    project_manager.create_project("Project Alpha")
    project_manager.add_task("Project Alpha", "Design UI", "Alice", "2023-12-01")
    project_manager.add_task("Project Alpha", "Develop Backend", "Bob", "2023-12-15")
    project_manager.update_task_status("Project Alpha", "Design UI", "In Progress")
    project_manager.generate_report("Project Alpha")
    communication.send_message("Alice", "Bob", "Please review the UI design.")
    communication.send_message("Bob", "Alice", "UI design looks good. Proceeding with backend development.")