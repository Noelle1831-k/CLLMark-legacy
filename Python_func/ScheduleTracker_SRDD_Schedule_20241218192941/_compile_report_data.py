def _compile_report_data(self):
        report_data = {}
        total_time = datetime.timedelta()
        for task_id, task in self.task_manager.tasks.items():
            start_time = datetime.datetime.strptime(task['start_time'], "%H:%M")
            end_time = datetime.datetime.strptime(task['end_time'], "%H:%M")
            task_duration = end_time - start_time
            total_time += task_duration
            report_data[task_id] = {
                'name': task['name'],
                'duration': task_duration
            }
        report_data['total_time'] = total_time
        return report_data