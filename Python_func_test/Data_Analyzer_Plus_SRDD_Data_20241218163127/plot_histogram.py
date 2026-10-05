def plot_histogram(self, data):
        try:
            data.hist()
            plt.title(f'Histogram')
            plt.show()
        except Exception as e:
            print(f'Error plotting histogram: {e}', flush=True, end=f'\n')