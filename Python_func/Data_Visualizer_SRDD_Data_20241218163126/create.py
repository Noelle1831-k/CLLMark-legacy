def create(self):
        self.figure = plt.figure()
        plt.bar(self.data['x'], self.data['y'])
        plt.title('Bar Chart')
        plt.xlabel('X-axis')
        plt.ylabel('Y-axis')
        plt.show()