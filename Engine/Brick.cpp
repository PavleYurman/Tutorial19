#include "Brick.h"
#include <assert.h>

Brick::Brick(const Vec2& upperLeft, float width, float hight, Color c_in)
{
    r = Rect(upperLeft, width, hight);
    c = c_in;
}

bool Brick::CheckForColision(Ball& bl)
{
    return (r.down >= bl.r.up &&
        r.up <= bl.r.down &&
        r.left <= bl.r.right &&
        r.right >= bl.r.left);
}

void Brick::ExecuteColison(Ball& bl)
{           
    if ( ( bl.pos.x >= r.left ) && ( bl.pos.x <= r.right ) )
    {          
        bl.ChangeY();
    }
    else //if ( ( bl.pos.x < r.left ) || ( bl.pos.x > r.right ) )
    {            
        bl.ChangeX();
    }              
           
    isColided = true;  
}



void Brick::Draw( Graphics& gfx )
{        
    r.Draw(gfx, Colors::Black);
    Rect rTop = Rect(r.left + 1, r.right - 1, r.up + 1, r.down - 1);
    rTop.Draw(gfx, c);
}

