def create_line_graph(data, title):
    try:
        data.plot(kind='line')
        plt.title(title)
        plt.xlabel('Date')
        plt.ylabel('Sales')
        plt.show()
    except Exception as e:
        raise Exception(f"Error creating line graph: {e}")