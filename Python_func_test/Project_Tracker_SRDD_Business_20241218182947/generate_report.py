def generate_report(self, project_name):
        if self.database.project_exists(project_name):
            tasks = self.database.get_tasks(project_name)
            report_generator = ReportGenerator()
            report = report_generator.generate(tasks)
            print(report)
        else:
            print(f"Project '{project_name}' does not exist.")