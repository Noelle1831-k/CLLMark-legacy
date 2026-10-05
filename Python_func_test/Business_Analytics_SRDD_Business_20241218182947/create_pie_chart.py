def create_pie_chart(data, title):
    try:
        data.plot(kind='pie', y='Sales', autopct='%1.1f%%')
        plt.title(title)
        plt.show()
    except Exception as e:
        raise Exception(f"Error creating pie chart: {e}")