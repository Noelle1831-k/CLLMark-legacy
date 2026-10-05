def plot_scatter(self, data, var1, var2):
        plt.figure(figsize=(10, 6))
        plt.scatter(data[var1], data[var2], alpha=0.5)
        plt.title(f'Scatter Plot: {var1} vs {var2}')
        plt.xlabel(var1)
        plt.ylabel(var2)
        plt.grid(True)
        plt.show()