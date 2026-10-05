def display_overview(self):
        '''
        Displays a visual overview of the day's tasks.
        '''
        tasks = self.task_manager.get_tasks()
        print("Today's Tasks Overview:")
        for task in tasks:
            print(f"Task: {task.name}, Priority: {task.priority}, Category: {task.category}, Time: {task.time_slot}")