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
				settings.playingColor = parseColor((char*)xmlNodeGetContent(gameChild));
			else if (!strcmp((char*)gameChild->name, "game_mode"))
				settings.gameMode = *xmlNodeGetContent(gameChild) - '0'; //should be '1' or '2'
			else if (!strcmp((char*)gameChild->name, "difficulty"))
				settings.minimaxDepth = parseDifficulty((char*)xmlNodeGetContent(gameChild));
			else if (!strcmp((char*)gameChild->name, "user_color"))
				settings.userColor = parseColor((char*)xmlNodeGetContent(gameChild));
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
				readXmlBoardRow(board, xmlNodeGetContent(row), 0);
			else if (!strcmp((char*)row->name, "row_2"))
				readXmlBoardRow(board, xmlNodeGetContent(row), 1);
			else if (!strcmp((char*)row->name, "row_3"))
				readXmlBoardRow(board, xmlNodeGetContent(row), 2);
			else if (!strcmp((char*)row->name, "row_4"))
				readXmlBoardRow(board, xmlNodeGetContent(row), 3);
			else if (!strcmp((char*)row->name, "row_5"))
				readXmlBoardRow(board, xmlNodeGetContent(row), 4);
			else if (!strcmp((char*)row->name, "row_6"))
				readXmlBoardRow(board, xmlNodeGetContent(row), 5);
			else if (!strcmp((char*)row->name, "row_7"))
				readXmlBoardRow(board, xmlNodeGetContent(row), 6);
			else if (!strcmp((char*)row->name, "row_8"))
				readXmlBoardRow(board, xmlNodeGetContent(row), 7);
		}
		row = row->next;
	}
	return board;
}

void readXmlBoardRow(char** board, xmlChar* xmlRow, int rowIndex) {
	if (xmlRow == NULL || xmlStrlen(xmlRow) < BOARD_SIZE)
		return;
	for (int i = 0; i < BOARD_SIZE; i++) {
		board[i][rowIndex] = (char)xmlRow[i] == '_' ? EMPTY : (char)xmlRow[i];
	}
}

int parseColor(char* colorString) {
	return (!colorString || !strcasecmp(colorString, "white"))
		? WHITE_COLOR
		: BLACK_COLOR;;
}

int parseDifficulty(char* difficultyString) {
	if (difficultyString == NULL)
		return 1;
	if (!strcasecmp(difficultyString, "best"))
		return BEST_DEPTH;
	int depth = *difficultyString - '0';
	if (depth < 1 || depth > 4)
		return 1;
	return depth;
}