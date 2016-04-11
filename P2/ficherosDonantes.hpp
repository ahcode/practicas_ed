/*!
\file ficherosDonantes.hpp
\brief Definición de funciones de ficheros
\author Álvaro Herrero Pérez
\date 11/04/2016
*/

#ifndef FICHEROSDONANTES_HPP
#define FICHEROSDONANTES_HPP

#include <fstream>
#include <string>
#include "Donantes.hpp"
#include "Donante.hpp"

/*!
\brief Carga un fichero de texto con una lista de donantes a un objeto Donantes
\param nombreFichero (Nombre del fichero) de tipo string
\note El fichero debe tener el siguiente formato: Los donantes irán uno detrás de otro ocupando 4 líneas cada uno, 1º línea para el nombre, 2º línea para los apellidos, 3º línea para el grupo sanguíneo y 4º para el factor de riesgo
\return Donantes, objeto Donantes con los datos del fichero
\note Se lanzará una excepción con valor entero 1 si no se puede abrir el fichero
\note Se lanzará una excepción con valor entero 2 si hay un fallo al intentar añadir un grupo sanguíneo no válido
\note Se lanzará una excepción con valor entero 3 si hay un fallo al intentar añadir un factor de riesgo no válido
*/
ed::Donantes cargarFichero(std::string const &nombreFichero);
/*!
\brief Guardar un fichero de texto con la lista de donantes de un objeto Donantes
\param nombreFichero (Nombre del fichero) de tipo string
\param lista (Objeto a guardar) de tipo Donantes
\note El fichero tendrá el siguiente formato: Los donantes irán uno detrás de otro ocupando 4 líneas cada uno, 1º línea para el nombre, 2º línea para los apellidos, 3º línea para el grupo sanguíneo y 4º para el factor de riesgo
\return bool, true si el fichero se graba correctamente y false en caso contrario
*/
bool grabarFichero(std::string const &nombreFichero, ed::Donantes const &lista);

#endif
