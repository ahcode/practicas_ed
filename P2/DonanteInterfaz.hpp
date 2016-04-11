/*!
\file DonanteInterfaz.hpp
\brief Interfaz para la clase Donante
\author Álvaro Herrero Pérez
\date 11/04/2016
*/

#ifndef DONANTEINTERFAZ_HPP
#define DONANTEINTERFAZ_HPP
#include <string>
namespace ed{
	/*!
	\brief Interfaz para la clase Donante
	*/
	class DonanteInterfaz {
		public:
			/*!
			\brief Establece un nombre al Donante
			\param n (Nombre) de tipo string
			\sa getNombre
			*/
			virtual void setNombre(std::string const &n)=0;
			/*!
			\brief Establece los apellidos al Donante
			\param a (Apellidos) de tipo string
			\sa getApellidos
			*/
			virtual void setApellidos(std::string const &a)=0;
			/*!
			\brief Establece un grupo sanguíneo al Donante
			\param g (Grupo Sanguíneo) de tipo string
			\pre g debe ser un grupo sanguíneo válido (0, a, A, b, B, ab, AB)
			\return bool, true si la operación es correcta y false en caso contrario
			\sa getGrupo
			*/
			virtual bool setGrupo(std::string const &g)=0;
			/*!
			\brief Establece un factor de riesgo al Donante
			\param f (Factor de riesgo) de tipo string
			\pre f debe ser un factor de riesgo válido (+, -, positivo, negativo, POSITIVO, NEGATIVO, Positivo, Negativo)
			\return bool, true si la operación es correcta y false en caso contrario
			\sa getFRH
			*/
			virtual bool setFRH(std::string const &f)=0;
			/*!
			\brief Devuelve el nombre del donante
			\return string, nombre del donante
			\sa setNombre
			*/
			virtual std::string getNombre() const=0;
			/*!
			\brief Devuelve los apellidos del donante
			\return string, apellidos del donante
			\sa setApellidos
			*/
			virtual std::string getApellidos() const=0;
			/*!
			\brief Devuelve el grupo sanguíneo del donante
			\return string, grupo sanguíneo
			\sa setGrupo
			*/
			virtual std::string getGrupo() const=0;
			/*!
			\brief Devuelve el factor de riesgo del donante
			\return string, factor de riesgo
			\sa setFRH
			*/
			virtual std::string getFRH() const=0;
	};
}
#endif
