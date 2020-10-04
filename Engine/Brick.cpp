#include "Brick.h"

bool Brick::Colide(Brick& br)
{
    return ( r.down <= br.r.up &&
             r.up >= br.r.down &&
             r.left <= br.r.right &&
             r.right >= br.r.left );
}
