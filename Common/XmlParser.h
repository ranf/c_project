#ifndef COMMON_XMLPARSER_H
#define COMMON_XMLPARSER_H

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlwriter.h>
#include "Settings.h"

#define WRONG_FILE_NAME "Wrong file name\n"

Settings loadSettings(Settings previousSettings, char* filePath);
void saveSettings(Settings settings, char* filename);

char** parseXmlBoard(char** board, xmlNode* row);
void readXmlBoardRow(char** board, xmlChar* xmlRow, int rowIndex);
int parseColor(char* colorString);
int parseDifficulty(char* difficultyString);
void boardRowToString(char** board, int rowIndex, char rowString[9]);
char* colorToString(int color);
char* difficultyToString(int difficulty);

#endif