
#include "Mage.hpp"

Mage::Mage() {
}

Mage::Mage(const Mage& orig) {
}

Mage::~Mage() {
}

int Mage::getMana() {
    return mana;
}

void Mage::setMana(int mana) {
    this->mana = mana;
}