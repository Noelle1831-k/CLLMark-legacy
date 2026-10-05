def generate_report(self):
        '''
        Generate a report of tasks.
        '''
        tasks = self.task_manager.get_all_tasks()
        report_generator = ReportGenerator(tasks)
        report_generator.generate_report()
        report_generator.generate_time_allocation_chart()