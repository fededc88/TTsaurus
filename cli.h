#ifndef __CLI_H__
#define __CLI_H__

#include <CommandParser.h>

#define LINE_LENGTH 80 /* default line length */

typedef CommandParser<> parser;

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
