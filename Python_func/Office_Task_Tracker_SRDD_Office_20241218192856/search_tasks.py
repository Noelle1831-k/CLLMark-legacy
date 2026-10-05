def search_tasks(self, keyword):
        '''
        Searches for tasks containing the given keyword.
        '''
        found_tasks = [task for task in self.tasks if keyword in task.title or keyword in task.description]
        return found_tasks