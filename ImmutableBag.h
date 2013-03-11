#ifndef _IMMUTBAG_H
#define _IMMUTBAG_H

#include <cstddef>

namespace artemis {
  template<typename E>
  class ImmutableBag {
  public:
    virtual E get(int index) = 0;
    virtual int getCapacity() = 0;
    virtual int getCount() = 0;
    virtual bool isEmpty() = 0;
    virtual ~ImmutableBag(){};
  };
  
  template<typename E>
  class Bag : public ImmutableBag<E> {
    
    
  public:
    Bag();
    
    Bag(int capacity);
    
    /**
     *  If set is used, the bag might
     *  contain gaps between indexes. Use this to get a
     *  complete bag. No changes will be made to the original bag.
     */
    Bag<E> * getGapless();
    
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
    void add(E o);
    
    void addAll(Bag<E> & bag);
    
    /**
     * Sets every pointer to NULLs. Does not delete data.
     */
    void clear();
    
    bool contains(E o);
    
    virtual E get(int index);
    
    virtual int getCapacity();
    virtual bool isEmpty();
    /**
     * Returns the amount of objects in the bag.
     *
     **/
    virtual int getCount();
    
    bool remove(E o);
    
    E remove(int index);
    
    bool removeAll(Bag<E> bag);
    
    E removeLast();
    
    bool set(int index, E o);
    
    
    void operator += (Bag<E> &bag);
    void deleteData();
    
    virtual ~Bag<E>();
    
    
  private:
    
    int count;
    int size;
    E *data;
    
    void grow();
    
    void grow(int newCapacity);
    
    void init(int capacity);
    
  };
};

#endif // $(Guard token)
