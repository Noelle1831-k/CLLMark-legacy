def plot_comparison(self, portfolio_name, performance, benchmark):
        plt.figure(figsize=(10, 5))
        plt.title(f"{portfolio_name.capitalize()} Portfolio vs Benchmark")
        plt.plot(performance, label='Portfolio Performance')
        plt.plot(benchmark, label='Benchmark', linestyle='--')
        plt.xlabel('Time Period')
        plt.ylabel('Value')
        plt.legend()
        plt.show()