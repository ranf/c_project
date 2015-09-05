#include "ElementFactory.h"

/*control factories*/
gui_chess window_factory(SDL_Surface* win_img)
{
	gui_chess result;
	result = (gui_chess)malloc(sizeof(game_frame));
	if (result == NULL){
		printf("ERROR: problem with window");
		exit(0);
		//break;
	}
	result->type = WINDOW;
	result->img = win_img;
	result->child = NULL;
	result->next = NULL;
	result->parent = NULL;
	return (result);
}

gui_chess panel_factory(SDL_Surface* pnl_img, int sheet_x_offset, int sheet_y_offset, int sheet_width, int sheet_height, int dest_x, int dest_y, gui_chess parent)
{
	gui_chess result;
	result = (gui_chess)malloc(sizeof(game_frame));
	if (result == NULL){
		perror("ERROR");
		exit(0);
		//break;
	}
	result->img = pnl_img;
	result->child = NULL;
	result->next = NULL;
	result->parent = parent;
	result->type = PANEL;
	result->clip.x = sheet_x_offset;
	result->clip.y = sheet_y_offset;
	result->clip.h = sheet_height;
	result->clip.w = sheet_width;
	result->box.x = dest_x;
	result->box.y = dest_y;
	return (result);
}

gui_chess label_factory(SDL_Surface* lbl_img, int sheet_x_offset, int sheet_y_offset, int sheet_width, int sheet_height, int dest_x, int dest_y, gui_chess parent)
{
	gui_chess result;
	result = (gui_chess)malloc(sizeof(game_frame));
	if (result == NULL){
		perror("ERROR");
		exit(0);
		//break;
	}
	result->img = lbl_img;
	result->child = NULL;
	result->next = NULL;
	result->parent = parent;
	result->type = LABEL;
	result->clip.x = sheet_x_offset;
	result->clip.y = sheet_y_offset;
	result->clip.h = sheet_height;
	result->clip.w = sheet_width;
	result->box.x = dest_x;
	result->box.y = dest_y;
	return (result);
}

gui_chess button_factory(SDL_Surface* btn_img, int sheet_x_offset, int sheet_y_offset, int sheet_width, int sheet_height, int dest_x, int dest_y, gui_chess parent)
{
	gui_chess result;
	result = (gui_chess)malloc(sizeof(game_frame));
	if (result == NULL){
		perror("ERROR");
		exit(0);
		//break
	}
	result->img = btn_img;
	result->child = NULL;
	result->next = NULL;
	result->parent = parent;
	result->type = BUTTON;
	result->clip.x = sheet_x_offset;
	result->clip.y = sheet_y_offset;
	result->clip.h = sheet_height;
	result->clip.w = sheet_width;
	result->box.x = dest_x;
	result->box.y = dest_y;
	return (result);
}