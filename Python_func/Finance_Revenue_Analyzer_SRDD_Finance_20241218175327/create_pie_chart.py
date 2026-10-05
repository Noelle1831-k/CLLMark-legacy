def create_pie_chart(self, data):
        sources = list(data.keys())
        amounts = list(data.values())
        explode = [0.1 if amount == max(amounts) else 0 for amount in amounts]
        plt.figure(figsize=(9, 9))
        plt.pie(amounts, labels=sources, autopct='%1.1f%%', startangle=140, explode=explode, shadow=True)
        plt.title('Revenue Distribution')
        plt.axis('equal')
        plt.show()