#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < MAX_KNOWN_MATERIAS; i++) {
        _knownMaterias[i] = nullptr;
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < MAX_KNOWN_MATERIAS; i++) {
        if (_knownMaterias[i] != nullptr)
            delete _knownMaterias[i];
    }
}

MateriaSource::MateriaSource (const MateriaSource& other) {
    for (int i = 0; i < MAX_KNOWN_MATERIAS; i++) {
        _knownMaterias[i] = other._knownMaterias[i]->clone();

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

}

