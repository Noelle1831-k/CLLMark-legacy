def visualize_priority_distribution(self):
        '''
        Visualize the priority distribution using a text-based bar chart.
        '''
        print("\nPriority Distribution Visualization:")
        print("===================================")
        for priority, count in self.analysis.items():
            bar = "#" * count
            print(f"{priority}: {bar} ({count})")