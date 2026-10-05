def removezero_ip(ip):
    return '.'.join((str(int(part)) for part in ip.split('.')))