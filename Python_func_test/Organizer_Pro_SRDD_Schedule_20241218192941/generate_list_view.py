def generate_list_view(self):
        print("Generating list view...")
        if not self.task_manager.tasks:
            print("No tasks available to display.")
            return
        df = pd.DataFrame(self.task_manager.tasks)
        print(df.to_string(index=False))