#include <progbase-cpp/console.h>

using namespace progbase::console;

CursorPosition::CursorPosition(unsigned short column, unsigned short row) {
	this->column = column;
	this->row = row;
} 

Size::Size(unsigned short columns, unsigned short rows) {
	this->columns = columns;
	this->rows = rows;
} 

void Console::clear(void) {
	pb::Console_clear();
}

void Console::reset(void) {
	pb::Console_reset();
}

CursorPosition Console::cursorPosition(void) {
	pb::ConsoleCursorPosition pos = pb::Console_cursorPosition();
	return CursorPosition(pos.column, pos.row);
}

void Console::setCursorPosition(unsigned short column, unsigned short row) {
	pb::Console_setCursorPosition(column, row);
}

Size Console::size(void) {
	pb::ConsoleSize size = pb::Console_size();
	return Size(size.columns, size.rows);
}

void Console::setSize(unsigned short columns, unsigned short rows) {
	pb::Console_setSize(columns, rows);
}

void Console::setCursorAttribute(int attributes) {
	pb::Console_setCursorAttributes(attributes);
}

bool Console::isKeyDown(void) {
	return pb::Console_isKeyDown();
}

char Console::getChar(void) {
	return pb::Console_getChar();
}

void Console::hideCursor(void) {
	pb::Console_hideCursor();
}

void Console::showCursor(void) {
	pb::Console_showCursor();
}

void Console::lockInput(void) {
	pb::Console_lockInput();
}

void Console::unlockInput(void) {
	pb::Console_unlockInput();
}
