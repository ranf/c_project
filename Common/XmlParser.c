#include "XmlParser.h"

Settings loadSettings(Settings previousSettings, char* filePath) {
	xmlDoc* doc = NULL;
	xmlNode* rootElement = NULL;
	if ((doc = xmlReadFile(filePath, NULL, XML_PARSE_RECOVER | XML_PARSE_NOERROR | XML_PARSE_NOWARNING )) == NULL ||
		(rootElement = xmlDocGetRootElement(doc)) == NULL) { //root element is <game>
		printMessage(WRONG_FILE_NAME);
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

// TODO return sucess value
void saveSettings(Settings settings, char* filename) {
	xmlTextWriterPtr writer = xmlNewTextWriterFilename(filename, 0);
	if (writer == NULL) {
		printMessage(WRONG_FILE_NAME);
		return;
	}
	writeSettingsToXml(settings, writer);

	xmlFreeTextWriter(writer);
	xmlCleanupCharEncodingHandlers();
}

void writeSettingsToXml(Settings settings, xmlTextWriterPtr writer) {
	int bytesWritten;
	bytesWritten = xmlTextWriterStartDocument(writer, NULL, "UTF-8", NULL);
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterStartDocument");
		return;
	}

	bytesWritten = xmlTextWriterStartElement(writer, BAD_CAST "game");
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterStartElement");
		return;
	}
	//<game> is root element. now writing inside it.

	bytesWritten = xmlTextWriterWriteFormatElement(writer, BAD_CAST "next_turn",
		"%s", colorToString(settings.playingColor));
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterWriteFormatElement");
		return;
	}
	bytesWritten = xmlTextWriterWriteFormatElement(writer, BAD_CAST "game_mode",
		"%d", settings.gameMode);
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterWriteFormatElement");
		return;
	}
	bytesWritten = xmlTextWriterWriteFormatElement(writer, BAD_CAST "difficulty", "%s",
		settings.gameMode != SINGLEPLAYER_MODE ? "" : difficultyToString(settings.minimaxDepth));
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterWriteFormatElement");
		return;
	}
	bytesWritten = xmlTextWriterWriteFormatElement(writer, BAD_CAST "user_color", "%s",
		settings.gameMode != SINGLEPLAYER_MODE ? "" : colorToString(settings.userColor));
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterWriteFormatElement");
		return;
	}

	bytesWritten = xmlTextWriterStartElement(writer, BAD_CAST "board");
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterStartElement");
		return;
	}
	char rowString[9];
	boardRowToString(settings.board, 7, rowString);
	bytesWritten = xmlTextWriterWriteFormatElement(writer, BAD_CAST "row_8",
		"%s", rowString);
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterWriteFormatElement");
		return;
	}
	boardRowToString(settings.board, 6, rowString);
	bytesWritten = xmlTextWriterWriteFormatElement(writer, BAD_CAST "row_7",
		"%s", rowString);
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterWriteFormatElement");
		return;
	}
	boardRowToString(settings.board, 5, rowString);
	bytesWritten = xmlTextWriterWriteFormatElement(writer, BAD_CAST "row_6",
		"%s", rowString);
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterWriteFormatElement");
		return;
	}
	boardRowToString(settings.board, 4, rowString);
	bytesWritten = xmlTextWriterWriteFormatElement(writer, BAD_CAST "row_5",
		"%s", rowString);
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterWriteFormatElement");
		return;
	}
	boardRowToString(settings.board, 3, rowString);
	bytesWritten = xmlTextWriterWriteFormatElement(writer, BAD_CAST "row_4",
		"%s", rowString);
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterWriteFormatElement");
		return;
	}
	boardRowToString(settings.board, 2, rowString);
	bytesWritten = xmlTextWriterWriteFormatElement(writer, BAD_CAST "row_3",
		"%s", rowString);
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterWriteFormatElement");
		return;
	}
	boardRowToString(settings.board, 1, rowString);
	bytesWritten = xmlTextWriterWriteFormatElement(writer, BAD_CAST "row_2",
		"%s", rowString);
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterWriteFormatElement");
		return;
	}
	boardRowToString(settings.board, 0, rowString);
	bytesWritten = xmlTextWriterWriteFormatElement(writer, BAD_CAST "row_1",
		"%s", rowString);
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterWriteFormatElement");
		return;
	}
	bytesWritten = xmlTextWriterEndElement(writer); //</board>
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterEndElement");
		return;
	}

	bytesWritten = xmlTextWriterEndDocument(writer); //</game> - closes any unclosed element
	if (bytesWritten < 0) {
		printErrorMessage("xmlTextWriterEndElement");
		return;
	}
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

void boardRowToString(char** board, int rowIndex, char rowString[9]) {
	char piece;
	for (int i = 0; i < BOARD_SIZE; i++) {
		piece = board[i][rowIndex];
		rowString[i] = piece == EMPTY ? '_' : piece;
	}
	rowString[BOARD_SIZE] = '\0';
}

int parseColor(char* colorString) {
	return (!colorString || !strcasecmp(colorString, "white"))
		? WHITE_COLOR
		: BLACK_COLOR;;
}

char* colorToString(int color) {
	return color == BLACK_COLOR ? "Black" : "White";
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

char* difficultyToString(int difficulty) {
	switch (difficulty) {
		case BEST_DEPTH:
			return "best";
		case 1:
			return "1";
		case 2:
			return "2";
		case 3:
			return "3";
		case 4:
			return "4";
		default:
			return "1";
	}
}
