def display_progress_chart(self, user):
        '''
        Displays a pie chart of task progress for the user.
        Parameters:
            user (User): The user whose task progress is to be visualized.
        '''
        print(f"Generating progress chart for {user.name}...")
        if not user.tasks:
            print("No tasks available to display progress.")
            return
        completed = sum(1 for task in user.tasks if task.progress == 100)
        in_progress = sum(1 for task in user.tasks if 0 < task.progress < 100)
        not_started = sum(1 for task in user.tasks if task.progress == 0)
        labels = ['Completed', 'In Progress', 'Not Started']
        sizes = [completed, in_progress, not_started]
        colors = ['green', 'orange', 'red']
        plt.figure(figsize=(6, 6))
        plt.pie(sizes, labels=labels, colors=colors, autopct='%1.1f%%', startangle=140)
        plt.title(f"Task Progress for {user.name}")
        plt.show()