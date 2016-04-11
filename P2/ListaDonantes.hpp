/*!
\file ListaDonantes.hpp
\brief Especificación de la clase ListaDonantes y NodoDonante
\author Álvaro Herrero Pérez
\date 11/04/2016
*/

#ifndef LISTADONANTES_HPP
#define LISTADONANTES_HPP

#include <cassert>
#include "Donante.hpp"

namespace ed{
  /*!
	\brief Nodo simplemente enlazado de un objeto Donante
	*/
  class NodoDonante{
    private:
      /*!
    	\brief objeto Donante que almacena el nodo
    	*/
      Donante item_;
      /*!
    	\brief puntero al siguiente nodo de la lista
    	*/
      NodoDonante * next_;
    public:
      /*!
    	\brief Constructor de la clase NodoDonante
      \param item (donante a almacenar) de tipo Donante
      \param next (puntero al siguiente nodo) de tipo *NodoDonante, por defecto NULL
    	*/
      NodoDonante(Donante item, NodoDonante *next=NULL){item_=item; next_=next;};
      /*!
    	\brief Devuelve el item almacenado
      \return Donante, donante almacenado
    	*/
      Donante item() const{return item_;};
      /*!
    	\brief Cambia el donante almacenado por otro
      \param item (donante a insertar) de tipo Donante
    	*/
      void setItem(Donante const & item){item_=item;};
      /*!
    	\brief Devuelve el puntero al siguiente nodo
      \return *NodoDonante, puntero al siguiente nodo
    	*/
      NodoDonante * next() const{return next_;};
      /*!
    	\brief Cambia el puntero al siguiente nodo
      \param next (puntero al siguiente nodo) de tipo *NodoDonante
    	*/
      void setNext(NodoDonante *next){next_=next;};
  };

  /*!
  \brief Lista ordenada simplemente enlazada de objetos de tipo Donante
  */
  class ListaDonantes{
    private:
      /*!
    	\brief Puntero al primer elemento de la lista
    	*/
      NodoDonante * head_;
      /*!
    	\brief Última posición válida
      \note Cuando no hay elementos vale -1
    	*/
      int lastPos_;
    public:
      /*!
    	\brief Constructor de la clase ListaDonantes
    	*/
      ListaDonantes(){head_=NULL; lastPos_=-1;};
      /*!
    	\brief Comprueba si una determinada posición es válida
      \param pos (posición a comprobar) de tipo int
      \return bool, true si la posición es válida y false si no lo es
    	*/
      bool isValid(int const & pos) const;
      /*!
    	\brief Comprueba si la lista está vacía
      \return bool, true si la lista está vacía y false si no lo está
    	*/
      bool isEmpty() const;
      /*!
    	\brief Inserta de forma ordenada un donante a la lista
      \note Si el donante ya existe (nombre y apellidos iguales), actualiza el que ya se encuentra en la lista por si ha cambiado el grupo sanguíneo o el factor de riesgo
      \param d (donante a insertar) de tipo Donante
    	*/
      void insert(Donante const & d);
      /*!
    	\brief Devuelve un determinado donante a partir de su posición
      \note Las posiciones comienzan por el valor 0
      \note Debe ser una posición válida comprobada anteriormente, si no lo es el programa se abortará
      \param pos (posición del donante) de tipo int
      \return Donante, donante almacenado en dicha posición
    	*/
      Donante item(int const & pos) const;
      /*!
    	\brief Elimina un donante de la lista a partir de su posición
      \param pos (posición a eliminar) de tipo int
      \return bool, true si la operación se ha realizado correctamente y false en caso contrario
    	*/
      bool deletePosition(int const & pos);
      /*!
    	\brief Comprueba si existe un objeto donante y si existe, devuelve su posición
      \param d (donante a buscar) de tipo Donante
      \param from (posición para iniciar la búsqueda) de tipo int
      \return int, posición del elemento encontrado
      \note Si no se encuentra el elemento se devuelve -1
    	*/
      int findItem(Donante const & d, int const & from=0) const;
  };
}

#endif
