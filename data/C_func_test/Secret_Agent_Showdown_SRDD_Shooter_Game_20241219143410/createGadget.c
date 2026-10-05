Gadget* createGadget(GadgetType type) {
    Gadget *gadget = (Gadget*)malloc(sizeof(Gadget));
    if (gadget != NULL) {
        gadget->type = type;
    }
    return gadget;
}