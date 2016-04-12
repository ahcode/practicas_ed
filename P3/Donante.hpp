/*!
\file Donante.hpp
\brief Especificación de la clase Donante
\author Álvaro Herrero Pérez
\date 12/04/2016
*/

#ifndef DONANTE_HPP
#define DONANTE_HPP
#include <string>
#include <iostream>
#include "DonanteInterfaz.hpp"
#include "macros.hpp"

namespace ed{
	/*!
	\brief Clase que almacena la información de un donante de sangre
	*/
	class Donante: public DonanteInterfaz{
		private:
			/*!
			\brief Almacena el nombre del donante
			*/
			std::string nombre_;
			/*!
			\brief Almacena los apellidos del donante
			*/
			std::string apellidos_;
			/*!
			\brief Almacena el grupo sanguíneo del donante
			*/
			std::string grupo_;
			/*!
			\brief Almacena el factor de riesgo del donante
			*/
			std::string frh_;
			/*!
			\brief Almacena número de donaciones del donante
			*/
			int donaciones_;
		public:
			/*!
			\brief Constructor de la clase Donante, se puede llamar con parámetros por defecto
			\param n (Nombre) de tipo string, valor por defecto ""
			\param a (Apellidos) de tipo string, valor por defecto ""
			\param g (Grupo Sanguíneo) de tipo string, valor por defecto "0"
			\param f (Factor de Riesgo) de tipo string, valor por defecto "positivo"
			*/
			Donante(std::string const &n="", std::string const &a="", std::string const &g="0", std::string const &f="positivo");
			/*!
			\brief Constructor de copia de la clase Donante
			\param d (Donante) de tipo Donante
			*/
			Donante(Donante const &d);
			/*!
			\brief Establece un nombre al Donante
			\param n (Nombre) de tipo string
			\sa getNombre
			*/
			inline void setNombre(std::string const &n){nombre_=n;};
			/*!
			\brief Establece los apellidos al Donante
			\param a (Apellidos) de tipo string
			\sa getApellidos
			*/
			inline void setApellidos(std::string const &a){apellidos_=a;};
			/*!
			\brief Establece un grupo sanguíneo al Donante
			\param g (Grupo Sanguíneo) de tipo string
			\pre g debe ser un grupo sanguíneo válido (0, a, A, b, B, ab, AB)
			\return bool, true si la operación es correcta y false en caso contrario
			\sa getGrupo
			*/
			bool setGrupo(std::string const &g);
			/*!
			\brief Establece un factor de riesgo al Donante
			\param f (Factor de riesgo) de tipo string
			\pre f debe ser un factor de riesgo válido (+, -, positivo, negativo, POSITIVO, NEGATIVO, Positivo, Negativo)
			\return bool, true si la operación es correcta y false en caso contrario
			\sa getFRH
			*/
			bool setFRH(std::string const &f);
			/*!
			\brief Establece el número de donaciones del donante
			\param n (Número de donaciones) de tipo int
			\pre n debe ser mayor o igual a 0
			\return bool, true si la operación es correcta y false en caso contrario
			\sa getDonaciones
			*/
			bool setDonaciones(int const &n);
			/*!
			\brief Devuelve el nombre del donante
			\return string, nombre del donante
			\sa setNombre
			*/
			inline std::string getNombre() const{return nombre_;};
			/*!
			\brief Devuelve los apellidos del donante
			\return string, apellidos del donante
			\sa setApellidos
			*/
			inline std::string getApellidos() const{return apellidos_;};
			/*!
			\brief Devuelve el grupo sanguíneo del donante
			\return string, grupo sanguíneo
			\sa setGrupo
			*/
			inline std::string getGrupo() const{return grupo_;};
			/*!
			\brief Devuelve el factor de riesgo del donante
			\return string, factor de riesgo
			\sa setFRH
			*/
			inline std::string getFRH() const{return frh_;};
			/*!
			\brief Devuelve el número de donaciones del donante
			\return int, número de donaciones
			\sa setDonaciones
			*/
			inline int getDonaciones() const{return donaciones_;};
			/*!
			\brief Pregunta por pantalla los datos de un donante y los almacena
			\note Si se insertan datos incorrectos, muestra un error y los pide de nuevo
			\sa mostrarDonante
			*/
			void leerDonante();
			/*!
			\brief Muestra por pantalla los datos de un donante
			\sa leerDonante
			*/
			void mostrarDonante() const;
			/*!
			\brief Pregunta que dato modificar y luego lo pide por pantalla
			\note Si se insertan datos incorrectos, muestra un error y los pide de nuevo
			*/
			void modificarDonante();
			/*!
			\brief Compara nombre y apellidos de un donante para saber si es el mismo
			\return bool, true si los donantes son iguales y false si no lo son
			*/
			bool mismoDonante(Donante const &d);
			/*!
			\brief Iguala dos donantes
			*/
			Donante &operator=(Donante const &d);
			/*!
			\brief Compara número de donaciones del donante
			\return bool, true si los donantes son iguales y false si no lo son
			*/
			bool operator==(Donante const &d) const;
			/*!
			\brief Compara número de donaciones del donante
			\return bool, true si el donante de la izquierda es menor o igual que el de la derecha y false si no lo es
			*/
			bool operator<=(Donante const &d) const;
			/*!
			\brief Pregunta por pantalla los datos de un donante y los almacena
			\note Si se insertan datos incorrectos, muestra un error y los pide de nuevo
			\sa leerDonante
			*/
			friend std::istream &operator>>(std::istream &stream, Donante &d);
			/*!
			\brief Muestra por pantalla los datos de un donante
			\sa leerDonante
			*/
			friend std::ostream &operator<<(std::ostream &stream, Donante const &d);
	};
}
#endif
