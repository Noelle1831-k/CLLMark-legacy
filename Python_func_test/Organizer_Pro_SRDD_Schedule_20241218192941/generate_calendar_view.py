def generate_calendar_view(self):
        print("Generating calendar view...")
        if not self.task_manager.tasks:
            print("No tasks available to display.")
            return
        dates = [datetime.strptime(task['deadline'], '%Y-%m-%d') for task in self.task_manager.tasks]
        task_names = [task['name'] for task in self.task_manager.tasks]
        plt.figure(figsize=(10, 5))
        plt.plot_date(dates, range(len(dates)), linestyle='-', marker='o')
        plt.yticks(range(len(dates)), task_names)
        plt.title('Task Calendar View')
        plt.xlabel('Dates')
        plt.ylabel('Tasks')
        plt.grid(True)
        plt.show()