def analyze_productivity(self, tasks):
        '''
        Analyzes productivity based on completed tasks.
        '''
        completed_tasks = [task for task in tasks if task["progress"] == "Completed"]
        productivity = len(completed_tasks) / len(tasks) * 100
        print(f"Productivity: {productivity}%")