def create_bar_chart(data, title):
    try:
        data.plot(kind='bar')
        plt.title(title)
        plt.xlabel('Category')
        plt.ylabel('Sales')
        plt.show()
    except Exception as e:
        raise Exception(f"Error creating bar chart: {e}")