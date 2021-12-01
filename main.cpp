#include <string.h>
#include <iostream>
using namespace std;

typedef enum {
    MADE_OF_FIRE,
    MADE_OF_WATER,
    MADE_OF_PLANT,
} ElementType;

class Element {
  private:
    ElementType type;

  public:
    Element(ElementType type) { this->type = type; }
};

class Monster {
  private:
    char    name[20];
    Element element;
    float   health;  // HP
    int     speed;
    int     attack;
    int     defense;

  public:
    Monster(const char * name, ElementType type, float health, int speed, int attack, int defense) : element(type) {

        strcpy(this->name, name);
        this->health  = health;
        this->speed   = speed;
        this->attack  = attack;
        this->defense = defense;
    }
};

class Tamer {
  private:
    char      name[20];
    uint8_t   age;
    float     winRate;
    float     loseRate;
    Monster * monster;

  public:
    Tamer(const char * name, uint8_t age, Monster & monster) {
        strcpy(this->name, name);
        this->age      = age;
        this->winRate  = 0.;
        this->loseRate = 0.;
        this->monster  = &monster;
    }
};

class Tournament {
  private:
    Monster * monster;
    Tamer *   tamer;

  public:
    Tournament(uint8_t tamer_count, uint32_t max_turn) {
        this->monster = new Monster[tamer_count];
        this->tamer = new Tamer[tamer_count];

        // Monster monster1("Igor", MADE_OF_FIRE, 100., 40, 40, 20);
        // Tamer   tamer1("Tony", 40, monster1);
    }

    ~Tournament() {

    }
};

int main() {
    cout << "Monster Battle System!\n" << endl;

    Tournament tournament(10, 10);

}
