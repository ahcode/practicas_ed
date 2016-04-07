#ifndef LISTADONANTES_HPP
#define LISTADONANTES_HPP

#include <cassert>
#include "Donante.hpp"

namespace ed{
  class NodoDonante{
    private:
      Donante item_;
      NodoDonante * next_;
    public:
      NodoDonante(Donante item, NodoDonante *next=NULL){item_=item; next_=next;};
      Donante item() const{return item_;};
      void setItem(Donante const & item){item_=item;};
      NodoDonante * next() const{return next_;};
      void setNext(NodoDonante *next){next_=next;};
  };

  class ListaDonantes{
    private:
      NodoDonante * head_;
      int lastPos_;
    public:
      ListaDonantes(){head_=NULL; lastPos_=-1;};
      bool isValid(int const & pos) const;
      bool isEmpty() const;
      void insert(Donante const & d);
      Donante item(int const & pos) const;
      bool deletePosition(int const & pos);
      int findItem(Donante const & d, int const & from=0) const;
  };
}

#endif
