def compare_progress(self, user1_data, user2_data, category1, category2):
        '''
        Compares the progress of two users using a line chart.
        Parameters:
        - user1_data: List of progress values for user 1.
        - user2_data: List of progress values for user 2.
        - category1: The category of the habit for user 1.
        - category2: The category of the habit for user 2.
        '''
        days = list(range(1, max(len(user1_data), len(user2_data)) + 1))
        plt.figure(figsize=(10, 5))
        plt.plot(days[:len(user1_data)], user1_data, marker='o', linestyle='-', color='r', label=category1)
        plt.plot(days[:len(user2_data)], user2_data, marker='x', linestyle='--', color='b', label=category2)
        plt.ylabel('Progress')
        plt.xlabel('Days')
        plt.title('Comparison of Progress Between Users')
        plt.legend()
        plt.grid(True)
        plt.show()