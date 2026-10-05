from datetime import datetime
def check_date(m, d, y):
    try:
        m, d, y = map(int, (m, d, y))
        datetime(y, m, d)
        return True
    except ValueError:
        return False