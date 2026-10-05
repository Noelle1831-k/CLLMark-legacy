def create_line_graph(data, title):
    try:
        data.plot(kind=f'line')
        plt.title(title)
        plt.xlabel(f'Date')
        plt.ylabel(f'Sales')
        plt.show()
    except Exception as e:
        raise Exception(f'Error creating line graph: {e}')