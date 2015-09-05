#ifndef GUI_BUILD_H
#define GUI_BUILD_H

#include "Gui.h"

/*check & mate labels parameters*/
#define CHECKMATE_LABEL 119,117,325,49,170,150
#define CHECK_LABEL 379,26,133,38,250,260
#define WHITE_MATE_IMG 262,193,240,200,210,250
#define BLACK_MATE_IMG 3,196,230,200,210,250

/*black pieces parameters*/
#define B_PAWN_PMT 16,76,65,65
#define B_BISHOP_PMT 147,11,65,65
#define B_ROOK_PMT 16,11,65,65
#define B_KNIGHT_PMT 82,11,65,65
#define B_QUEEN_PMT 212,11,65,65
#define B_KING_PMT 277,11,65,65

/*white pieces parameters*/
#define W_PAWN_PMT 16,411,65,65
#define W_BISHOP_PMT 147,476,65,65
#define W_ROOK_PMT 16,476,65,65
#define W_KNIGHT_PMT 82,476,65,65
#define W_QUEEN_PMT 212,476,65,65
#define W_KING_PMT 277,476,65,65

/*board parameters*/

#define GET_MOVES_SELECT_SQURE 470,91

/*fish panel parameters*/
#define FISH_PANEL_PMT 0,0,590,400,103,103
#define CANCEL_BUTTON_PMT 15,470,85,52,80,310
#define START_BUTTON_PMT 185,470,85,52,420,310
#define NEXT_BUTTON_PMT 553, 470, 85, 52, 420, 310

/*number buttons parameters*/
#define ONE_BUTTON_PMT 654,584,40,50,140,240
#define TWO_BUTTON_PMT 695,584,40,50,200,240
#define THREE_BUTTON_PMT 735,584,40,50,260,240
#define FOUR_BUTTON_PMT 775,584,40,50,320,240
#define FIVE_BUTTON_PMT 910,584,40,50,380,240
#define ONE_S_BUTTON_PMT 654,640,40,50,140,240
#define TWO_S_BUTTON_PMT 695,640,40,50,200,240
#define THREE_S_BUTTON_PMT 735,640,40,50,260,240
#define FOUR_S_BUTTON_PMT 775,640,40,50,320,240
#define FIVE_S_BUTTON_PMT 910,640,40,50,380,240
#define NUM_BUTTON_Y 584
#define NUM_S_BUTTON_Y 640
#define NUM_HORIZONTAL_OFFSET 60

/*main menu parameters*/
#define MAIN_LABEL_PMT 750,10,200,50,190,40
#define NEW_BUTTON_PMT 765,75,160,50,200,110
#define LOAD_BUTTON_PMT 765,137,160,50,200,180
#define QUIT_BUTTON_PMT 765,205,160,50,200,250
#define MAIN_VERTICAL_OFFSET 70

/*mode menu parameters*/
#define MODE_LABEL_PMT 20,290,295,45,155,40
#define PVP_BUTTON_PMT 55,342,195,48,205,130
#define PVC_BUTTON_PMT 55,400,195,48,205,240
#define PVP_S_BUTTON_PMT 267,342,195,48,205,130
#define PVC_S_BUTTON_PMT 267,400,195,48,205,240
#define PV_BUTTON_X 55
#define PV_S_BUTTON_X 267
#define NEXT_ARROW_X 553
#define START_ARROW_X 185

/*settinges menu parameters*/
#define COLOR_LABEL_PMT 650,290,290,45,140,40
#define WHITE_BUTTON_PMT 665,353,95,48,180,110
#define BLACK_BUTTON_PMT 825,353,95,48,300,110
#define WHITE_S_BUTTON_PMT 665,403,95,48,180,110
#define BLACK_S_BUTTON_PMT 825,403,95,48,300,110
#define COLOR_BUTTON_Y 353
#define COLOR_S_BUTTON_Y 403
#define DIFFICULTY_LABEL_PMT 670,512,270,45,145,180
#define BEST_BUTTON_PMT 818,584,70,50,380,240
#define BEST_S_BUTTON_PMT 818,640,70,50,380,240

/*game menu parameters*/
#define MENU_BUTTON_PMT 495,5,120,38,625,60
#define SAVE_BUTTON_PMT 495,82,120,38,625,130
#define RESTART_BUTTON_PMT 495,44,120,38,625,200
#define POSSIBLE_MOVES_ALLOWED 495,220,120,54,625,420
#define POSSIBLE_MOVES_NOT_ALLOWED 495,161,120,54,625,450
#define POSSIBLE_MOVES_Y 450
#define POSSIBLE_MOVES_ALLOWED_Y 220
#define POSSIBLE_MOVES_NOT_ALLOWED_Y 161
#define QUIT_SIDE_BUTTON_PMT 495,120,120,38,625,530
#define QUIT_SIDE_Y 530
#define KINGS_IMG 25,203,127,145,625,283

/*promotion parameters*/
#define PROMOTE_LABEL 223,195,232,38,180,85
#define PROMOTE_FIRST_POS_X 100
#define PROMOTE_FIRST_POS_Y 180
#define PROMOTE_OFFSET 100

/*save and load buttons and labels*/
#define SAVE_LABEL_PMT 5,620,345,44,125,140
#define SAVE_ARROW_PMT 340,460,85,52,420,310
#define LOAD_LABEL_PMT 20,540,330,44,125,140
#define LOAD_ARROW_PMT 446,460,85,52,420,310
#define LOAD_FAILED_LABEL_PMT 336,370,202,66,300,340
#define SAVE_FAILED_LABEL_PMT 168,249,250,83,300,340
#define SAVE_SUCCEED_LABEL_PMT 104,366,196,111,300,340

/*files for saving*/
#define MEM_SLOT_1 "mem_slot_1.xml"
#define MEM_SLOT_2 "mem_slot_2.xml"
#define MEM_SLOT_3 "mem_slot_3.xml"
#define MEM_SLOT_4 "mem_slot_4.xml"
#define MEM_SLOT_5 "mem_slot_5.xml"

/*type of conrolers*/
#define WINDOW 1
#define PANEL 2
#define LABEL 3
#define BUTTON 4

/*menus numbering*/
#define QUIT 0
#define MAIN_MENU 1
#define LOAD_MENU 2
#define MODE_MENU 3
#define SETTINGS_MENU 4
#define GAME_MENU 5

/*images paths*/
#define MAIN_IMG "Images/main_img.bmp"
#define PANELS_SHEET "Images/panels sheet.bmp"
#define SETTINGS_SHEET "Images/settings sheet.bmp"
#define PIECES_SHEET "Images/pieces sheet.bmp"
#define SELECTED_PIECES_SHEET "Images/selected pieces sheet.bmp"
#define BACKROUND_IMAGE "Images/back.bmp"


SDL_Surface *load_link_image(char *path);


#include "ElementFactory.h"

#endif