def display_graphical_view(self, user):
        '''
        Displays a graphical representation of the user's schedule using a Gantt chart.
        Parameters:
            user (User): The user whose schedule is to be visualized.
        '''
        print(f"Generating graphical schedule view for {user.name}...")
        if not user.tasks:
            print("No tasks available to generate a graphical view.")
            return
        # Prepare data for the Gantt chart
        tasks = []
        start_times = []
        durations = []
        for task in user.tasks:
            tasks.append(task.description)
            start_time = datetime.strptime(task.start_time, "%Y-%m-%d %H:%M")
            end_time = datetime.strptime(task.end_time, "%Y-%m-%d %H:%M")
            start_times.append(start_time)
            durations.append((end_time - start_time).total_seconds() / 3600)  # Convert duration to hours
        # Plot the Gantt chart
        fig, ax = plt.subplots()
        y_pos = range(len(tasks))
        ax.barh(y_pos, durations, left=[start.timestamp() for start in start_times], color='skyblue')
        ax.set_yticks(y_pos)
        ax.set_yticklabels(tasks)
        ax.set_xlabel('Time')
        ax.set_title(f"Schedule for {user.name}")
        plt.show()