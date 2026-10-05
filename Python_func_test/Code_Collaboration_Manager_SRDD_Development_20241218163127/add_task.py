def add_task(self, project_name, task):
        if project_name in self.projects:
            self.projects[project_name]["tasks"].append(task)
            print(f"Task {task} added to {project_name}.")
        else:
            print(f"Project {project_name} not found.")