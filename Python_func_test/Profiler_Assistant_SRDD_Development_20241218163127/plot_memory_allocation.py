def plot_memory_allocation(self, memory_allocation):
        print("Plotting Memory Allocation...")
        plt.figure(figsize=(10, 5))
        plt.plot(memory_allocation, label='Memory Allocation')
        plt.xlabel('Time')
        plt.ylabel('Memory (MB)')
        plt.title('Memory Allocation Over Time')
        plt.legend()
        plt.show()