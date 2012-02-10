#include <iostream>
#include <cstdlib>

#ifndef PEG_H
#define PEG_H

#define MAXSIZE 64

class Peg
{
  public:
		Peg(int size=64);
    int count() const;
    int topSize() const;
    void add(const int addedRing);
    void remove();
       	
    friend std::ostream& operator<< (std::ostream&, const Peg&);

  private:
    int size;
    int rings[MAXSIZE];
};
#endif