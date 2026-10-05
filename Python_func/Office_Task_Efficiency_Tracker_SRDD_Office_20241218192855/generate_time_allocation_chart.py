def generate_time_allocation_chart(self):
        '''
        Generate a chart showing time allocation across tasks.
        '''
        task_names = [task.name for task in self.tasks]
        time_spent = [task.time_spent for task in self.tasks]
        plt.bar(task_names, time_spent, color='#2196F3')
        plt.xlabel('Tasks')
        plt.ylabel('Time Spent (minutes)')
        plt.title('Time Allocation Across Tasks')
        plt.xticks(rotation=45, ha='right')
        plt.tight_layout()
        plt.show()