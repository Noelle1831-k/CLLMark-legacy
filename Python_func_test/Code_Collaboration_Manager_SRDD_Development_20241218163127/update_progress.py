def update_progress(self, project_name, progress):
        if project_name in self.projects:
            self.projects[project_name]["progress"] = progress
            print(f"Progress for {project_name} updated to {progress}%.")
        else:
            print(f"Project {project_name} not found.")