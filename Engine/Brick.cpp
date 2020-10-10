#include "Brick.h"

Brick::Brick(const Vec2& upperLeft, float width, float hight, Color c_in)
{
    r = Rect(upperLeft, width, hight);
    c = c_in;
}


void Brick::ProcessColison(Ball& bl)
{    
    if ( Colide(bl) )
    {
        if ( isColided )
		{
			return;
		}
        isColided = true;
        bl.ChangeY();
    }
}

bool Brick::Colide(Ball& bl)
{
    return (r.down >= bl.r.up &&
        r.up <= bl.r.down &&
        r.left <= bl.r.right &&
        r.right >= bl.r.left);
}

void Brick::Draw( Graphics& gfx )
{
    r.Draw(gfx, c);
}

