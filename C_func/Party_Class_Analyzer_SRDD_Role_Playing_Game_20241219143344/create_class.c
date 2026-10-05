void create_class(Class *class) {
    char class_name[50];
    scanf("%s", class_name);
    strcpy(class->name, class_name);
    class->strength = rand() % 10 + 1;
    class->intelligence = rand() % 10 + 1;
    class->agility = rand() % 10 + 1;
    class->defense = rand() % 10 + 1;
    class->attack = rand() % 10 + 1;
}