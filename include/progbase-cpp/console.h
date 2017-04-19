/** @file
    @brief simple C++ wrapper for progbase/net module of libprogbase
*/
#pragma once

#include <iostream>
#include <stdexcept>

namespace pb {
    #include <progbase.h>
    #include <progbase/console.h>

    #ifdef PROGBASE_VERSION
        #if !PROGBASE_VERSION_CHECK(0, 3, 3)
            #error "Please, update your libprogbase to version >= 0.3.3"
        #endif
    #else
        #warning "Update your libprogbase to version >= 0.3.1 to enable version check"
    #endif 
}

namespace progbase {
    namespace console {
        class Console;
		struct Size;
		struct CursorPosition;

		typedef enum pb::conAttribute_e CursorAttributes;
    }
}

struct progbase::console::CursorPosition {
	unsigned short column;
	unsigned short row;

	CursorPosition(unsigned short column, unsigned short row);
};

struct progbase::console::Size {
	unsigned short columns;
	unsigned short rows;

	Size(unsigned short columns, unsigned short rows);
};

class progbase::console::Console {
public:
    static void clear(void);
	static void reset(void);
	static CursorPosition cursorPosition(void);
	static void setCursorPosition(unsigned short column, unsigned short row);
	static Size size(void);
	static void setSize(unsigned short columns, unsigned short rows);
	static void setCursorAttribute(int attributes);
	static bool isKeyDown(void);
	static char getChar(void);
	static void hideCursor(void);
	static void showCursor(void);
	static void lockInput(void);
	static void unlockInput(void);
};
