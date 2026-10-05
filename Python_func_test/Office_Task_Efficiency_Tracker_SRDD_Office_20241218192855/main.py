def main():
    '''
    Initialize the application components and start the dashboard.
    '''
    data_storage = DataStorage('tasks_data.json')
    task_manager = TaskManager(data_storage)
    dashboard = Dashboard(task_manager)
    dashboard.run()