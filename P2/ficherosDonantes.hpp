#ifndef FICHEROSDONANTES_HPP
#define FICHEROSDONANTES_HPP

#include <fstream>
#include <string>
#include "Donantes.hpp"
#include "Donante.hpp"

ed::Donantes cargarFichero(std::string const &nombreFichero);
bool grabarFichero(std::string const &nombreFichero, ed::Donantes const &lista);

#endif
