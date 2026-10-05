def customize_graph(self, fig, title, xlabel, ylabel):
        fig.suptitle(title)
        ax = fig.gca()
        ax.set_xlabel(xlabel)
        ax.set_ylabel(ylabel)