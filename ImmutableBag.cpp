#include "ImmutableBag.h"

namespace artemis {
  
  template<typename E>
  Bag<E>::Bag() {
    init(20);
  };
  
  template<typename E>
  Bag<E>::Bag(int capacity) {
    init(capacity);
  };
  
  /**
   *  If set is used, the bag might
   *  contain gaps between indexes. Use this to get a
   *  complete bag. No changes will be made to the original bag.
   */
  template<typename E>
  Bag<E> * Bag<E>::getGapless() {
    
    Bag<E> * bag = new Bag<E>(this->count);
    //int c = 0;
    
    for(int i=0; i < this->size; i++)
    {
      if(this->data[i] != NULL){
        bag->add(data[i]);
      }
    }
    
    return bag;
    
  }
  
  /**
   * Adds an object to the bag.
   * Mixing add and set is not encouraged.
   * Note: set can create gaps between indexes where
   * the object count is irrelevant to the order.
   *
   * Autmatically grows the bag if necessary.
   *
   * @param o The object to be added.
   **/
  template<typename E>
  void Bag<E>::add(E o) {
    if(size == count)grow();
    
    data[count++] = o;
  };
  
  template<typename E>
  void Bag<E>::addAll(Bag<E> & bag) {
    
    for(int i=0; i < bag.size ; i++) {
      add(bag.data[i]);
    }
  };
  
  /**
   * Sets every pointer to NULLs. Does not delete data.
   */
  template<typename E>
  void Bag<E>::clear() {
    for(int i=0; i<size; i++) {
      data[i] = NULL;
    }
    
    count = 0;
    
  };
  
  template<typename E>
  bool Bag<E>::contains(E o) {
    
    for(int i=0; i<count; i++)
      if(o == data[i])
        return true;
    
    return false;
  };
  
  template<typename E>
  E Bag<E>::get(int index) {
    if (index >= size) return NULL;
    return (E)data[index];
  };
  
  template<typename E>
  int Bag<E>::getCapacity() {return size;};
  template<typename E>
  bool Bag<E>::isEmpty() {return count == 0;};
  /**
   * Returns the amount of objects in the bag.
   *
   **/
  template<typename E>
  int Bag<E>::getCount() {return count;};
  
  template<typename E>
  bool Bag<E>::remove(E o) {
    
    for(int i=0; i<count; i++) {
      if(o == data[i]) {
        remove(i);
        return true;
      }
    }
    
    return false;
  };
  
  template<typename E>
  E Bag<E>::remove(int index) {
    if(count == 0) return NULL;
    
    E object = data[index];
    data[index] = data[count-1];
    data[count-1] = NULL;
    count--;
    return (E) object;
  };
  
  template<typename E>
  bool Bag<E>::removeAll(Bag<E> bag) {
    bool mod = false;
    
    for(int i=0; i<bag.count; i++)
      for(int j= 0; j< count ; j++)
        if(bag.data[i] == data[j]) {
          remove(j);
          j--; // ?
          mod = true;
          break;
        }
    
    return mod;
    
  };
  
  template<typename E>
  E Bag<E>::removeLast() {
    if(!isEmpty()) {
      E object = data[count-1];
      data[count-1] = NULL;
      --count;
      return (E) object;
    }
    
    return NULL;
  };
  
  
  template<typename E>
  bool Bag<E>::set(int index, E o) {
    if(index >= size) grow(index*2);
    
    
    if(o == NULL && data[index] != NULL){
      count--;
    }
    else if(o != NULL && data[index] == NULL){
      count++;
    };
    
    data[index] = o;
    return true;
  };
  
  
  template<typename E>
  void Bag<E>::operator += (Bag<E> &bag) {
    addAll(bag);
  };
  
  template<typename E>
  void Bag<E>::deleteData(){
    
    for(int i=0; i<size; i++)
    {
      delete data[i];
      data[i] = NULL;
    }
    count = 0;
  }
  
  template<typename E>
  Bag<E>::~Bag<E>() {
    delete[] data;
  };
  
  template<typename E>
  void Bag<E>::grow() {
    int newCapacity =(size * 3.0f) * 0.5f + 1.0f;
    grow(newCapacity);
  };
  
  template<typename E>
  void Bag<E>::grow(int newCapacity) {
    E* newData = new E[newCapacity];
    
    for (int i = 0; i < size; i++)
      newData[i] = data[i];
    for (int i = size; i < newCapacity; i++)
      newData[i] = NULL;
    
    delete[] data;
    
    size = newCapacity;
    data = newData;
  };
  
  template<typename E>
  void Bag<E>::init(int capacity) {
    size = capacity;
    count = 0;
    data = new E[capacity];
    clear();
  }
};