def generate_report(self):
        for portfolio_name, portfolio in self.portfolios.items():
            performance = portfolio.calculate_performance()
            self.visualization.plot_performance(portfolio_name, performance)