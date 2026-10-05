def visualize_sleep_data(self, analysis):
        print("Visualizing sleep data...")
        print(f"Sleep Efficiency: {analysis['efficiency']}%")
        print(f"Disruptors: {', '.join(analysis['disruptors'])}")