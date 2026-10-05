def create(self):
        self.figure = plt.figure()
        plt.pie(self.data['values'], labels=self.data['labels'], autopct='%1.1f%%')
        plt.title('Pie Chart')
        plt.show()