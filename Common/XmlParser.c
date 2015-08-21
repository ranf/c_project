#include "XmlParser.h"

Settings loadSettings(Settings previousSettings, char* filePath) {
	xmlDoc* doc = NULL;
	xmlNode* rootElement = NULL;
	if ((doc = xmlReadFile(filePath, NULL, XML_PARSE_RECOVER | XML_PARSE_NOERROR | XML_PARSE_NOWARNING )) == NULL ||
		(rootElement = xmlDocGetRootElement(doc)) == NULL) { //root element is <game>
		fprintf(stderr, "error: could not parse file %s\n", filePath);
		if(doc) xmlFreeDoc(doc);
		xmlCleanupParser();
		return previousSettings;
	}

	freeBoard(previousSettings.board);
	Settings settings = DEFAULT_SETTINGS;
	xmlNode* gameChild = rootElement->children;
	while (gameChild) {
		if (gameChild->type == XML_ELEMENT_NODE) {
			if (!strcmp((char*)gameChild->name, "next_turn")){
				xmlChar* content = xmlNodeGetContent(gameChild);
				settings.playingColor = parseColor((char*)content);
				if (content) xmlFree(content);
			}
			else if (!strcmp((char*)gameChild->name, "game_mode")) {
				xmlChar* content = xmlNodeGetContent(gameChild);
				settings.gameMode = *content - '0'; //should be '1' or '2'
				xmlFree(content);
			}
			else if (!strcmp((char*)gameChild->name, "difficulty")) {
				xmlChar* content = xmlNodeGetContent(gameChild);
				settings.minimaxDepth = parseDifficulty((char*)content);
				if (content) xmlFree(content);
			}
			else if (!strcmp((char*)gameChild->name, "user_color")) {
				xmlChar* content = xmlNodeGetContent(gameChild);
				settings.userColor = parseColor((char*)content);
				if (content) xmlFree(content);
			}
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
			xmlChar* content = xmlNodeGetContent(row);
			if (!strcmp((char*)row->name, "row_1"))
				readXmlBoardRow(board, content, 0);
			else if (!strcmp((char*)row->name, "row_2"))
				readXmlBoardRow(board, content, 1);
			else if (!strcmp((char*)row->name, "row_3"))
				readXmlBoardRow(board, content, 2);
			else if (!strcmp((char*)row->name, "row_4"))
				readXmlBoardRow(board, content, 3);
			else if (!strcmp((char*)row->name, "row_5"))
				readXmlBoardRow(board, content, 4);
			else if (!strcmp((char*)row->name, "row_6"))
				readXmlBoardRow(board, content, 5);
			else if (!strcmp((char*)row->name, "row_7"))
				readXmlBoardRow(board, content, 6);
			else if (!strcmp((char*)row->name, "row_8"))
				readXmlBoardRow(board, content, 7);
			if (content != NULL)
				xmlFree(content);
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
	int depth;
	if (!strcasecmp(difficultyString, "best")) {
		depth =  BEST_DEPTH;
	} else {
		depth = *difficultyString - '0';
		if (depth < 1 || depth > 4)
			depth = 1;
	}
	return depth;
}