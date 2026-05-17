#include "jatekapp.hpp"
#include "jatekmester.hpp"
#include "amoebaboard.hpp"

int main() {
    JatekMester mester(15, 15);
    JatekApp app(1200, 1200);

    AmoebaBoard* board = new AmoebaBoard(50, 100, 500, 500, &mester);
    app.hozzaad(board);

    app.futtat();

    return 0;
}
