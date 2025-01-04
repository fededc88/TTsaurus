#ifndef __CLI_H__
#define __CLI_H__

#include <CommandParser.h>

#define LINE_LENGTH 40 /* default line length */

/**
 * All of the template arguments below are optional, but it is useful to adjust
 * them to save memory (by lowering the limits) or allow larger inputs (by
 * increasing the limits)
 * limit number of commands to at most 3
 * limit number of arguments per command to at most 2
 * limit length of command names to 10 characters
 * limit size of all arguments to 15 bytes (e.g., the argument "\x41\x42\x43" uses
 *    14 characters to represent the string but is actually only 3 bytes, 0x41,
 *    0x42, and 0x43)
 * limit size of response strings to LINE_LENGTH bytes
 */
typedef CommandParser<3, 2, 10, 15, LINE_LENGTH> parser;

class ttcli: public parser
{
    public:
        size_t line_length;

        /* Class Constructor */
        ttcli(int line_len = LINE_LENGTH)
        {
            line_length = line_len;
        }

        void begin(void);
        void menue(parser::Argument *args, char *response);
        void run(void);

    private:
        char line[LINE_LENGTH];
        char response[LINE_LENGTH];
};

#endif

// 
// End of file.
//
