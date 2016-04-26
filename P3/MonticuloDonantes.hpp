/*!
\file MonticuloDonantes.hpp
\brief Especificación de la clase MonticuloDonantes
\author Álvaro Herrero Pérez
\date 18/04/2016
*/

#ifndef MONTICULODONANTES_HPP
#define MONTICULODONANTES_HPP

#include <vector>
#include <fstream>
#include "MonticuloDonantesInterfaz.hpp"
#include "Donante.hpp"

namespace ed{
	/*!
	\brief Clase que almacena un montículo de donantes
	*/
	class MonticuloDonantes: public MonticuloDonantesInterfaz{
		private:
			/*!
			\brief Vector que almacena los datos del montículo
			*/
			std::vector<Donante> vector_;
			/*!
			\brief Flota un nodo para cumplir la invariante del montículo
			\param pos (Posición del nodo a flotar) de tipo int
			\sa hundir
			*/
			void flotar(int const &pos);
			/*!
			\brief Hunde un nodo para cumplir la invariante del montículo
			\param pos (Posición del nodo a hundir) de tipo int
			\sa flotar
			*/
			void hundir(int const &pos);
			/*!
			\brief Devuelve la posición del nodo que corresponde al padre a partir de otra posición
			\param pos (Posición del hijo) de tipo int
			\return int, Posición del padre
			*/
			int padre(int const &pos) const{return ((pos+1)/2)-1;};
			/*!
			\brief Devuelve la posición del nodo que corresponde al hijo izquierdo a partir de otra posición
			\param pos (Posición del padre) de tipo int
			\return int, Posición del hijo izquierdo
			\sa hijoDer
			*/
			int hijoIzq(int const &pos) const{return 2*pos+1;};
			/*!
			\brief Devuelve la posición del nodo que corresponde al hijo derecho a partir de otra posición
			\param pos (Posición del padre) de tipo int
			\return int, Posición del hijo derecho
			\sa hijoIzq
			*/
			int hijoDer(int const &pos) const{return 2*pos+2;};
		public:
			/*!
			\brief Constructor de la clase donantes (inicializa el vector)
			*/
			MonticuloDonantes() : vector_(0){};
			/*!
			\brief Comprueba si el montículo está vacío
      \return bool, true si está vacío y false si no lo está
			*/
			inline bool vacio() const{return vector_.empty();};
			/*!
			\brief Devuelve el donante situado en la cima del montículo
			\return Donante, cima del montículo
      \note Si el montículo está vacío lanza una excepción de valor entero 1
			*/
			Donante cima() const;
			/*!
			\brief Inserta un donante en el montículo
			\param d (Donante), Donante a insertar
      \note Se inserta en una hoja y se flota su nodo para colocarlo en su posición y cumplir la invariante
			*/
			void insertar(Donante const &d);
			/*!
			\brief Borra el donante en la cima
			\note Si el montículo está vacío devuelve false
      \return bool, true si la operación se realiza con éxito y false en caso contrario
			*/
			bool borrar();
			/*!
			\brief Aumenta en 1 el número de donaciones del donante de la cima y lo hunde si es necesario
			\note Si el montículo está vacío devuelve false
      \return bool, true si la operación se realiza con éxito y false en caso contrario
			*/
			bool donar();
			/*!
			\brief Vacía todos los datos del montículo
			\note No se libera la memoria reservada por el vector
			*/
			void vaciar(){vector_.clear();};
			/*!
			\brief Carga un fichero de texto con una lista de donantes en el montículo
			\param nombreFichero (Nombre del fichero) de tipo string
			\note El fichero debe tener el siguiente formato: Los donantes irán uno detrás de otro ocupando 5 líneas cada uno, 1º línea para el nombre, 2º línea para los apellidos, 3º línea para el grupo sanguíneo, 4º para el factor de riesgo y 5º para el número de donaciones
			\note Se lanzará una excepción con valor entero 1 si no se puede abrir el fichero
			\note Se lanzará una excepción con valor entero 2 si hay un fallo al intentar añadir un grupo sanguíneo no válido
			\note Se lanzará una excepción con valor entero 3 si hay un fallo al intentar añadir un factor de riesgo no válido
			\note Se lanzará una excepción con valor entero 4 si hay un fallo al intentar añadir un número de donaciones no válido
			*/
			void cargarFichero(std::string const &nombreFichero);
			/*!
			\brief Guardar un fichero de texto con los donantes del montículo
			\param nombreFichero (Nombre del fichero) de tipo string
			\note El fichero debe tener el siguiente formato: Los donantes irán uno detrás de otro ocupando 5 líneas cada uno, 1º línea para el nombre, 2º línea para los apellidos, 3º línea para el grupo sanguíneo, 4º para el factor de riesgo y 5º para el número de donaciones
			\return bool, true si el fichero se graba correctamente y false en caso contrario
			*/
			bool grabarFichero(std::string const &nombreFichero);
	};
}

#endif
