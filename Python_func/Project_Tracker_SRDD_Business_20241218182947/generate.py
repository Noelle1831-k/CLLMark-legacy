def generate(self, tasks):
        report = "Project Report:\n"
        for task in tasks:
            report += f"Task: {task.title}, Assignee: {task.assignee}, Deadline: {task.deadline}, Status: {task.status}\n"
        return report