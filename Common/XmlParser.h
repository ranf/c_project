#ifndef COMMON_XMLPARSER_H
#define COMMON_XMLPARSER_H

#include <libxml/parser.h>
#include <libxml/tree.h>
#include "Settings.h"

Settings loadSettings(Settings previousSettings, char* filePath);

char** parseXmlBoard(char** board, xmlNode* row);
void readXmlBoardRow(char** board, xmlChar* xmlRow, int rowIndex);
int parseColor(char* colorString);
int parseDifficulty(char* difficultyString);

#endif