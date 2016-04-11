/*!
\file DonantesInterfaz.hpp
\brief Interfaz de la clase Donantes
\author Álvaro Herrero Pérez
\date 11/04/2016
*/

#ifndef DONANTESINTERFAZ_HPP
#define DONANTESINTERFAZ_HPP

#include <string>
#include "Donante.hpp"

namespace ed{
  /*!
	\brief Interfaz para la clase Donantes
	*/
  class DonantesInterfaz{
    public:
      /*!
			\brief Comprueba si hay al menos un donante en la lista
      \return bool, true si hay donantes y false si no los hay
			*/
      virtual bool hayDonantes() const=0;
      /*!
			\brief Busca un donante en la lista a partir de su nombre y su apellido
      \param nombre (Nombre del donante) de tipo string
      \param apellidos (Apellidos del donante) de tipo string
      \note Si no se encuentra el donante lanza una excepción con valor entero 1
      \return Donante, objeto Donante encontrado en la lista
			*/
      virtual Donante buscarDonante(std::string const &nombre, std::string const &apellidos) const=0;
      /*!
      \brief Inserta un objeto Donante en la lista de donantes
      \param d (donante a insertar) de tipo Donante
      */
      virtual void insertarDonante(Donante const &d)=0;
      /*!
      \brief Borra un donante de la lista a partir de su nombre y apellidos
      \param nombre (Nombre del donante) de tipo string
      \param apellidos (Apellidos del donante) de tipo string
      \return bool, true si la operación ha tenido éxito y false en caso contrario
      */
      virtual bool borrarDonante(std::string const &nombre, std::string const &apellidos)=0;
      /*!
      \brief Borra un objeto Donante en la lista de donantes
      \param d (donante a borrar) de tipo Donante
      \return bool, true si la operación ha tenido éxito y false en caso contrario
      */
      virtual bool borrarDonante(Donante const &d)=0;
  };
}

#endif
