for (const auto& subList : testList) {
    for (const auto& element : subList) {
        if (element != k) {
            return false;
        }
    }
}
return true;
}