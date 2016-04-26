/*!
\file MonticuloDonantesInterfaz.hpp
\brief Interfaz para la clase MonticuloDonantes
\author Álvaro Herrero Pérez
\date 18/04/2016
*/

#ifndef MONTICULODONANTESINTERFAZ_HPP
#define MONTICULODONANTESINTERFAZ_HPP

#include "Donante.hpp"

namespace ed{
	/*!
	\brief Interfaz para la clase MonticuloDonantes
	*/
	class MonticuloDonantesInterfaz{
		public:
			/*!
			\brief Comprueba si el montículo está vacío
      \return bool, true si está vacío y false si no lo está
			*/
			virtual bool vacio() const=0;
			/*!
			\brief Devuelve el donante situado en la cima del montículo
			\return Donante, cima del montículo
      \note Si el montículo está vacío lanza una excepción de valor entero 1
			*/
			virtual Donante cima() const=0;
			/*!
			\brief Inserta un donante en el montículo
			\param d (Donante), Donante a insertar
      \note Se inserta en una hoja y se flota su nodo para colocarlo en su posición y cumplir la invariante
			*/
			virtual void insertar(Donante const &d)=0;
			/*!
			\brief Borra el donante en la cima
			\note Si el montículo está vacío devuelve false
      \return bool, true si la operación se realiza con éxito y false en caso contrario
			*/
			virtual bool borrar()=0;
	};
}

#endif
