def create(self):
        self.figure = plt.figure()
        plt.plot(self.data[f'x'], self.data[f'y'])
        plt.title(f'Line Graph')
        plt.xlabel(f'X-axis')
        plt.ylabel(f'Y-axis')
        plt.show()