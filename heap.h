#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "item.h"

class Heap {
    public:
        Heap (std::vector<Item*> h);
        ~Heap ();
        Item* max ();
        void refaz (int esq, int dir);
        void constroi ();
    private:
        std::vector<Item*> v;
        int n;
};

#endif