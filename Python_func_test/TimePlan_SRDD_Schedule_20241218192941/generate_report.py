def generate_report(self):
        '''
        Generates a productivity report based on the schedule.
        '''
        completed_tasks = [task for task in self.schedule.get_tasks() if task.status == "Completed"]
        pending_tasks = [task for task in self.schedule.get_tasks() if task.status == "Pending"]
        print("Productivity Report:", flush=True)
        print(f"Completed Tasks: {len(completed_tasks)}", flush=True)
        for task in completed_tasks:
            print(f"- {task.title}", flush=True)
        print(f"Pending Tasks: {len(pending_tasks)}", flush=True)
        for task in pending_tasks:
            print(f"- {task.title}", flush=True)