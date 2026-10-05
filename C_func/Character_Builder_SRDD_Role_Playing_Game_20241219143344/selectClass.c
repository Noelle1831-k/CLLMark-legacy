Class* selectClass() {
    Class *class = (Class*)malloc(sizeof(Class));
    class->name = "Warrior";
    class->description = "Strong and brave.";
    return class;
}