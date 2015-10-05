#include "Main.h"

int main(int argc, char* argv[]) {
	initXmlParser();
	if (argc > 1 && strcasecmp(argv[1], GUI_FLAG) == 0) {
		startGuiMode();
	} else {
		startConsoleMode();
	}

	return 0;
}
