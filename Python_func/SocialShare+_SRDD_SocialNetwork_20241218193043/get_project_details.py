def get_project_details(self):
        return {
            "project_id": self.project_id,
            "project_name": self.project_name,
            "contributors": [user.username for user in self.contributors],
            "tasks": self.tasks,
            "feedback": self.feedback
        }