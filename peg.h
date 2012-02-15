#include <iostream>
#include <cstdlib>
#include <string>

const unsigned int MAXSIZE = 63;

class Peg
{
  public:
		Peg(int size=64); /* Size of ring on peg */
    int count() const;
    int topSize() const;
    void add(const int addedRing);
    void remove();
       	
    friend std::ostream& operator<< (std::ostream&, const Peg&);

  private:
    int size; /* Number of rings on peg */
    int rings[MAXSIZE];
};
