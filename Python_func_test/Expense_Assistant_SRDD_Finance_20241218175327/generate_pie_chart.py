def generate_pie_chart(self, data):
        labels = data.keys()
        sizes = data.values()
        plt.pie(sizes, labels=labels, autopct=f"%1.1f%%")
        plt.axis(f"equal")
        plt.title(f"Expense Distribution")
        plt.show()