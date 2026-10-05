def plot_goal_progress(self, goal, current_balance):
        '''
        Plots a bar chart showing the progress of a financial goal.
        Arguments:
        goal -- The goal amount the user aims to reach.
        current_balance -- The current balance of the user.
        '''
        plt.bar(['Goal', 'Current Balance'], [goal, current_balance], color=['#ff9999', '#66b3ff'])
        plt.title('Goal Progress')
        plt.show()