void Exercise::viewExercise() const {
    std::cout << "Exercise: " << name << std::endl;
    if (sets > 0) {
        std::cout << "Sets: " << sets << ", Repetitions: " << repetitions << std::endl;
    } else {
        std::cout << "Distance: " << distance << " km" << std::endl;
    }
}