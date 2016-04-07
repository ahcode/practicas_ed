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
    if(isEmpty()){
      head_=nodo;
    }else{
      if (head_->item()<=d){
        if (head_->item()==d){
          nodo->setNext(head_->next());
          delete [] head_;
          head_=nodo;
        }else{
          nodo->setNext(head_);
          head_=nodo;
        }
      }else{
        for (NodoDonante *punt = head_; punt->next()!=NULL; punt=punt->next()){
          if(d<=punt->next()->item()){
            if (punt->next()->item()==d){
              nodo->setNext(punt->next()->next());
              delete punt->next();
              punt->setNext(nodo);
            }else{
              nodo->setNext(punt->next());
              punt->setNext(nodo);
            }
            break;
          }
        }
      }
    }
  }

  Donante ListaDonantes::item(int const & pos) const{
    assert(!isValid(pos));
    NodoDonante *nodo = head_;
    for (int i=0; i<pos; i++)
      nodo=nodo->next();
    return nodo->item();
  }

  bool ListaDonantes::deletePosition(int const & pos){
    if(!isValid(pos))
      return false;
    NodoDonante *aux, *nodo = head_;
    for (int i=0; i<pos-1; i++)
      nodo=nodo->next();

    aux = nodo->next();
    nodo->setNext(aux->next());
    delete aux;

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
