def get_employee_details(emp_id):
    for emp in employees:
        if emp["emp_id"] == emp_id:
            return emp
    return None