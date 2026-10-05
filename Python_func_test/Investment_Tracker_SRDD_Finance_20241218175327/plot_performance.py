def plot_performance(self, portfolio_name, performance):
        plt.figure(figsize=(10, 5))
        plt.title(f'{portfolio_name.capitalize()} Portfolio Performance')
        plt.plot(performance, label=f'Performance')
        plt.xlabel(f'Time Period')
        plt.ylabel(f'Value')
        plt.legend()
        plt.show()