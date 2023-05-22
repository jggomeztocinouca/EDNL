/*--------------------------------------------------------*/
/* particion.h                                            */
/*                                                        */
/* clase Particion: Representa particiones del rango de   */
/*     enteros [0, n-1].                                  */
/*--------------------------------------------------------*/

#ifndef PARTICION_H
#define PARTICION_H

#include <vector>

class Particion {
public:
   Particion(unsigned int n): padre(n, -1) {}
   void unir(unsigned int a, unsigned int b);
   unsigned int encontrar(unsigned int x) const;
private:
   mutable std::vector<unsigned int> padre;
};

#endif   // PARTICION_H
