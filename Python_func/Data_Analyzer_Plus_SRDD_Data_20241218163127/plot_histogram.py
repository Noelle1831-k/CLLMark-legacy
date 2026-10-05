def plot_histogram(self, data):
        try:
            data.hist()
            plt.title("Histogram")
            plt.show()
        except Exception as e:
            print(f"Error plotting histogram: {e}")