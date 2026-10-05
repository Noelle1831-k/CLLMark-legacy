def Check_Solution(a, b, c):
    if a == 0:
        return 'No'
    discriminant = b ** 2 - 4 * a * c
    if discriminant < 0:
        return 'No'
    root1 = (-b + discriminant ** 0.5) / (2 * a)
    root2 = (-b - discriminant ** 0.5) / (2 * a)
    if root1 == 2 * root2 or root2 == 2 * root1:
        return 'Yes'
    return 'No'