def generate_graph(self, data):
        fig, ax = plt.subplots()
        for key, values in data.items():
            ax.plot(range(len(values)), list(values.values()), label=key)
        ax.set_xlabel('Levels')
        ax.set_ylabel('Values')
        ax.set_title('Character Progression')
        ax.legend()
        return fig