def plot_cpu_usage(self, cpu_usage):
        print("Plotting CPU usage...")
        plt.figure(figsize=(10, 5))
        plt.plot(cpu_usage, label='CPU Usage')
        plt.xlabel('Time')
        plt.ylabel('CPU Usage (%)')
        plt.title('CPU Usage Over Time')
        plt.legend()
        plt.show()