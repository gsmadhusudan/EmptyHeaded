#include "Vector.hpp"

template <class T, class A, class M>
uint32_t Vector<T,A,M>::indexOf(const uint32_t data) const{
  return 0;
}

//calls index of then calls get below.
template <class T, class A, class M>
A Vector<T,A,M>::get(const uint32_t data) const{
  return (A)0;
}

//look up a data value
template <class T, class A, class M>
A Vector<T,A,M>::get(
  const uint32_t index,
  const uint32_t data) const{
  return (A)0;
}

//set an annotation value
template <class T, class A, class M>
void Vector<T,A,M>::set(
  const uint32_t index,
  const uint32_t data, 
  const A value) {

}

//look up a data value
template <class T, class A, class M>
bool Vector<T,A,M>::contains(const uint32_t key) const{
  return false;
}

//constructors
template <class T, class A, class M>
Vector<T,A,M> Vector<T,A,M>::from_vector(
  M* memoryBuffer,
  std::vector<uint32_t>* v){

  const size_t index = memoryBuffer->get_offset();
  const size_t num_bytes = T::get_num_bytes(v);
  //reserve memory
  memoryBuffer->get_next(sizeof(Meta)+num_bytes);
  Meta* meta = new(memoryBuffer->get_address(index)) Meta();

  meta->cardinality = v->size();

  meta->start = 0;
  meta->end = 0;
  if(v->size() > 0){
    meta->start = v->at(0);
    meta->end = v->at(v->size()-1);
  }
  meta->type = T::get_type();

  T:: template from_vector<A,M>(memoryBuffer->get_address(index+sizeof(Meta)),v);
  return Vector<T,A,M>(memoryBuffer,index);
}


template struct Vector<SparseVector,void*,MemoryBuffer>;
template struct Vector<SparseVector,int,MemoryBuffer>;
template struct Vector<SparseVector,long,MemoryBuffer>;
template struct Vector<SparseVector,float,MemoryBuffer>;
template struct Vector<SparseVector,double,MemoryBuffer>;