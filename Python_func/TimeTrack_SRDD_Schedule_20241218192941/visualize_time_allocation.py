def visualize_time_allocation(self, allocation):
        activities = list(allocation.keys())
        times = list(allocation.values())
        plt.figure(figsize=(10, 5))
        plt.bar(activities, times, color='skyblue')
        plt.xlabel('Activities')
        plt.ylabel('Time (minutes)')
        plt.title('Time Allocation')
        plt.show()