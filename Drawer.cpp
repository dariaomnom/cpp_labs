#include "Drawer.hpp"

Drawer::Drawer(PlayerController& controller, GameField& gameField, Player& player)
        : controller(controller), gameField(gameField), player(player) {}

void Drawer::drawField() {
    clear();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);

    int area = REGION_AROUND;

    int w = gameField.getSize().first;
    int h = gameField.getSize().second;
    int x_start = 0;
    int y_start = 0;
    int x_end = 0;
    int y_end = 0;
    if (w <= 10 && h <= 10) {
        x_start = 0;
        y_start = 0;
        x_end = w;
        y_end = h;
    } else {
        int x_center = controller.getX();
        int y_center = controller.getY();

        if (x_center < area/2) { x_start = 0; x_end = area; }
        else if (x_center >= w - area/2) { x_start = w - area; x_end = w; }
        else { x_start = x_center - area/2; x_end = x_center + area/2+1; }

        if (y_center < area/2) { y_start = 0; y_end = area; }
        else if (y_center >= h - area/2) { y_start = h - area; y_end = h; }
        else { y_start = y_center - area/2; y_end = y_center + area/2+1; }
    }
    std::string cell_view;
    std::string n_message = "\n";
    printw("%s", n_message.c_str());
    for (int i = y_start; i < y_end; i++) {
        cell_view = "   ";
        printw("%s", cell_view.c_str());
        for (int j = x_start; j < x_end; j++) {
            GameEvent* event = gameField.getCell(j, i).getEvent();
            if (gameField.getCell(j, i).isPassable()) {
                if (controller.getX() == j && controller.getY() == i)
                    cell_view = "(T-T)";
                else if(dynamic_cast<PointsEvent *>(event)){
                    cell_view = "  $  ";
                }
                else if(dynamic_cast<LivesEvent *>(event)){
                    cell_view = "  +  ";
                }
                else if(dynamic_cast<EnemyEvent *>(event)){
                    cell_view = "  >: ";
                }
                else if(dynamic_cast<PositionEvent *>(event)){
                    cell_view = "  o  ";
                }
                else if(gameField.getExit().first == j && gameField.getExit().second == i){
                    cell_view = " !!! ";
                }
                else
                    cell_view = "  .  ";
            } else {
                cell_view = " [#] ";
            }

            if (cell_view == " !!! ")
                attron(COLOR_PAIR(1));
            if (cell_view == "  >: ")
                attron(COLOR_PAIR(2));
            if (cell_view == "(T-T)")
                attron(COLOR_PAIR(3));
            printw("%s", cell_view.c_str());
            if (cell_view == " !!! ")
                attroff(COLOR_PAIR(1));
            if (cell_view == "  >: ")
                attroff(COLOR_PAIR(2));
            if (cell_view == "(T-T)")
                attroff(COLOR_PAIR(3));
        }
        printw("\n");
    }
    refresh();
}

void Drawer::showStats() {
    clear();
    init_pair(8, COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(8));
    printw("\n   STATS\n   Lives: %d\n   Points: %d\n   Level: %d\n", player.getLives(), player.getPoints(), player.getLevel());
    attroff(COLOR_PAIR(8));
}