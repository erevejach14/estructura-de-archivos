#ifndef ARISTAS_H_INCLUDE
#define ARISTAS_H_INCLUDE

template <class T>
class Aristas{
  private:
    T dato;
    vertice *nodoAdyDest;
    arista *nodoAriSig;
  public:
    Aristas();
	  Aristas(const Music&);

  	Music& getData();
  	Aristas* getNext();
  	Aristas* getPrev();

  	void setData(const T&);
  	void setNext(Aristas*);
  	void setVertice(Vertices*);
};

#endif
