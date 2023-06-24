#include <iostream>
#include <vector>

// Abstract Talent class
class Talent {
public:
    virtual std::string getAbility() const = 0;
};

// Swimming class inheriting from Talent
class Swimming : public Talent {
public:
    std::string getAbility() const override {
        return "Swim";
    }
};

class Eating : public Talent {
public:
    std::string getAbility() const override {
        return "Eat";
    }
};

// Dancing class inheriting from Talent
class Dancing : public Talent {
public:
    std::string getAbility() const override {
        return "Dance";
    }
};

// Counting class inheriting from Talent
class Counting : public Talent {
public:
    std::string getAbility() const override {
        return "Count";
    }
};

class Computing : public Talent {
public:
    std::string getAbility() const override {
        return "Compute";
    }
};

// Dog class
class Dog {
private:
    std::string name;
    std::vector<Talent*> talents;

public:
    Dog(const std::string& dogName) : name(dogName) {}

    void addTalent(Talent* talent) {
        talents.push_back(talent);
    }

    void show_talents() const {
        std::cout << "This is " << name << " and it has some talents:" << std::endl;
        for (const Talent* talent : talents) {
            std::cout << "\tIt can \"" << talent->getAbility() << "\"" << std::endl;
        }
    }

    ~Dog() {
        for (Talent* talent : talents) {
            delete talent;
        }
    }
};

int main() {
    Dog dog1("Steve");

    Talent* dance = new Dancing();
    Talent* eating = new Eating();
    Talent* swim = new Swimming();
    Talent* counting = new Counting();
    Talent* computing = new Computing();
    // Adding abilities to the dog
    dog1.addTalent(dance);
    dog1.addTalent(swim);
    dog1.addTalent(counting); //My own skill
    dog1.addTalent(computing); //Another one :)
    dog1.addTalent(eating);


    dog1.show_talents();
    

    return 0;
}
