#include <iostream>

// Class Hierarchy with Non-Virtual Inheritance:

class Base {
public:
    int base_data;
};

class Level1A : public Base {
public:
    int level1A_data;
};

class Level1B : public Base {
public:
    int level1B_data;
};

class Level2A : public Level1A, public Level1B {
public:
    int level2A_data;
};

class Level3A : public Level2A {
public:
    int level3A_data;
};


class Level2B : public Level1B, public Base {
public:
    int level2B_data;
};

class Level3B : public Level2B, public Level1A, public Level2A {
public:
    int level3B_data;
};
// Class Hierarchy with Virtual Inheritance:

class VirtualBase {
public:
    int base_data;
};

class VirtualLevel1B : virtual public VirtualBase {
public:
    int level1B_data;
};

class VirtualLevel1A : virtual public VirtualBase {
public:
    int level1A_data;
};

class VirtualLevel2A : virtual public VirtualLevel1A, virtual public VirtualLevel1B {
public:
    int level2A_data;
};

class VirtualLevel2B : virtual public VirtualLevel1B, virtual public VirtualBase {
public:
    int level2B_data;
};

class VirtualLevel3B : public VirtualLevel2B, virtual public VirtualLevel1A, virtual public VirtualLevel2A {
public:
    int level3B_data;
};

class VirtualLevel3A : public VirtualLevel2A {
public:
    int level3B_data;
};

class VirtualDerived : public VirtualLevel2A, public VirtualLevel1B {
public:
    int derived_data;
};

int main() {
    // Creating objects of derived classes with non-virtual inheritance
    Level2A* objA = new Level2A();
    Level2B* objB = new Level2B();

    // Creating object of derived class with virtual inheritance
    VirtualDerived* objD = new VirtualDerived();

    // Displaying the sizes of the classes
    std::cout << "Size of Base class: " << sizeof(Base) << std::endl;
    std::cout << "Size of Level1A class: " << sizeof(Level1A) << std::endl;
    std::cout << "Size of Level1B class: " << sizeof(Level1B) << std::endl;
    std::cout << "Size of Level2A class: " << sizeof(Level2A) << std::endl;
    std::cout << "Size of Level2B class: " << sizeof(Level2B) << std::endl;
    std::cout << "Size of Level2A class: " << sizeof(Level3A) << std::endl;
    std::cout << "Size of Level2B class: " << sizeof(Level3B) << std::endl;
    std::cout << "Size of VirtualBase class: " << sizeof(VirtualBase) << std::endl;
    std::cout << "Size of VirtualLevel1A class: " << sizeof(VirtualLevel1A) << std::endl;
    std::cout << "Size of VirtualLevel1B class: " << sizeof(VirtualLevel1B) << std::endl;
    std::cout << "Size of VirtualLevel2A class: " << sizeof(VirtualLevel2A) << std::endl;
    std::cout << "Size of VirtualLevel2B class: " << sizeof(VirtualLevel2B) << std::endl;
    std::cout << "Size of VirtualLevel3A class: " << sizeof(VirtualLevel3A) << std::endl;
    std::cout << "Size of VirtualLevel3B class: " << sizeof(VirtualLevel3B) << std::endl;
    std::cout << "Size of VirtualDerived class: " << sizeof(VirtualDerived) << std::endl;

    // Clean up the memory
    delete objA;
    delete objB;
    delete objD;

    return 0;
}
