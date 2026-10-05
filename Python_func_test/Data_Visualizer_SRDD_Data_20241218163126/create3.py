def create(self):
        self.figure = plt.figure()
        plt.scatter(self.data['x'], self.data['y'])
        plt.title('Scatter Plot')
        plt.xlabel('X-axis')
        plt.ylabel('Y-axis')
        plt.show()