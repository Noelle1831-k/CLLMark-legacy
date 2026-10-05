def display_schedule(self):
        '''
        Displays the detailed schedule including tasks, time blocks, priorities, and progress.
        '''
        print("\n--- Full Schedule Overview ---\n")
        self.task_manager.list_tasks()
        for task in self.task_manager.tasks.keys():
            print(f"\nTask: {task}")
            print(f"Priority: {self.priority_manager.get_priority(task)}")
            print(f"Time Blocks: {self.time_blocker.get_time_blocks(task)}")
            print(f"Progress: {self.progress_tracker.get_progress(task)}%")
        print("\n-------------------------------\n")