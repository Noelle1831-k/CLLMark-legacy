def view_progress(self):
        """
        Displays a visual representation of savings progress.
        """
        try:
            progress = self.budget_manager.get_savings_progress()
            self.visualizer.display_progress(progress)
        except Exception as e:
            print(f"An error occurred while displaying progress: {e}")