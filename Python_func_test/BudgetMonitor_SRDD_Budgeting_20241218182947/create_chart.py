def create_chart(self, user_data):
        categories = [expense['category'] for expense in user_data['expenses']]
        amounts = [expense['amount'] for expense in user_data['expenses']]
        plt.figure(figsize=(10, 5))
        plt.bar(categories, amounts, color='skyblue')
        plt.title('Expense Breakdown')
        plt.xlabel('Category')
        plt.ylabel('Amount')
        plt.show()