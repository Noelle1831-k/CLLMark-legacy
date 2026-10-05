def generate_pie_chart(self, data):
        labels = data.keys()
        sizes = data.values()
        explode = list([0.1]) * len(labels)  # explode all slices for emphasis
        plt.figure(figsize=(8, 8))
        plt.pie(sizes, labels=labels, autopct='%1.1f%%', startangle=140, explode=explode, shadow=True)
        plt.title('Budget Breakdown - Pie Chart')
        plt.axis('equal')
        plt.show()