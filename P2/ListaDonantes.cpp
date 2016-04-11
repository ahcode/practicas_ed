/*!
\file ListaDonantes.cpp
\brief Implementación de la clase ListaDonantes
\author Álvaro Herrero Pérez
\date 11/04/2016
*/

#include "ListaDonantes.hpp"

namespace ed{
  bool ListaDonantes::isValid(int const & pos) const{
    if (pos<=lastPos_ && pos>=0)
      return true;
    else
      return false;
  }

  bool ListaDonantes::isEmpty() const{
    if (head_==NULL)
      return true;
    else
      return false;
  }

  void ListaDonantes::insert(Donante const & d){
    NodoDonante *nodo = new NodoDonante(d);
    //Si la lista está vacía se inserta en el head_
    if(isEmpty()){
      head_=nodo;
      lastPos_++;
    }else{
      if (head_->item()<=d){
        //Si el donante es igual a head_ se sustituye head por el nuevo donante
        if (head_->item()==d){
          nodo->setNext(head_->next());
          delete head_;
          head_=nodo;
        //Si el donante es mayor que head_, se recorre la lista para buscar en que posición insertar
        }else{
          for (NodoDonante *punt = head_; punt!=NULL; punt=punt->next()){
            //Si no hay más elementos se inserta al final
            if(punt->next()==NULL){
              nodo->setNext(punt->next());
              punt->setNext(nodo);
              lastPos_++;
              break;
            }else if(d<=punt->next()->item()){
              //Si es igual que el siguiente elemento, se sustituye
              if(punt->next()->item()==d){
                nodo->setNext(punt->next()->next());
                delete punt->next();
                punt->setNext(nodo);
              //Si es menor que el siguiente elemento se inserta antes de este
              }else{
                nodo->setNext(punt->next());
                punt->setNext(nodo);
                lastPos_++;
              }
              break;
            }
          }
        }
      //Si el donante es menor que head_, se inserta delante de este
      }else{
        nodo->setNext(head_);
        head_=nodo;
        lastPos_++;
      }
    }
  }

  Donante ListaDonantes::item(int const & pos) const{
    assert(isValid(pos));
    NodoDonante *nodo = head_;
    for (int i=0; i<pos; i++)
      nodo=nodo->next();
    return nodo->item();
  }

  bool ListaDonantes::deletePosition(int const & pos){
    //std::cout << "a";
    if(!isValid(pos))
      return false;
    NodoDonante *aux;
    NodoDonante *nodo = head_;
    if (pos==0){
      //Si se va a eliminar la pos 0 y no hay más elementos, solo se borra head_
      if(head_->next()==NULL){
        delete head_;
        head_=NULL;
      //Si se va a eliminar la pos 0 y hay más elementos, se asigna head_->next() a head_
      }else{
        aux = head_;
        head_ = aux->next();
        delete aux;
      }
    //Si se va a eliminar otro elemento se recorre la lista, se elimina y se actualizan los punteros
    }else{
      for (int i=0; i<pos-1; i++)
        nodo=nodo->next();

      aux = nodo->next();
      nodo->setNext(aux->next());
      delete aux;
    }
    lastPos_--;
    return true;
  }

  int ListaDonantes::findItem(Donante const & d, int const & from) const{
    int i=0;
    for (NodoDonante *punt = head_; punt!=NULL; punt=punt->next()){
      if(d==punt->item()){
        return i;
      }
      i++;
    }
    return -1;
  }
}
