def plot_performance(self, portfolio_name, performance):
        plt.figure(figsize=(10, 5))
        plt.title(f"{portfolio_name.capitalize()} Portfolio Performance")
        plt.plot(performance, label='Performance')
        plt.xlabel('Time Period')
        plt.ylabel('Value')
        plt.legend()
        plt.show()