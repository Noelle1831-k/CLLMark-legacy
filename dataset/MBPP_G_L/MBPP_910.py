from datetime import datetime
def check_date(m, d, y):
    try:
        datetime(int(y), int(m), int(d))
        return True
    except ValueError:
        return False