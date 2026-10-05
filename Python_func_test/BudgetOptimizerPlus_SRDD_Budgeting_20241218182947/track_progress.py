def track_progress(self):
        """
        Simulate tracking progress based on current savings.
        """
        while True:
            progress = input(f'Enter your current savings amount: ')
            try:
                self.current_savings = float(progress)
                if self.current_savings < 0:
                    print('Current savings cannot be negative. Please enter a valid amount.')
                    continue
                break
            except ValueError:
                print('Please enter a valid number.')
        progress_percentage = (self.current_savings / self.savings_goal) * 100
        print(f'Savings progress: {progress_percentage:.2f}%')
        # Show further recommendations based on savings progress
        if progress_percentage >= 75:
            print('Great job! You are almost there!')
        elif progress_percentage >= 50:
            print('You"re halfway to your savings goal!')
        else:
            print('Keep going! Every bit counts toward your goal.')