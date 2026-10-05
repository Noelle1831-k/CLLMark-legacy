def plot_io_operations(self, io_operations):
        print("Plotting I/O Operations...")
        plt.figure(figsize=(10, 5))
        plt.plot(io_operations, label='I/O Operations')
        plt.xlabel('Time')
        plt.ylabel('I/O Operations')
        plt.title('I/O Operations Over Time')
        plt.legend()
        plt.show()