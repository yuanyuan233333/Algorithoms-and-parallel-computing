//
// Created by Danilo Ardagna on 19/10/2019.
//

#include "Sneaky.h"

// ok: clobber1 can access the private and protected members in Sneaky objects
void Sneaky::clobber1(Sneaky &s) { s.j = s.prot_mem = 0; }

// error: clobber can't access the protected members in Basevoid
void Sneaky::clobber2(Base &b) { b.prot_mem = 0; }
