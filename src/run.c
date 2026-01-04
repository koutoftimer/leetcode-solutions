#include "solution.h"

int
main()
{
        assert(knightDialer(1) == 10);
        assert(knightDialer(2) == 20);
        assert(knightDialer(3) == 46);
        assert(knightDialer(4) == 104);
        assert(knightDialer(5) == 240);
        assert(knightDialer(6) == 544);
        assert(knightDialer(7) == 1256);
        assert(knightDialer(8) == 2848);
        assert(knightDialer(100) == 540641702);
        assert(knightDialer(120) == 798119115);
        assert(knightDialer(150) == 31297159);
        assert(knightDialer(1000) == 88106097);
        assert(knightDialer(2000) == 71794716);
        assert(knightDialer(2500) == 851996060);
        assert(knightDialer(3000) == 447863713);
        assert(knightDialer(3131) == 136006598);
        assert(knightDialer(5000) == 406880451);
}
