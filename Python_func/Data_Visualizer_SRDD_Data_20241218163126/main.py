def main():
    '''
    Initializes the application and sets up the user interface.
    '''
    print("Welcome to the Data Visualizer!")
    file_path = input("Enter the path to your data file: ")
    data = import_data(file_path)
    print("Choose a visualization type:")
    print("1. Bar Chart")
    print("2. Line Graph")
    print("3. Scatter Plot")
    print("4. Pie Chart")
    choice = int(input("Enter your choice: "))
    visualization = None
    if choice == 1:
        visualization = BarChart(data)
    elif choice == 2:
        visualization = LineGraph(data)
    elif choice == 3:
        visualization = ScatterPlot(data)
    elif choice == 4:
        visualization = PieChart(data)
    else:
        print("Invalid choice!")
        sys.exit(1)
    options = {}  # Assume options are collected from the user
    customize_visualization(visualization, options)
    print("Choose an export option:")
    print("1. Export as Image")
    print("2. Generate Shareable Link")
    export_choice = int(input("Enter your choice: "))
    if export_choice == 1:
        image_path = input("Enter the path to save the image: ")
        export_as_image(visualization, image_path)
    elif export_choice == 2:
        link = generate_shareable_link(visualization)
        print(f"Shareable link: {link}")
    else:
        print("Invalid choice!")
        sys.exit(1)