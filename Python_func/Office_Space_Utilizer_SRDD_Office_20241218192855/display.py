def display(self, data, insights, suggestions):
        '''
        Display the dashboard with data, insights, and optimization suggestions.
        '''
        self._plot_occupancy(data)
        self._show_insights(insights)
        self._show_suggestions(suggestions)
        self._advanced_visualizations(data)