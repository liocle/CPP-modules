#include "MateriaSource.hpp"
#include "Color.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < MAX_KNOWN_MATERIAS; i++) {
        _knownMaterias[i] = nullptr;
    }
    std::cout << RED << "MateriaSource constructor called" << std::endl;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < MAX_KNOWN_MATERIAS; i++) {
        if (_knownMaterias[i] != nullptr)
            delete _knownMaterias[i];
    }
    std::cout << RED << "MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource (const MateriaSource& other) {
    for (int i = 0; i < MAX_KNOWN_MATERIAS; i++) {
        if (other._knownMaterias[i] != nullptr)
            _knownMaterias[i] = other._knownMaterias[i]->clone();
        else {
            (void)other;
            _knownMaterias[i] = nullptr;
        }
    std::cout << RED << "MateriaSource copy constructor called" << std::endl;

    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    for (int i = 0;  i < MAX_KNOWN_MATERIAS; i++)
    {
        if (_knownMaterias[i] != nullptr)  {
            delete _knownMaterias[i];
            _knownMaterias[i] = nullptr;
        }
        _knownMaterias[i] = other._knownMaterias[i]->clone();
    }
    std::cout << RED << "MateriaSource copy assignment operator called" << std::endl;
    return *this;
}


void MateriaSource::learnMateria(AMateria* materia) {
    std::cout << RED << "MateriaSource::learnMateria() called" << std::endl;
    if (materia != nullptr) {
        for (int i = 0; i < MAX_KNOWN_MATERIAS; i++){
            if (_knownMaterias[i] == nullptr){
                _knownMaterias[i] = materia;
                return ; 
            }
        }
        delete materia;
        std::cout << RED << "MAX_KNOWN_MATERIAS reached, cannot learn anymore new Materia" << RESET << std::endl;
    }
    std::cout << RED << "Materia points to nullptr" << RESET << std::endl;
    materia = nullptr;
}

AMateria* MateriaSource::createMateria(std::string const & type){
    std::cout << RED << "MateriaSource::createMateria() called" << std::endl;
    for (int i = 0; i < MAX_KNOWN_MATERIAS; i++){
        std::cout << RED << "Number of for loop iterations: " << i << RESET << std::endl;
        if (_knownMaterias[i] && _knownMaterias[i]->getType() == type){
            return (_knownMaterias[i]->clone());
        }
    }
    return nullptr;
}
