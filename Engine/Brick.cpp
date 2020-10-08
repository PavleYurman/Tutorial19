#include "Brick.h"

Brick::Brick(const Vec2& upperLeft, float width, float hight, Color c_in)
{
    r = Rect(upperLeft, width, hight);
    c = c_in;
}

bool Brick::Colide( Ball& bl) // ball collision is not working
{    
    return (r.down >= bl.r.up &&
            r.up <= bl.r.down &&
            r.left <= bl.r.right &&
            r.right >= bl.r.left);
}

void Brick::ProcessColison(Ball& bl)
{
    if ( isColided )
    {
        return;
    }
    else if ( Colide(bl) )
    {
        isColided = true;
        bl.ChangeY();
    }
}


void Brick::Draw( Graphics& gfx )
{
    r.Draw(gfx, c);
}

