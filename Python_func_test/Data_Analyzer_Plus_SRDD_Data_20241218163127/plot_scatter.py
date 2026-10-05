def plot_scatter(self, data):
        try:
            plt.scatter(data.iloc[:, 0], data.iloc[:, 1])
            plt.title("Scatter Plot")
            plt.show()
        except Exception as e:
            print(f"Error plotting scatter plot: {e}")