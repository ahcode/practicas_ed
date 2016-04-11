/*!
\file Donantes.hpp
\brief Especificación de la clase Donantes
\author Álvaro Herrero Pérez
\date 11/04/2016
*/

#ifndef DONANTES_HPP
#define DONANTES_HPP

#include <string>
#include <iostream>
#include "macros.hpp"
#include "DonantesInterfaz.hpp"
#include "Donante.hpp"
#include "ListaDonantes.hpp"

namespace ed{
  /*!
	\brief Clase para almacenar y trabajar con una lista de donantes de sangre
	*/
  class Donantes: public DonantesInterfaz{
    private:
      /*!
			\brief Lista que almacena los donantes añadidos al objeto
			*/
      ListaDonantes lista_;
    public:
      /*!
			\brief Constructor parametrizado de la clase Donantes
      \param lista (Lista de donantes) de tipo ListaDonantes
			*/
      Donantes(ListaDonantes const &lista){lista_=lista;};
      /*!
			\brief Constructor por defecto de la clase Donantes
      \note La lista de donantes se crea vacía con este constructor
			*/
      Donantes(){};
      /*!
			\brief Comprueba si hay al menos un donante en la lista
      \return bool, true si hay donantes y false si no los hay
			*/
      bool hayDonantes() const{return !lista_.isEmpty();};
      /*!
			\brief Busca un donante en la lista a partir de su nombre y su apellido
      \param nombre (Nombre del donante) de tipo string
      \param apellidos (Apellidos del donante) de tipo string
      \note Si no se encuentra el donante lanza una excepción con valor entero 1
      \return Donante, objeto Donante encontrado en la lista
			*/
      Donante buscarDonante(std::string const &nombre, std::string const &apellidos) const;
      /*!
      \brief Inserta un objeto Donante en la lista de donantes
      \param d (donante a insertar) de tipo Donante
      */
      void insertarDonante(Donante const &d){lista_.insert(d);};
      /*!
      \brief Borra un objeto Donante en la lista de donantes
      \param d (donante a borrar) de tipo Donante
      \return bool, true si la operación ha tenido éxito y false en caso contrario
      */
      bool borrarDonante(Donante const &d);
      /*!
      \brief Borra un donante de la lista a partir de su nombre y apellidos
      \param nombre (Nombre del donante) de tipo string
      \param apellidos (Apellidos del donante) de tipo string
      \return bool, true si la operación ha tenido éxito y false en caso contrario
      */
      bool borrarDonante(std::string const &nombre, std::string const &apellidos);
      /*!
      \brief Borra un donante de la lista a partir posición
      \param n (Posición) de tipo int
      \pre La posición debe ser un valor válido
      \return bool, true si la operación ha tenido éxito y false en caso contrario
      */
      bool borrarDonante(int const &n){return lista_.deletePosition(n-1);};
      /*!
			\brief Devuelve la lista de donantes
			\return ListaDonantes, lista de donantes
			\sa setLista
			*/
      ListaDonantes getLista() const{return lista_;};
      /*!
			\brief Devuelve un donante a partir de su posición
      \param n (posición), de tipo int
			\return Donante, donante en la posición indicada
      \note Las posiciones comienzan en el valor 1
      \note Si la posición no es válida lanza una excepción con valor entero 1
			\sa setLista
			*/
      Donante getDonante(int const &n) const;
      /*!
			\brief Cambia la lista actual del objeto
			\param lista (lista de donantes) de tipo ListaDonantes
			\sa getLista
			*/
      void setLista(ListaDonantes const & lista){lista_=lista;};
      /*!
			\brief Pregunta por pantalla cuantos donantes se quieren insertar y los datos de estos
			\note Si se insertan datos incorrectos, muestra un error y los pide de nuevo
			\sa escribirDonantes
			*/
      void leerDonantes();
      /*!
			\brief Muestra por pantalla los donantes almacenados en la lista
      \note Borra los donantes que ya se encontraran en la lista antes de llamar a la función
			\sa leerDonantes
			*/
      void escribirDonantes() const;
      /*!
			\brief Borra todos los donantes almacenados en la lista
			*/
      void borrarLista();
      /*!
			\brief Devuelve el número de donantes almacenados
      \return int, número de donantes almacenados en la lista
			*/
      int numDonantes() const;
  };
}

#endif
