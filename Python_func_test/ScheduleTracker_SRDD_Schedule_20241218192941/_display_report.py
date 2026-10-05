def _display_report(self, report_data):
        print("\n--- Productivity Report ---")
        for task_id, data in report_data.items():
            if task_id != 'total_time':
                print(f"Task ID: {task_id}, Name: {data['name']}, Duration: {data['duration']}")
        print(f"Total Time Spent: {report_data['total_time']}")
        print("--- End of Report ---\n")