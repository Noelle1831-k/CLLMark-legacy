def plot_line(self, data):
        try:
            data.plot()
            plt.title("Line Graph")
            plt.show()
        except Exception as e:
            print(f"Error plotting line graph: {e}")