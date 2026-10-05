def plot_schedule(self, tasks, time_log):
        task_names = [task['name'] for task in tasks]
        allocated_times = [float(time_log[task['name']]['allocated'].split()[0]) if task['name'] in time_log else 0 for task in tasks]
        plt.figure(figsize=(10, 5))
        plt.bar(task_names, allocated_times, color='skyblue')
        plt.title("Schedule Plot")
        plt.xlabel("Tasks")
        plt.ylabel("Time Allocated (hours)")
        plt.xticks(rotation=45)
        plt.tight_layout()
        plt.show()