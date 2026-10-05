def create_tables(self):
        self.execute_query('''CREATE TABLE IF NOT EXISTS employees (
                                employee_id INTEGER PRIMARY KEY,
                                name TEXT,
                                department TEXT,
                                position TEXT)''')
        self.execute_query('''CREATE TABLE IF NOT EXISTS performance_goals (
                                goal_id INTEGER PRIMARY KEY,
                                employee_id INTEGER,
                                goal_description TEXT,
                                start_date TEXT,
                                end_date TEXT,
                                FOREIGN KEY(employee_id) REFERENCES employees(employee_id))''')
        self.execute_query('''CREATE TABLE IF NOT EXISTS performance_evaluations (
                                evaluation_id INTEGER PRIMARY KEY,
                                employee_id INTEGER,
                                evaluator_id INTEGER,
                                evaluation_date TEXT,
                                score INTEGER,
                                comments TEXT,
                                FOREIGN KEY(employee_id) REFERENCES employees(employee_id))''')
        self.execute_query('''CREATE TABLE IF NOT EXISTS performance_reports (
                                report_id INTEGER PRIMARY KEY,
                                employee_id INTEGER,
                                report_date TEXT,
                                goals TEXT,
                                evaluations TEXT,
                                FOREIGN KEY(employee_id) REFERENCES employees(employee_id))''')