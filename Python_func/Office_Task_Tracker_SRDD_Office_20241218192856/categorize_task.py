def categorize_task(self, category):
        '''
        Categorizes tasks based on the given category.
        '''
        categorized_tasks = [task for task in self.tasks if task.category == category]
        return categorized_tasks