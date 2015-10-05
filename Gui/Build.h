#ifndef GUI_BUILD_H
#define GUI_BUILD_H

#include "Image.h"
#include "ElementFactory.h"
#include "../Common/Board.h"

/*pieces*/
#define WHITE_PAWN 16,76,65,65
#define WHITE_BISHOP 147,11,65,65
#define WHITE_ROOK 16,11,65,65
#define WHITE_KNIGHT 82,11,65,65
#define WHITE_QUEEN 212,11,65,65
#define WHITE_KING 277,11,65,65

#define BLACK_PAWN 16,411,65,65
#define BLACK_BISHOP 147,476,65,65
#define BLACK_ROOK 16,476,65,65
#define BLACK_KNIGHT 82,476,65,65
#define BLACK_QUEEN 212,476,65,65
#define BLACK_KING 277,476,65,65

#define EMPTY_BUTTON 82,76,65,65

#define RED_FRAME 16,141,65,65
#define SELECT_SQUER 470,91

/*panel*/
#define BLACK_WHITE_IMAGE 0,0,590,400,103,103

/*butons*/
#define BUTTON_ONE 654,584,40,50,140,240
#define BUTTON_TWO 695,584,40,50,200,240
#define BUTTON_THREE 735,584,40,50,260,240
#define BUTTON_FOUR 775,584,40,50,320,240
#define BUTTON_FIVE 910,584,40,50,380,240
#define BUTTON_SIX 735,584,40,50,440,240
#define BUTTON_SEVEN 654,584,40,50,500,240
#define P_VS_P_BUTTON 55,342,195,48,205,130
#define P_VS_C_BUTTON 55,400,195,48,205,240
#define HIGH_BUTTON_NUMBER 584
#define WHITE_COLOR_BUTTON 665,353,95,48,180,110
#define BLACK_COLOR_BUTTON 825,353,95,48,300,110
#define BEST_BUTTON 818,584,70,50,380,240
#define BEST_BUTTON_SELECT 818,640,70,50,380,240
#define NEW_GAME 765,75,160,50,200,110
#define LOAD_GAME 765,137,160,50,200,180
#define QUIT_GAME 765,205,160,50,200,250
#define MAIN_MENI_BUTTON 495,5,120,38,625,60
#define SAVE_GAME_BUTTON 495,82,120,38,625,130
#define HINT_BUTTON 495,44,120,38,625,200
#define QUIT_GAME_BUTTON 495,120,120,38,625,530
#define SET_GAME_BUTTON 495,82,120,38,625,270
#define START_GAME_BUTTON 495,44,120,38,625,340
#define SAVE_BUTTON 340,354,85,52,420,310
#define LOAD_BUTTON 446,460,85,52,420,310
#define CANCEL_BUTTON 15,470,85,52,80,310
#define START_BUTTON 185,470,85,52,420,310
#define NEXT_BUTTON 553, 470, 85, 52, 420, 310
//selected buttons
#define BUTTON_ONE_SELECT 654,640,40,50,140,240
#define BUTTON_TWO_SELECT 695,640,40,50,200,240
#define BUTTON_THREE_SELCT 735,640,40,50,260,240
#define FOUR_BUTTON_SELECT 775,640,40,50,320,240
#define FIVE_BUTTON_SELECT 910,640,40,50,380,240
#define SIX_BUTTON_SELECT 775,640,40,50,440,240
#define SEVEN_BUTTON_SELECT 654,640,40,50,500,240
#define P_VS_P_BUTTON_SELECT 267,342,195,48,205,130
#define P_VS_C_BUTTON_SELECT 267,400,195,48,205,240
#define HIGH_BUTTON_NUMBER_SELECT 640
#define WHITE_COLOR_BUTTON_SELECT 665,403,95,48,180,110
#define BLACK_COLOR_BUTTON_SELECT 825,403,95,48,300,110

/*labels*/
#define LABLE_MAIN_MENU 750,10,200,50,190,40
#define LABLE_CHOOSE_COLOR 650,290,290,45,140,40
#define LABLE_DIFFCLTY 670,512,270,45,145,180
#define LABLE_MODE_MENU 20,290,295,45,155,40
#define LABLE_PROMOTE_MENU 223,195,232,38,180,85
#define LABLE_SAVE_SLOT 5,620,345,44,125,140
#define LABLE_CHOOSE_NEW_PIECE 20,540,330,44,125,140
#define LABLE_LOAD_GAME 20,540,330,44,125,140

/* define constans*/
#define GAME_MENU_QUIT_BUTTON_HIGHT 530
#define PROMOTE_X 100
#define PROMOTE_Y 180
#define PROMOTE_OFFSET 100

gui_chess build_main_menu();
gui_chess build_mode_menu();
gui_chess build_color_set_menu();
gui_chess build_minmax_menu();
gui_chess build_settings_menu();
gui_chess build_save_menu();
gui_chess build_load_menu();
gui_chess build_game_menu();
gui_chess white_player_promots();
gui_chess black_player_promots();
gui_chess build_promotion_menu(int now_playing);
gui_chess build_set_menu();

#endif
