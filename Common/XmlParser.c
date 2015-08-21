#include "XmlParser.h"

Settings loadSettings(Settings previousSettings, char* filePath) {
	xmlDoc* doc = NULL;
	xmlNode* rootElement = NULL;
	Settings settings = DEFAULT_SETTINGS;
	if ((doc = xmlReadFile(filePath, NULL, 0)) == NULL ||
		(rootElement = xmlDocGetRootElement(doc)) == NULL) { //root element is <game>
		fprintf(stderr, "error: could not parse file %s\n", filePath);
		return previousSettings;
	}

	xmlNode* gameChild = rootElement->children;
	while (gameChild) {
		if (gameChild->type == XML_ELEMENT_NODE) {
			if (!strcmp((char*)gameChild->name, "next_turn"))
				settings.playingColor = parseColor((char*)gameChild->content);
			else if (!strcmp((char*)gameChild->name, "game_mode"))
				settings.gameMode = (*gameChild->content) - '0'; //should be '1' or '2'
			else if (!strcmp((char*)gameChild->name, "difficulty"))
				settings.minimaxDepth = parseDifficulty((char*)gameChild->content);
			else if (!strcmp((char*)gameChild->name, "user_color"))
				settings.userColor = parseColor((char*)gameChild->content);
			else if (!strcmp((char*)gameChild->name, "board"))
				settings.board = parseXmlBoard(settings.board, gameChild->children);
		}
		gameChild = gameChild->next;
	}

	xmlFreeDoc(doc);
	xmlCleanupParser();

	return settings;
}

char** parseXmlBoard(char** board, xmlNode* row) {
	while (row) {
		if (row->type == XML_ELEMENT_NODE) {
			if (!strcmp((char*)row->name, "row_1"))
				readXmlBoardRow(board[0], row->content);
			else if (!strcmp((char*)row->name, "row_2"))
				readXmlBoardRow(board[1], row->content);
			else if (!strcmp((char*)row->name, "row_3"))
				readXmlBoardRow(board[2], row->content);
			else if (!strcmp((char*)row->name, "row_4"))
				readXmlBoardRow(board[3], row->content);
			else if (!strcmp((char*)row->name, "row_5"))
				readXmlBoardRow(board[4], row->content);
			else if (!strcmp((char*)row->name, "row_6"))
				readXmlBoardRow(board[5], row->content);
			else if (!strcmp((char*)row->name, "row_7"))
				readXmlBoardRow(board[6], row->content);
			else if (!strcmp((char*)row->name, "row_8"))
				readXmlBoardRow(board[7], row->content);
		}
		row = row->next;
	}
	return board;
}

void readXmlBoardRow(char* boardRow, xmlChar* xmlRow) {
	if (xmlRow == NULL || xmlStrlen(xmlRow) < BOARD_SIZE)
		return;
	for (int i = 0; i < BOARD_SIZE; i++) {
		boardRow[i] = (char)xmlRow[i] == EMPTY ? EMPTY : (char)xmlRow[i];
	}
}

int parseColor(char* colorString) {
	return !strcasecmp(colorString, "black") ? BLACK_COLOR : WHITE_COLOR;
}

int parseDifficulty(char* difficultyString) {
	if(!strcasecmp(difficultyString, "best"))
		return BEST_DEPTH;
	int depth = *difficultyString - '0';
	if (depth < 1 || depth > 4)
		return 1;
	return depth;
}