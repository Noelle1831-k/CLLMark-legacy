def generate_daily_view(self):
        """
        Generates and displays a daily schedule view as a bar chart.
        """
        if not self.tasks:
            print("No tasks available to visualize.")
            return
        print("Generating daily schedule view...")
        task_names = [task['name'] for task in self.tasks]
        start_times = [task['start_time'] for task in self.tasks]
        end_times = [task['end_time'] for task in self.tasks]
        durations = [(end - start).total_seconds() / 3600 for start, end in zip(start_times, end_times)]
        # Sorting tasks by start time
        sorted_tasks = sorted(self.tasks, key=lambda x: x['start_time'])
        task_names = [task['name'] for task in sorted_tasks]
        start_times = [task['start_time'] for task in sorted_tasks]
        durations = [(task['end_time'] - task['start_time']).total_seconds() / 3600 for task in sorted_tasks]
        # Plotting schedule
        fig, ax = plt.subplots(figsize=(10, 6))
        start_hours = [time.hour + time.minute / 60 for time in start_times]
        ax.barh(task_names, durations, left=start_hours, color='skyblue', edgecolor='black')
        # Formatting the graph
        ax.set_xlabel('Hours', fontsize=12)
        ax.set_ylabel('Tasks', fontsize=12)
        ax.set_title('Daily Schedule Overview', fontsize=16)
        ax.set_xticks(range(0, 25))
        ax.set_xticklabels([f"{hour}:00" for hour in range(0, 25)], rotation=45)
        ax.grid(axis='x', linestyle='--', alpha=0.7)
        # Annotating each task with its time range
        for i, (name, start, end) in enumerate(zip(task_names, start_times, end_times)):
            ax.text(
                start.hour + start.minute / 60 + durations[i] / 2,
                i,
                f"{start.strftime('%H:%M')} - {end.strftime('%H:%M')}",
                ha='center',
                va='center',
                color='black',
                fontsize=10
            )
        plt.tight_layout()
        plt.show()