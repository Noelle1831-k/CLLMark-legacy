def create(self):
        self.figure = plt.figure()
        plt.plot(self.data['x'], self.data['y'])
        plt.title('Line Graph')
        plt.xlabel('X-axis')
        plt.ylabel('Y-axis')
        plt.show()